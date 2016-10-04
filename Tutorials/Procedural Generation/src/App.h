#pragma once
#include <iostream>
#include "gl_core_4_4.h"
#include "Gizmos.h"
#include <GLFW\glfw3.h>
#include <glm.hpp>
#include <ext.hpp>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <gtx\transform.hpp>
#include <gtc\matrix_transform.hpp>
#include <FBXFile.h>

class Application
{
public:
	virtual bool start() = 0;
	virtual bool update() = 0;
	virtual void draw() = 0;
	virtual void destroy() = 0;
};

struct Vertex
{
	glm::vec4 position;
	glm::vec2 UV;
};

class ProceduralGeneration : public Application
{
public:
	ProceduralGeneration();
	bool start() override;
	bool update() override;
	void draw() override;
	void destroy() override;
	std::string ReadFromFile(std::string text);
	float* generatePerlin();
	void createPlane(const int &width, const int &height);
private:
	glm::mat4 m_projectionViewMatrix;
	glm::mat4 view;
	glm::mat4 projection;
	GLFWwindow* window;
	unsigned int m_programID;
	unsigned int m_texture;
	unsigned int m_rocks;
	unsigned int m_VAO;
	unsigned int m_VBO;
	unsigned int m_IBO;
	int m_indexCounter;
};