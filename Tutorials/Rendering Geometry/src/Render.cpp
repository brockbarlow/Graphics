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

	myCamera.setLookAt(glm::vec3(15, 15, 15), glm::vec3(0), glm::vec3(0, 1, 0));
	myCamera.setPerspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.f);
	myCamera.setSpeed(10);

	glClearColor(0.25f, 0.25f, 0.25f, 1);
	glEnable(GL_DEPTH_TEST);
}

bool RenderingGeometry::start()
{
	createPlane();  
	createCube();   
	createSphere(2, 30, 30);   

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
	
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return true;
}

bool RenderingGeometry::update()
{
	current = (float)glfwGetTime();
	delta = current - previous;
	previous = current;

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
	glUniformMatrix4fv(projectionViewUniform, 1, false, &(myCamera.getProjectionView()[0][0]));

	drawPlane();
	drawCube();
	drawSphere();

	myCamera.update(delta, window);

	glfwSwapBuffers(window);
	glfwPollEvents();
}

void RenderingGeometry::destroy()
{
	glfwDestroyWindow(window);
	glfwTerminate();
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

	p_indicesCounter = 4;

	vertices[0].position = glm::vec4(-5, -5, -5, 1);
	vertices[1].position = glm::vec4(5, -5, -5, 1);
	vertices[2].position = glm::vec4(-5, -5, 5, 1);
	vertices[3].position = glm::vec4(5, -5, 5, 1);

	vertices[0].color = glm::vec4(1, 0, 0, 1);
	vertices[1].color = glm::vec4(0, 1, 0, 1);
	vertices[2].color = glm::vec4(0, 0, 1, 1);
	vertices[3].color = glm::vec4(1, 1, 1, 1);

	glGenBuffers(1, &p_VBO);
	glGenBuffers(1, &p_IBO);
	glGenVertexArrays(1, &p_VAO);
	glBindVertexArray(p_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, p_VBO);
	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, p_IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(glm::vec4)));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void RenderingGeometry::drawPlane()
{
	glBindVertexArray(p_VAO);
	glDrawElements(GL_TRIANGLE_STRIP, p_indicesCounter, GL_UNSIGNED_INT, 0);
}

void RenderingGeometry::createCube()
{
	Vertex vertices[8];
	unsigned int indices[17] = { 0,1,2,3,6,7,4,5,0,1,5,3,7,6,4,2,0 };

	c_indicesCounter = 17;

	vertices[0].position = glm::vec4(-2, 4, -2, 1);
	vertices[1].position = glm::vec4(2, 4, -2, 1);
	vertices[2].position = glm::vec4(-2, 4, 2, 1);
	vertices[3].position = glm::vec4(2, 4, 2, 1);
	vertices[4].position = glm::vec4(-2, 6, -2, 1);
	vertices[5].position = glm::vec4(2, 6, -2, 1);
	vertices[6].position = glm::vec4(-2, 6, 2, 1);
	vertices[7].position = glm::vec4(2, 6, 2, 1);

	vertices[0].color = glm::vec4(1, 0, 0, 1);
	vertices[1].color = glm::vec4(0, 1, 0, 1);
	vertices[2].color = glm::vec4(0, 0, 1, 1);
	vertices[3].color = glm::vec4(1, 1, 1, 1);
	vertices[4].color = glm::vec4(1, 0, 0, 1);
	vertices[5].color = glm::vec4(0, 1, 0, 1);
	vertices[6].color = glm::vec4(0, 0, 1, 1);
	vertices[7].color = glm::vec4(1, 1, 1, 1);

	glGenBuffers(1, &c_VBO);
	glGenBuffers(1, &c_IBO);
	glGenVertexArrays(1, &c_VAO);
	glBindVertexArray(c_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, c_VBO);
	glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(Vertex), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, c_IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 17 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(glm::vec4)));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void RenderingGeometry::drawCube()
{
	glBindVertexArray(c_VAO);
	glDrawElements(GL_TRIANGLE_STRIP, c_indicesCounter, GL_UNSIGNED_INT, 0);
}

Vertex* RenderingGeometry::generateHalfSphereVertices(unsigned int np, const int &rad)
{
	Vertex* vertices = new Vertex[np];

	for (int i = 0; i < np; i++)
	{
		float angle = pi * i / (np - 1);
		vertices[i].position = glm::vec4(rad * cos(angle), rad * sin(angle), 0, 1);
	}
	return vertices;
}

Vertex* RenderingGeometry::generateSphereVertices(const unsigned int &sides, const unsigned int &mirid, Vertex* &halfSphere)
{
	int count = 0;
	Vertex* vertices = new Vertex[sides * mirid];

	for (int i = 0; i < mirid; i++)
	{
		float phi = 2.f * pi * ((float)i / (float)(mirid));
		for (int j = 0; j < sides; j++, count++)
		{
			float x = halfSphere[j].position.x;
			float y = halfSphere[j].position.y * cos(phi) - halfSphere[j].position.z * sin(phi);
			float z = halfSphere[j].position.z * cos(phi) + halfSphere[j].position.y * sin(phi);
			
			vertices[count].position = glm::vec4(x, y, z, 1);
			vertices[count].color = glm::vec4(1, 0, 0, 1);
		}
	}
	return vertices;
}

unsigned int* RenderingGeometry::generateSphereIndicies(const unsigned int &vertices, const unsigned int &mirid)
{
	unsigned int* indices = new unsigned int[2 * (vertices * (mirid + 1))];
	s_indicesCounter = 2 * (vertices * (mirid + 1));

	for (unsigned int i = 0; i < mirid; i++)	
	{
		unsigned int beginning = i * vertices;
		for (int j = 0; j < vertices; j++)
		{
			unsigned int botR = ((beginning + vertices + j) % (vertices * mirid));
			unsigned int botL = ((beginning + j) % (vertices * mirid));
			indicesHolder.push_back(botL);
			indicesHolder.push_back(botR);
		}
		indicesHolder.push_back(0xFFFF);
	}

	for (int i = 0; i < indicesHolder.size(); i++) {
		indices[i] = indicesHolder[i];
	}
	return indices;
}

void RenderingGeometry::createSphere(const int radius, const unsigned int verts, const unsigned int halfSpheres)
{
	const unsigned int size = (verts) * (halfSpheres);

	Vertex* vertices = new Vertex[size];
	unsigned int* indices;

	Vertex* halfSpheresVerts = generateHalfSphereVertices(verts, radius);		
	vertices = generateSphereVertices(verts, halfSpheres, halfSpheresVerts);
	indices = generateSphereIndicies(verts, halfSpheres);

	glGenBuffers(1, &s_VBO);
	glGenBuffers(1, &s_IBO);
	glGenVertexArrays(1, &s_VAO);
	glBindVertexArray(s_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, s_VBO);
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(Vertex), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, s_IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (s_indicesCounter * sizeof(unsigned int)), indices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);	
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glEnableVertexAttribArray(1);	
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void RenderingGeometry::drawSphere()
{
	glBindVertexArray(s_VAO);
	glDrawElements(GL_TRIANGLE_STRIP, s_indicesCounter, GL_UNSIGNED_INT, 0);
}