#include "Render.h"

RenderingGeometry::RenderingGeometry()
{

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