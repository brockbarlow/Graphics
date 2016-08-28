#include "App.h"
#include "Camera.h"

SolarApp::SolarApp()
{

}

bool SolarApp::start()
{
	white = vec4(1);
	black = vec4(0, 0, 0, 1);
	yellow = vec4(1, 1, 0, 1);
	blue = vec4(0, 0, 1, 1);

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
	view = lookAt(vec3(8, 8, 8), vec3(0), vec3(0, 1, 0));
	projection = perspective(pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.f);

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
	mat4 cameraTransform = glm::inverse(view);
	cameraTransform = cameraTransform * glm::translate(vec3(0, 0, 10 * delta));
	view = glm::inverse(cameraTransform);
	//
	while (glfwWindowShouldClose(window) == false && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Gizmos::clear();
		Gizmos::addTransform(mat4(1));

		angle += 0.01f;

		//rotates the sun
		mat4 sunRotation = rotate(angle, vec3(0, 1, 0));
		sun = mat4(1) * sunRotation;

		mat4 newEarth = translate(tes) * rotate(angle, vec3(0, 1, 0));
		mat4 newMoon = translate(tme) * rotate(angle, vec3(0, 1, 0));
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
	Gizmos::addSphere(vec3(sun[3]), 1, 50, 50, yellow, &sun);
	Gizmos::addSphere(vec3(earth[3]), 0.6f, 50, 50, blue, &earth);
	Gizmos::addSphere(vec3(moon[3]), 0.2f, 50, 50, white, &moon);

	//draws grid
	for (int i = 0; i < 21; ++i)
	{
		Gizmos::addLine(vec3(-10 + i, 0, 10), vec3(-10 + i, 0, -10), i == 10 ? white : black);
		Gizmos::addLine(vec3(10, 0, -10 + i), vec3(-10, 0, -10 + i), i == 10 ? white : black);
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