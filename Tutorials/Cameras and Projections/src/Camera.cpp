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
	setLookAt(glm::vec3(8, 8, 8), glm::vec3(0), up);
	setPerspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.f);
}

void FlyCamera::update(float deltaTime)
{
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT))
	{

	}

	if (glfwGetKey(window, GLFW_KEY_W))
	{

	}

	if (glfwGetKey(window, GLFW_KEY_A))
	{

	}

	if (glfwGetKey(window, GLFW_KEY_S))
	{

	}

	if (glfwGetKey(window, GLFW_KEY_D))
	{

	}

	//worldTransform = glm::inverse();
	viewTransform *= worldTransform;
	updateProjectionViewTransform();
}

void FlyCamera::setSpeed(float speed)
{
	
}