#pragma once
#include <iostream>
#include "gl_core_4_4.h"
#include "Gizmos.h"
#include <GLFW\glfw3.h>
#include <glm.hpp>
#include <ext.hpp>

class Camera {
public:
	virtual void update(float deltaTime, GLFWwindow* window) = 0;
	void setPerspective(float  fieldOfView, float aspectRatio, float near, float far);
	void setLookAt(glm::vec3 from, glm::vec3 to, glm::vec3 up);
	void setPosition(glm::vec3 position);
	glm::mat4 getWorldTransform();
	glm::mat4 getView();
	glm::mat4 getProjection();
	glm::mat4 getProjectionView();
	double oldX = 0;
	double oldY = 0;
	void worldRotation(glm::mat4 rotate);
	glm::mat4 viewTransform;
	glm::mat4 worldTransform;
private:
	void updateProjectionView();
	glm::mat4 projectionTransform;
	glm::mat4 projectionViewTransform;
};

class FlyCamera : public Camera {
public:
	void update(float deltaTime, GLFWwindow* window) override;
	void setSpeed(float speed);
private:
	glm::vec3 up;
	float speed;
};