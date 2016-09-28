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

class Application
{
public:
	virtual bool start() = 0;
	virtual bool update() = 0;
	virtual void draw() = 0;
	virtual void destroy() = 0;
};

class Textures : public Application {
public:
	Textures();
	bool start() override;
	bool update() override;
	void draw() override;
	void destroy() override;
	std::string ReadFromFile(std::string text);
	void createPlane();
private:
	glm::mat4 m_projectionViewMatrix;
	glm::mat4 view;
	glm::mat4 projection;
	GLFWwindow* window;
	unsigned int m_programID;
	unsigned int m_texture;
	unsigned int m_texture2;
	unsigned int p_VAO;
	unsigned int p_VBO;
	unsigned int p_IBO;
	int p_indicesCounter;
};

struct Vertex {
	float x, y, z, w;
	float nx, ny, nz, nw;
	float tx, ty, tz, tw;
	float s, t;
};

class Advance : public Application {
public:
	Advance();
	bool start() override;
	bool update() override;
	void draw() override;
	void destroy() override;
	std::string ReadFromFile(std::string text);
	void createPlane();
private:
	glm::mat4 m_projectionViewMatrix;
	glm::mat4 view;
	glm::mat4 projection;
	GLFWwindow* window;
	unsigned int m_programID;
	unsigned int m_texture;
	unsigned int m_normal;
	unsigned int p_VAO;
	unsigned int p_VBO;
	unsigned int p_IBO;
	int p_indicesCounter;
};