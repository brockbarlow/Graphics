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
	worldTransform = worldTransform * glm::translate(position);
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
	setLookAt(glm::vec3(8, 8, 8), glm::vec3(0), up);
	setPerspective(glm::pi<float>() * 0.35f, 16 / 9.f, 0.1f, 1000.f);
}

void FlyCamera::update(float deltaTime)
{
	GLFWwindow* window = glfwGetCurrentContext();

	glm::mat4 translationCamera, rotationCamera, scaleCamera = glm::mat4(1);

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT))
	{
		glfwGetCursorPos(window, &posX, &posY);

		if (mousePress)
		{
			oldX = posX;
			oldY = posY;
			mousePress = false;
		}

		float offsetX = oldX - posX;
		float offsetY = oldY - posY;

		offsetX *= 0.005f;
		offsetY *= 0.005f;

		if (offsetX < 1 || offsetX > 1)
		{
			angle = offsetX;
			rotationCamera[0][0] = cos(angle);
			rotationCamera[0][2] = sin(angle);
			rotationCamera[2][0] = -1.f * sin(angle);
			rotationCamera[2][2] = cos(angle);
		}

		if (offsetY < 1 || offsetY > 1)
		{
			angle = offsetY;
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
	this->speed = speed;
}