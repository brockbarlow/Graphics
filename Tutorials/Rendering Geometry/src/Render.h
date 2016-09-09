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
	void generatePlane();
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