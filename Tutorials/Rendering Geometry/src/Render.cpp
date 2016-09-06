#include "Render.h"

RenderingGeometry::RenderingGeometry()
{

}

void RenderingGeometry::generateGrid(unsigned int rows, unsigned int cols)
{
	Vertex* aoVertices = new Vertex[rows * cols];
	for (unsigned int r = 0; r < rows; r++)
	{
		for (unsigned int c = 0; c < cols; c++)
		{
			aoVertices[r * cols + c].position = glm::vec4((float)c, 0, (float)r, 1);
			glm::vec3 color = glm::vec3(sinf((c / (float)(cols - 1)) * (r / (float)(rows - 1))));
			aoVertices[r * cols + c].color = glm::vec4(color, 1);
		}
	}
	delete[] aoVertices;
}

bool RenderingGeometry::start()
{

}

bool RenderingGeometry::update()
{

}

void RenderingGeometry::draw()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void RenderingGeometry::destroy()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}