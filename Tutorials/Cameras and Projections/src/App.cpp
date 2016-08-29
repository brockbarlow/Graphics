#include "App.h"
#include "Camera.h"

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
	//
	/*myCamera = new FlyCamera;*/

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
	view = glm::lookAt(glm::vec3(8, 8, 8), glm::vec3(0), glm::vec3(0, 1, 0));
	projection = glm::perspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.f);

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
	glm::mat4 cameraTransform = glm::inverse(view);
	cameraTransform = cameraTransform * glm::translate(glm::vec3(0, 0, 10 * delta));
	view = glm::inverse(cameraTransform);
	//
	while (glfwWindowShouldClose(window) == false && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Gizmos::clear();
		Gizmos::addTransform(glm::mat4(1));

		angle += 0.01f;

		//rotates the sun
		glm::mat4 sunRotation = glm::rotate(angle, glm::vec3(0, 1, 0));
		sun = glm::mat4(1) * sunRotation;

		glm::mat4 newEarth = glm::translate(tes) * glm::rotate(angle, glm::vec3(0, 1, 0));
		glm::mat4 newMoon = glm::translate(tme) * glm::rotate(angle, glm::vec3(0, 1, 0));
		earth = sun * newEarth;
		moon = earth * newMoon;

		//
		/*myCamera->update(deltaTime);
		Gizmos::draw(myCamera->getProjectionView());*/

		return true;
	}
	return false;
}

void SolarApp::draw()
{
	//draws the sun, earth, and the moon
	Gizmos::addSphere(glm::vec3(sun[3]), 1, 50, 50, yellow, &sun);
	Gizmos::addSphere(glm::vec3(earth[3]), 0.6f, 50, 50, blue, &earth);
	Gizmos::addSphere(glm::vec3(moon[3]), 0.2f, 50, 50, white, &moon);

	//draws grid
	for (int i = 0; i < 21; ++i)
	{
		Gizmos::addLine(glm::vec3(-10 + i, 0, 10), glm::vec3(-10 + i, 0, -10), i == 10 ? white : black);
		Gizmos::addLine(glm::vec3(10, 0, -10 + i), glm::vec3(-10, 0, -10 + i), i == 10 ? white : black);
	}

	Gizmos::draw(projection * view);
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void SolarApp::end()
{
	glfwDestroyWindow(window);
	Gizmos::destroy();
	glfwTerminate();
}