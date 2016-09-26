#pragma once
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
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

struct Vertex
{
	glm::vec4 Position;
	glm::vec4 color;
	glm::vec2 TexCoord;
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
	void drawPlane();
	void createCube();
	void drawCube();
	Vertex* generateHalfSphereVertices(unsigned int np, const int &rad);
	Vertex* generateSphereVertices(const unsigned int &sides, const unsigned int &mirid, Vertex* &halfSphere);
	unsigned int* generateSphereIndicies(const unsigned int &vertices, const unsigned int &mirid);
	std::vector<unsigned int> indicesHolder;
	void createSphere(const int radius, const unsigned int verts, const unsigned int halfSpheres);
	void drawSphere();
private:
	glm::mat4 m_projectionViewMatrix;
	glm::mat4 view;
	glm::mat4 projection;
	GLFWwindow* window;
	unsigned int m_programID;
	unsigned int p_VAO;
	unsigned int p_VBO;
	unsigned int p_IBO;
	unsigned int c_VAO;
	unsigned int c_VBO;
	unsigned int c_IBO;
	unsigned int s_VAO;
	unsigned int s_VBO;
	unsigned int s_IBO;
	int p_indicesCounter;
	int c_indicesCounter;
	int s_indicesCounter;
	float pi = 3.14159265359f;
};