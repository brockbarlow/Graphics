#include "App.h"

SolarApp::SolarApp()
{

}

bool SolarApp::start()
{
	white = glm::vec4(1);
	black = glm::vec4(0, 0, 0, 1);
	yellow = glm::vec4(1, 1, 0, 1);
	blue = glm::vec4(0, 0, 1, 1);

	if (glfwInit() == false)
	{
		return false;
	}

	window = glfwCreateWindow(1280, 720, "Computer Graphics", nullptr, nullptr);

	if (window == nullptr)
	{
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(window);

	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		return false;
	}

	Gizmos::create();

	myCamera.setLookAt(glm::vec3(10, 10, 10), glm::vec3(0), glm::vec3(0, 1, 0));
	myCamera.setPerspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.f);
	myCamera.setSpeed(10);

	auto major = ogl_GetMajorVersion();
	auto minor = ogl_GetMinorVersion();
	printf("GL: %i.%i\n", major, minor);

	glClearColor(0.25f, 0.25f, 0.25f, 1);
	glEnable(GL_DEPTH_TEST); //enables the depth buffer

	return true;
}

bool SolarApp::update()
{	
	current = (float)glfwGetTime();
	delta = current - previous;
	previous = current;

	while (glfwWindowShouldClose(window) == false && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Gizmos::clear();
		Gizmos::addTransform(glm::mat4(1));

		angle += 0.01f;

		glm::mat4 sunRotation = glm::rotate(angle, glm::vec3(0, 1, 0));
		sun = glm::mat4(1) * sunRotation;

		glm::mat4 newEarth = glm::translate(tes) * glm::rotate(angle, glm::vec3(0, 1, 0));
		glm::mat4 newMoon = glm::translate(tme) * glm::rotate(angle, glm::vec3(0, 1, 0));
		earth = sun * newEarth;
		moon = earth * newMoon;

		return true;
	}
	return false;
}

void SolarApp::draw()
{
	Gizmos::addSphere(glm::vec3(sun[3]), 1, 50, 50, yellow, &sun);
	Gizmos::addSphere(glm::vec3(earth[3]), 0.6f, 50, 50, blue, &earth);
	Gizmos::addSphere(glm::vec3(moon[3]), 0.2f, 50, 50, white, &moon);

	for (int i = 0; i < 21; ++i)
	{
		Gizmos::addLine(glm::vec3(-10 + i, 0, 10), glm::vec3(-10 + i, 0, -10), i == 10 ? white : black);
		Gizmos::addLine(glm::vec3(10, 0, -10 + i), glm::vec3(-10, 0, -10 + i), i == 10 ? white : black);
	}

	myCamera.update(delta, window);
	Gizmos::draw(myCamera.getProjectionView());
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void SolarApp::end()
{
	glfwDestroyWindow(window);
	Gizmos::destroy();
	glfwTerminate();
}