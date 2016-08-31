#include "Camera.h"

void Camera::setPerspective(float fieldOfView, float aspectRatio, float n, float f)
{
	projectionTransform = glm::perspective(fieldOfView, aspectRatio, n, f);
}

void Camera::setLookAt(glm::vec3 from, glm::vec3 to, glm::vec3 up)
{
	viewTransform = glm::lookAt(from, to, up);
}

void Camera::setPosition(glm::vec3 position)
{
	
}

glm::mat4 Camera::getWorldTransform()
{
	return worldTransform;
}

glm::mat4 Camera::getView()
{
	return viewTransform;
}

glm::mat4 Camera::getProjection()
{
	return projectionTransform;
}

glm::mat4 Camera::getProjectionView()
{
	return projectionViewTransform;
}

void Camera::updateProjectionViewTransform()
{
	projectionViewTransform = projectionTransform * viewTransform;
}

FlyCamera::FlyCamera()
{
	up = glm::vec3(0,1,0);
	setLookAt(glm::vec3(8, 8, 8), glm::vec3(0), up);
	setPerspective(glm::pi<float>() * 0.35f, 16 / 9.f, 0.1f, 1000.f);
	oldX, oldY = 0;
	mousePress = true;
}

void FlyCamera::update(float deltaTime)
{
	GLFWwindow* window = glfwGetCurrentContext();

	glm::mat4 translationCamera, rotationCamera, scaleCamera = glm::mat4(1);

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT))
	{
		double posX, posY = 0;
		float angle = 0.0f;
		glfwGetCursorPos(window, &posX, &posY);

		if (mousePress)
		{
			oldX = posX;
			oldY = posY;
			mousePress = false;
		}

		float newX = oldX - posX;
		float newY = oldY - posY;

		newX *= 0.005f;
		newY *= 0.005f;

		if (newX < 1 || newX > 1)
		{
			angle = newX;
			rotationCamera[0][0] = cos(angle);
			rotationCamera[0][2] = sin(angle);
			rotationCamera[2][0] = -1.f * sin(angle);
			rotationCamera[2][2] = cos(angle);
		}

		if (newY < 1 || newY > 1)
		{
			angle = newY;
			rotationCamera[1][1] = cos(angle);
			rotationCamera[1][2] = -1.f * sin(angle);
			rotationCamera[2][1] = sin(angle);
			rotationCamera[2][2] = cos(angle);
		}

		oldX = posX;
		oldY = posY;
	}

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		translationCamera = glm::translate(glm::vec3(0, 0, (-0.10f * deltaTime) * 10));
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		translationCamera = glm::translate(glm::vec3((-0.10f * deltaTime) * 10, 0, 0));
	}

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		translationCamera = glm::translate(glm::vec3(0, 0, (0.10f * deltaTime) * 10));
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		translationCamera = glm::translate(glm::vec3((0.10f * deltaTime) * 10, 0, 0));
	}

	worldTransform = glm::inverse(translationCamera * rotationCamera * scaleCamera);
	viewTransform *= worldTransform;
	updateProjectionViewTransform();
}

void FlyCamera::setSpeed(float speed)
{
	
}