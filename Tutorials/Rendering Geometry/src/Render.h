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
private:
	GLFWwindow* window;
	unsigned int m_programID;
	unsigned int m_VAO;
	unsigned int m_VBO;
	unsigned int m_IBO;
};