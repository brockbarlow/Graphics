#pragma once
#include "App.h"
#include "Camera.h"

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
	void createSphere(const int radius, const unsigned int verts, const unsigned int halfSpheres);
	void drawSphere();
private:
	GLFWwindow* window;
	FlyCamera myCamera;
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
	float previous = 0;
	float current;
	float delta;
};