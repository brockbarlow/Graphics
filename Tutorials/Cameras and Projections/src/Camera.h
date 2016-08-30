#pragma once
#include <iostream>
#include "gl_core_4_4.h"
#include "Gizmos.h"
#include <GLFW\glfw3.h>
#include <glm.hpp>
#include <ext.hpp>

class Camera {
public:
	virtual void update(float deltaTime) = 0;
	void setPerspective(float  fieldOfView, float aspectRatio, float near, float far);
	void setLookAt(glm::vec3 from, glm::vec3 to, glm::vec3 up);
	void setPosition(glm::vec3 position);
	glm::mat4 getWorldTransform();
	glm::mat4 getView();
	glm::mat4 getProjection();
	glm::mat4 getProjectionView();
	void updateProjectionViewTransform();
	glm::mat4 viewTransform;
	glm::mat4 worldTransform;
private:
	glm::mat4 projectionTransform;
	glm::mat4 projectionViewTransform;
};

class FlyCamera : public Camera {
public:
	FlyCamera();
	void update(float deltaTime) override;
	void setSpeed(float speed);
private:
	GLFWwindow* window;                //needed for get mouse button and get key if statements
	glm::vec3 up = glm::vec3(0, 1, 0);
	float angle = 0.0f;  //used with rotation
	float speed;
};