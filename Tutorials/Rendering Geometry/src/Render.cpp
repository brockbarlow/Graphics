#include "Render.h"

RenderingGeometry::RenderingGeometry()
{
	
}
 
void RenderingGeometry::generatePlane()
{
	Vertex vertices[4];
	//unsigned int indices[4] = { 0,1,2,3 };
	unsigned int indices[6] = { 2, 1, 0, 2, 3, 1 };

	vertices[0].position = glm::vec4(-5, 0, -5, 1);
	vertices[1].position = glm::vec4(5, 0, -5, 1);
	vertices[2].position = glm::vec4(-5, 0, 5, 1);
	vertices[3].position = glm::vec4(5, 0, 5, 1);

	vertices[0].color = glm::vec4(1, 0, 0, 1);
	vertices[1].color = glm::vec4(0, 1, 0, 1);
	vertices[2].color = glm::vec4(0, 0, 1, 1);
	vertices[3].color = glm::vec4(1, 1, 1, 1);
}

void RenderingGeometry::generateCube()
{

}

void RenderingGeometry::generateSphere()
{

}

bool RenderingGeometry::start()
{
	if (glfwInit() == false)
	{
		return false;
	}

	window = glfwCreateWindow(1280, 720, "Computer Graphics", nullptr, nullptr);

	if (window == nullptr)
	{
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(window);

	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		return false;
	}

	
	view = glm::lookAt(glm::vec3(8, 8, 8), glm::vec3(0), glm::vec3(0, 1, 0));
	projection = glm::perspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.f);

	auto major = ogl_GetMajorVersion();
	auto minor = ogl_GetMinorVersion();
	printf("GL: %i.%i\n", major, minor);

	glClearColor(0.25f, 0.25f, 0.25f, 1);
	glEnable(GL_DEPTH_TEST); //enables the depth buffer
	// create vertex and index data for a quad
	
	//generate the vertex buffer
	glGenBuffers(1, &m_VBO);
	//generate the index buffer
	glGenBuffers(1, &m_IBO);
	//generate the vertex descriptor
	glGenVertexArrays(1, &m_VAO);
	//bind the vertex descriptor
	glBindVertexArray(m_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(glm::vec4)));




	glBindVertexArray(0); //unbind the vao
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		// create shader
	const char* vsSource = "#version 410\n \
							layout(location=0) in vec4 Position; \
							layout(location=1) in vec4 Colour; \
							out vec4 vColour; \
							uniform mat4 ProjectionViewWorld; \
							void main() { vColour = Colour; \
							gl_Position = ProjectionViewWorld * Position; }";

	const char* fsSource = "#version 410\n \
							in vec4 vColour; \
							out vec4 FragColor; \
							void main() { FragColor = vColour; }";


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
	// clear the screen for this frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(m_programID);
	unsigned int projectionViewUniform = glGetUniformLocation(m_programID, "projectionViewWorldMatrix");

	m_projectionViewMatrix = projection * view;
	glUniformMatrix4fv(projectionViewUniform, 1, false,	glm::value_ptr(m_projectionViewMatrix));
	
	glBindVertexArray(m_VAO);
	
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void RenderingGeometry::destroy()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}