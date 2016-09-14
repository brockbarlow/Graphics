#include "Render.h"

RenderingGeometry::RenderingGeometry()
{
	glfwInit();

	window = glfwCreateWindow(1280, 720, "Rendering Geometry", nullptr, nullptr);

	if (window == nullptr)
	{
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);

	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	view = glm::lookAt(glm::vec3(10, 10, 10), glm::vec3(0), glm::vec3(0, 1, 0));
	projection = glm::perspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.f);

	glClearColor(0.25f, 0.25f, 0.25f, 1);
	glEnable(GL_DEPTH_TEST);
}

bool RenderingGeometry::start()
{
	//createPlane();  //creates the plane.
	//createCube();   //creates a cube.
	createSphere(); //creates a sphere.

	const char* vsSource;						
	std::string vs = ReadFromFile("vsInfo.txt");	
	vsSource = vs.c_str();						

	const char* fsSource;	
	std::string fs = ReadFromFile("fsInfo.txt");
	fsSource = fs.c_str();

	int success = GL_FALSE;
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexShader, 1, (const char**)&vsSource, 0);
	glCompileShader(vertexShader);
	glShaderSource(fragmentShader, 1, (const char**)&fsSource, 0);
	glCompileShader(fragmentShader);

	m_programID = glCreateProgram();
	glAttachShader(m_programID, vertexShader);
	glAttachShader(m_programID, fragmentShader);
	glLinkProgram(m_programID);

	glGetProgramiv(m_programID, GL_LINK_STATUS, &success);
	if (success == GL_FALSE)
	{
		int infoLogLength = 0;
		glGetProgramiv(m_programID, GL_INFO_LOG_LENGTH, &infoLogLength);
		char* infoLog = new char[infoLogLength];
		glGetProgramInfoLog(m_programID, infoLogLength, 0, infoLog);
		printf("Error: Failed to link shader program!\n");
		printf("%s\n", infoLog);
		delete[] infoLog;
	}
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);
	
	return true;
}

std::string RenderingGeometry::ReadFromFile(std::string text)
{
	std::string data;
	std::string container;
	std::ifstream file(text);

	if (file.is_open())
	{
		while (std::getline(file, data))
		{
			container += data + "\n";
		}
		file.close();
	}
	return container;
}

void RenderingGeometry::createPlane()
{
	Vertex vertices[4];
	unsigned int indices[4] = { 0,1,2,3 };

	indicesCounter = 4;

	vertices[0].position = glm::vec4(-5, 0, -5, 1);
	vertices[1].position = glm::vec4(5, 0, -5, 1);
	vertices[2].position = glm::vec4(-5, 0, 5, 1);
	vertices[3].position = glm::vec4(5, 0, 5, 1);

	vertices[0].color = glm::vec4(1, 0, 0, 1);
	vertices[1].color = glm::vec4(0, 1, 0, 1);
	vertices[2].color = glm::vec4(0, 0, 1, 1);
	vertices[3].color = glm::vec4(1, 1, 1, 1);

	glGenBuffers(1, &m_VBO);
	glGenBuffers(1, &m_IBO);
	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(glm::vec4)));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void RenderingGeometry::createCube()
{
	Vertex vertices[4];
	unsigned int indices[4] = { 0,1,2,3 };

	indicesCounter = 4;

	vertices[0].position = glm::vec4(-2, 0, -2, 1);
	vertices[1].position = glm::vec4(2, 0, -2, 1);
	vertices[2].position = glm::vec4(-2, 0, 2, 1);
	vertices[3].position = glm::vec4(2, 0, 2, 1);

	vertices[0].color = glm::vec4(1, 0, 0, 1);
	vertices[1].color = glm::vec4(0, 1, 0, 1);
	vertices[2].color = glm::vec4(0, 0, 1, 1);
	vertices[3].color = glm::vec4(1, 1, 1, 1);

	glGenBuffers(1, &m_VBO);
	glGenBuffers(1, &m_IBO);
	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(glm::vec4)));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

Vertex* RenderingGeometry::generateHalfSphereVertices(unsigned int np, const int &rad)
{
	Vertex* vertices = new Vertex[np];

	for (int i = 0; i < np; i++)
	{
		angle = pi * (i / (np - 1));
		vertices[i].position = glm::vec4(rad * sin(angle), rad * cos(angle), 0, 1);
	}
	return vertices;
}

Vertex* RenderingGeometry::generateSphereVertices(const unsigned int &sides, const unsigned int &mirid, Vertex* &halfSphere)
{
	int count = 0;
	Vertex* vertices = new Vertex[sides * mirid];

	for (int i = 0; i < mirid; i++)
	{
		float phi = 2 * (pi * ((float)i / (float)(mirid)));
		for (int j = 0; j < sides; j++, count++)
		{
			float x;
			float y;
			float z;
		}
	}
}

void RenderingGeometry::createSphere()
{
	
}

bool RenderingGeometry::update()
{
	while (glfwWindowShouldClose(window) == false && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		return true;
	}
	return false;
}

void RenderingGeometry::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(m_programID);
	unsigned int projectionViewUniform = glGetUniformLocation(m_programID, "projectionViewWorldMatrix");
	m_projectionViewMatrix = projection * view;
	glUniformMatrix4fv(projectionViewUniform, 1, false,	glm::value_ptr(m_projectionViewMatrix));
	glBindVertexArray(m_VAO);
	glDrawElements(GL_TRIANGLE_STRIP, indicesCounter, GL_UNSIGNED_INT, 0);
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void RenderingGeometry::destroy()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}