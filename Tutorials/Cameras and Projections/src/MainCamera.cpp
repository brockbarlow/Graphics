#include "Camera.h"

bool start()
{
	if (glfwInit() == false)
		return false;

	GLFWwindow* window = glfwCreateWindow(1280, 720, "Window", nullptr, nullptr);
	Camera* myCamera = new FlyCamera;

	if (window == nullptr)
	{
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(window);

	if (ogl_LoadFunctions() == ogl_LOAD_FAILED) {
		glfwDestroyWindow(window);
		glfwTerminate();
		return false;
	}

	Gizmos::create();

	float deltaTime = 0.0f;
	float previousTime = 0.0f;

	float currentTime = (float)glfwGetTime();
	deltaTime = currentTime - previousTime;
	previousTime = currentTime;

	glClearColor(0.25f, 0.25f, 0.25f, 1);
	glEnable(GL_DEPTH_TEST);

	while (glfwWindowShouldClose(window) == false && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS) {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Gizmos::clear();
		Gizmos::addTransform(glm::mat4(1));

		glm::vec4 white(1);
		glm::vec4 black(0, 0, 0, 1);
		glm::vec4 yellow(1, 1, 0, 1);

		glm::mat4 sun = glm::mat4(1);
		Gizmos::addSphere(glm::vec3(sun[3]), 1, 50, 50, yellow, &sun);

		for (int i = 0; i < 21; ++i) {
			Gizmos::addLine(glm::vec3(-10 + i, 0, 10), glm::vec3(-10 + i, 0, -10), i == 10 ? white : black);
			Gizmos::addLine(glm::vec3(10, 0, -10 + i), glm::vec3(-10, 0, -10 + i), i == 10 ? white : black);
		}

		myCamera->update(deltaTime);
		Gizmos::draw(myCamera->getProjectionView());
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	return true;
}

int main()
{
	start();

	return 0;
}