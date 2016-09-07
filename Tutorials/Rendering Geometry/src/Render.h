#pragma once
#include "App.h"

struct Vertex
{
	
	glm::vec4 color;
	glm::vec4 position;
};

class RenderingGeometry : public Application {

public:
	RenderingGeometry();
	bool start() override;
	bool update() override;
	void draw() override;
	void destroy() override;
	//void generateGrid(unsigned int rows, unsigned int cols);
	//void generatePlane();
private:
	glm::mat4 m_projectionViewMatrix;
	glm::mat4 view;
	glm::mat4 projection;
	GLFWwindow* window;
	unsigned int m_programID;
	unsigned int m_VAO;
	unsigned int m_VBO;
	unsigned int m_IBO;
	int rows;
	int cols;
};

/*Vertex vertices[4];
	unsigned int indices[4] = { 0,1,2,3 };

	vertices[0].position = glm::vec4(-5, 0, -5, 1);
	vertices[1].position = glm::vec4(5, 0, -5, 1);
	vertices[2].position = glm::vec4(-5, 0, 5, 1);
	vertices[3].position = glm::vec4(5, 0, 5, 1);

	vertices[0].color = glm::vec4(1, 0, 0, 1);
	vertices[1].color = glm::vec4(0, 1, 0, 1);
	vertices[2].color = glm::vec4(0, 0, 1, 1);
	vertices[3].color = glm::vec4(1, 1, 1, 1);*/