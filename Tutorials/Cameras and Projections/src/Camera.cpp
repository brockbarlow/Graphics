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
	updateProjectionView();
	return projectionViewTransform;
}

void Camera::worldRotation(glm::mat4 rotate)
{
	worldTransform = worldTransform * rotate;
}

void Camera::updateProjectionView()
{
	projectionViewTransform = projectionTransform * viewTransform * worldTransform;
}

glm::mat4 getRotateMatrix(float angle, glm::vec3 up) {
	return glm::rotate(angle, up);
}

void FlyCamera::update(float deltaTime, GLFWwindow* window)
{
	glm::vec3 moveBy = glm::vec3(0);			
	glm::mat4 rotateBy = glm::mat4(1);				
	double x, y;
	glfwGetCursorPos(window, &x, &y);
	double Xoffset;
	double Yoffset;

	Xoffset = oldX - x;
	Yoffset = oldY - y;

	oldX = x;
	oldY = y;

	Xoffset *= .005;
	Yoffset *= .005;

	int stateW = glfwGetKey(window, GLFW_KEY_W);
	int stateS = glfwGetKey(window, GLFW_KEY_S);
	int stateA = glfwGetKey(window, GLFW_KEY_A);	
	int stateD = glfwGetKey(window, GLFW_KEY_D);	
	int stateMouse = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);	

	if (stateMouse == GLFW_PRESS) {		
		if (Yoffset > 1 || Yoffset < 1) {
			double rotate = Yoffset;
			rotateBy[1][1] = cos(rotate);
			rotateBy[1][2] = -sin(rotate);
			rotateBy[2][1] = sin(rotate);
			rotateBy[2][2] = cos(rotate);
		}
		if (Xoffset > 1 || Xoffset < 1) {
			double rotate = Xoffset;
			rotateBy[0][0] = cos(rotate);
			rotateBy[0][2] = sin(rotate);
			rotateBy[2][0] = -sin(rotate);
			rotateBy[2][2] = cos(rotate);
		}
	}

	if (stateW == GLFW_PRESS) {
		moveBy.x += speed * deltaTime;
		moveBy.z += speed * deltaTime;
	}

	if (stateS == GLFW_PRESS) {
		moveBy.x -= speed * deltaTime;
		moveBy.z -= speed * deltaTime;
	}

	if (stateA == GLFW_PRESS) {
		moveBy.x += speed * deltaTime;
		moveBy.z -= speed * deltaTime;
	}

	if (stateD == GLFW_PRESS) {
		moveBy.x -= speed * deltaTime;
		moveBy.z += speed * deltaTime;
	}
	
	worldTransform *= glm::translate(moveBy);
	worldTransform *= rotateBy;
	getProjectionView();
}

void FlyCamera::setSpeed(float speed)
{
	this->speed = speed;
}