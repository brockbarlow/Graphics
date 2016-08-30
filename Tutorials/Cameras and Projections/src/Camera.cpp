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
	up = glm::vec3(0, 1, 0);
	setPerspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.f);
	setLookAt(glm::vec3(8, 8, 8), glm::vec3(0), up);
}

void FlyCamera::update(float deltaTime, GLFWwindow* window)
{
	window = glfwGetCurrentContext();

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT))
	{
		glfwGetCursorPos(window, &posX, &posY);

		while (mouseMove)
		{
			lastX = posX;
			lastY = posY;
			mouseMove = false;
		}

		offsetX *= 0.005f;
		offsetY *= 0.005f;

		switch (offsetX < 1 || offsetX > 1)
		{
		default:
			angle = offsetX;
			rotateCam[0][0] = cos(angle);
			rotateCam[0][2] = sin(angle);
			rotateCam[2][0] = -1.f * sin(angle);
			rotateCam[2][2] = cos(angle);
			break;
		}
		switch (offsetY < 1 || offsetY > 1)
		{
		default:
			angle = offsetY;
			rotateCam[1][1] = cos(angle);
			rotateCam[1][2] = -1.f * sin(angle);
			rotateCam[2][1] = sin(angle);
			rotateCam[2][2] = cos(angle);
			break;
		}

		lastX = posX;
		lastY = posY;

		/*if (offsetX < 1 || offsetX > 1)
		{
			angle = offsetX;
			rotateCam[0][0] = cos(angle);
			rotateCam[0][2] = sin(angle);
			rotateCam[2][0] = -1.f * sin(angle);
			rotateCam[2][2] = cos(angle);
		}*/
	}

	

	viewTransform *= glm::inverse(translateCam * rotateCam * scaleCam);
	updateProjectionViewTransform();
}

void FlyCamera::setSpeed(float speed)
{
	this->speed = speed;
}

/*
if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
{
camTrans = glm::translate(vec3(0, 0, (-0.10f * deltaTime) * 10));
}
if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
{
camTrans = glm::translate(vec3((-0.10f * deltaTime) * 10, 0, 0));
}
if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
{
camTrans = glm::translate(vec3(0, 0, (0.10f * deltaTime) * 10));
}
if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
{
camTrans = glm::translate(vec3((0.10f * deltaTime) * 10, 0, 0));
}
*/