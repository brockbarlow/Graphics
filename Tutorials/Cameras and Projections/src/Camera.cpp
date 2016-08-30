#include "Camera.h"

void Camera::setPerspective(float fieldOfView, float aspectRatio, float n, float f)
{
	
}

void Camera::setLookAt(glm::vec3 from, glm::vec3 to, glm::vec3 up)
{
	
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
	
}

void FlyCamera::update(float deltaTime, GLFWwindow* window)
{

}

void FlyCamera::setSpeed(float speed)
{
	
}