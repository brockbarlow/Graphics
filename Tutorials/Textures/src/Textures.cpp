#include <stb_image.h>
#include "App.h"

Textures::Textures()
{
	glfwInit();

	window = glfwCreateWindow(1280, 720, "Textures", nullptr, nullptr);

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

	glEnable(GL_BLEND);
	glClearColor(0.25f, 0.25f, 0.25f, 1);
	glEnable(GL_DEPTH_TEST);
}

bool Textures::start()
{
	createData();

	m_fbx = new FBXFile();
	m_fbx->load("data/FBXmodels/stanford/Dragon.fbx");
	createOpenGLBuffers(m_fbx);

	int imageWidth = 0, imageHeight = 0, imageFormat = 0;                                             
	                                                                                                  
	unsigned char* data;

	data = stbi_load("data/textures/rock_diffuse.tga", &imageWidth, &imageHeight, &imageFormat, STBI_default);
	glGenTextures(1, &m_texture);
	glBindTexture(GL_TEXTURE_2D, m_texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	stbi_image_free(data);

	data = stbi_load("data/textures/rock_normal.tga", &imageWidth, &imageHeight, &imageFormat, STBI_default);
	glGenTextures(1, &m_normal);
	glBindTexture(GL_TEXTURE_2D, m_normal);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	stbi_image_free(data);

	const char* vsSource;
	std::string vs = ReadFromFile("vsAdvanceInfo.txt");
	vsSource = vs.c_str();

	const char* fsSource;
	std::string fs = ReadFromFile("fsAdvanceInfo.txt");
	fsSource = fs.c_str();

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

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return true;
}

bool Textures::update()
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

void Textures::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(m_programID);

	int loc = glGetUniformLocation(m_programID, "ProjectionView");
	glUniformMatrix4fv(loc, 1, GL_FALSE, &(myCamera.getProjectionView()[0][0]));

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_texture);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, m_normal);

	loc = glGetUniformLocation(m_programID, "diffuse");
	glUniform1i(loc, 0);

	loc = glGetUniformLocation(m_programID, "normal");
	glUniform1i(loc, 1);

	glm::vec3 lightAD(sin(glfwGetTime()), 1, cos(glfwGetTime()));
	loc = glGetUniformLocation(m_programID, "LightDir");
	glUniform3f(loc, lightAD.x, lightAD.y, lightAD.z);

	glBindVertexArray(m_VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

	for (unsigned int i = 0; i < m_fbx->getMeshCount(); ++i) {
		FBXMeshNode* mesh = m_fbx->getMeshByIndex(i);
		unsigned int* glData = (unsigned int*)mesh->m_userData;
		glBindVertexArray(glData[0]);
		glDrawElements(GL_TRIANGLES, (unsigned int)mesh->m_indices.size(), GL_UNSIGNED_INT, 0);
	}

	glBindVertexArray(m_VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

	myCamera.update(delta, window);

	glfwSwapBuffers(window);
	glfwPollEvents();
}

void Textures::destroy()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

std::string Textures::ReadFromFile(std::string text)
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

void Textures::createData()
{
	Vertex vertexData[] = {
		{ -5, 0, 5, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1 },
		{ 5, 0, 5, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1 },
		{ 5, 0, -5, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0 },
		{ -5, 0, -5, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0 },
	};
	unsigned int indexData[] = {
		0, 1, 2,
		0, 2, 3,
	};
	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);

	glGenBuffers(1, &m_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 4, vertexData, GL_STATIC_DRAW);

	glGenBuffers(1, &m_IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 6, indexData, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), ((char*)0) + 48);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), ((char*)0) + 16);
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), ((char*)0) + 32);
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Textures::createOpenGLBuffers(FBXFile* fbx)
{
	for (unsigned int i = 0; i < fbx->getMeshCount(); ++i)
	{
		FBXMeshNode* mesh = fbx->getMeshByIndex(i);
		unsigned int* glData = new unsigned int[3];

		glGenVertexArrays(1, &glData[0]);
		glBindVertexArray(glData[0]);
		glGenBuffers(1, &glData[1]);
		glGenBuffers(1, &glData[2]);
		glBindBuffer(GL_ARRAY_BUFFER, glData[1]);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, glData[2]);
		glBufferData(GL_ARRAY_BUFFER, mesh->m_vertices.size() * sizeof(FBXVertex), mesh->m_vertices.data(), GL_STATIC_DRAW);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->m_indices.size() * sizeof(unsigned int), mesh->m_indices.data(), GL_STATIC_DRAW);
		glEnableVertexAttribArray(0); 
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(FBXVertex), 0);
		glEnableVertexAttribArray(1); 
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_TRUE, sizeof(FBXVertex), ((char*)0) + FBXVertex::NormalOffset);
		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		mesh->m_userData = glData;
	}
}