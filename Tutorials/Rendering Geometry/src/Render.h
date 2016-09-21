#pragma once
#include "App.h"

struct Vertex
{
	glm::vec4 position;
	glm::vec4 color;
};

class RenderingGeometry : public Application {
public:
	RenderingGeometry();
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
	void createSphere();
	void drawSphere();
private:
	glm::mat4 m_projectionViewMatrix;
	glm::mat4 view;
	glm::mat4 projection;
	GLFWwindow* window;
	unsigned int m_programID;
	unsigned int m_VAO;
	unsigned int m_VBO;
	unsigned int m_IBO;
	//
	unsigned int p_VAO;
	unsigned int p_VBO;
	unsigned int p_IBO;
	unsigned int c_VAO;
	unsigned int c_VBO;
	unsigned int c_IBO;
	unsigned int s_VAO;
	unsigned int s_VBO;
	unsigned int s_IBO;
	//
	int indicesCounter;
	//
	int p_indicesCounter;
	int c_indicesCounter;
	int s_indicesCounter;
	//
	float pi = 3.14159265359f;
};