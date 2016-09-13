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
	void createCube();
	//std::vector<unsigned int> generateVertices(int nm, int np);
	Vertex* generateVertices(unsigned int np, const int rad);
	Vertex* generateSphere(unsigned int np, unsigned int nm, Vertex* hc);
	void createSphere();
private:
	glm::mat4 m_projectionViewMatrix;
	glm::mat4 view;
	glm::mat4 projection;
	GLFWwindow* window;
	unsigned int m_programID;
	unsigned int m_VAO;
	unsigned int m_VBO;
	unsigned int m_IBO;
	int indicesCounter;
	float pi = 3.14159265359f;
	float angle = 0;
};