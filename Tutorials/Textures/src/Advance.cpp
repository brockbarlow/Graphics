////#define STB_IMAGE_IMPLEMENTATION
//#include <stb_image.h>
//#include "App.h"
//
//Advance::Advance()
//{
//	glfwInit();
//
//	window = glfwCreateWindow(1280, 720, "Textures", nullptr, nullptr);
//
//	if (window == nullptr)
//	{
//		glfwTerminate();
//	}
//
//	glfwMakeContextCurrent(window);
//
//	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
//	{
//		glfwDestroyWindow(window);
//		glfwTerminate();
//	}
//
//	view = glm::lookAt(glm::vec3(15, 15, 15), glm::vec3(0), glm::vec3(0, 1, 0));
//	projection = glm::perspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.f);
//
//	
//	glClearColor(0.25f, 0.25f, 0.25f, 1);
//	glEnable(GL_DEPTH_TEST);
//}
//
//bool Advance::start()
//{
//	createPlane();
//
//	int imageWidth = 0, imageHeight = 0, imageFormat = 0;
//
//	unsigned char* data;
//	data = stbi_load("data/textures/rock_diffuse.tga", &imageWidth, &imageHeight, &imageFormat, STBI_default);
//	glGenTextures(1, &m_texture);
//	glBindTexture(GL_TEXTURE_2D, m_texture);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	stbi_image_free(data);
//
//	data = stbi_load("data/textures/rock_normal.tga", &imageWidth, &imageHeight, &imageFormat, STBI_default);
//	glGenTextures(1, &m_normal);
//	glBindTexture(GL_TEXTURE_2D, m_normal);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	stbi_image_free(data);
//
//	const char* vsSource;
//	std::string vs = ReadFromFile("vsAdvText.glsl");
//	vsSource = vs.c_str();
//
//	const char* fsSource;
//	std::string fs = ReadFromFile("fsAdvText.glsl");
//	fsSource = fs.c_str();
//
//	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//
//	glShaderSource(vertexShader, 1, (const char**)&vsSource, 0);
//	glCompileShader(vertexShader);
//	glShaderSource(fragmentShader, 1, (const char**)&fsSource, 0);
//	glCompileShader(fragmentShader);
//
//	m_programID = glCreateProgram();
//	glAttachShader(m_programID, vertexShader);
//	glAttachShader(m_programID, fragmentShader);
//	glLinkProgram(m_programID);
//
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//
//	return true;
//}
//
//bool Advance::update()
//{
//	while (glfwWindowShouldClose(window) == false && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
//	{
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		return true;
//	}
//	return false;
//}
//
//void Advance::draw()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glUseProgram(m_programID);
//
//	m_projectionViewMatrix = projection * view;
//
//	int loc = glGetUniformLocation(m_programID, "ProjectionView");
//	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(m_projectionViewMatrix));
//
//	glActiveTexture(GL_TEXTURE0);
//	glBindTexture(GL_TEXTURE_2D, m_texture);
//
//	glActiveTexture(GL_TEXTURE1);
//	glBindTexture(GL_TEXTURE_2D, m_normal);
//
//	loc = glGetUniformLocation(m_programID, "diffuse");
//	glUniform1i(loc, 0);
//	
//	loc = glGetUniformLocation(m_programID, "normal");
//	glUniform1i(loc, 1);
//
//	glm::vec3 light(sin(glfwGetTime()), 1, cos(glfwGetTime()));
//	loc = glGetUniformLocation(m_programID, "LightDir");
//	glUniform3f(loc, light.x, light.y, light.z);
//
//	glBindVertexArray(p_VAO);
//	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
//
//	glfwSwapBuffers(window);
//	glfwPollEvents();
//}
//
//void Advance::destroy()
//{
//	glfwDestroyWindow(window);
//	glfwTerminate();
//}
//
//std::string Advance::ReadFromFile(std::string text)
//{
//	std::string data;
//	std::string container;
//	std::ifstream file(text);
//
//	if (file.is_open())
//	{
//		while (std::getline(file, data))
//		{
//			container += data + "\n";
//		}
//		file.close();
//	}
//	return container;
//}
//
//void Advance::createPlane()
//{
//	Vertex vertexData[] = {
//		{ -5, 0, 5, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1 },
//		{ 5, 0, 5, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1 },
//		{ 5, 0, -5, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0 },
//		{ -5, 0, -5, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0 },
//	};
//	unsigned int indexData[] = {
//		0, 1, 2,
//		0, 2, 3,
//	};
//	glGenVertexArrays(1, &p_VAO);
//	glBindVertexArray(p_VAO);
//	
//	glGenBuffers(1, &p_VBO);
//	glBindBuffer(GL_ARRAY_BUFFER, p_VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 4, vertexData, GL_STATIC_DRAW);
//	
//	glGenBuffers(1, &p_IBO);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, p_IBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 6, indexData, GL_STATIC_DRAW);
//	
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), ((char*)0) + 48);
//	glEnableVertexAttribArray(2);
//	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), ((char*)0) + 16);
//	glEnableVertexAttribArray(3);
//	glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), ((char*)0) + 32);
//	glBindVertexArray(0);
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//}