#pragma once
#include <iostream>
#include "gl_core_4_4.h"
#include "Gizmos.h"
#include <GLFW\glfw3.h>
#include <glm.hpp>
#include <ext.hpp>

using glm::vec3;
using glm::vec4;
using glm::mat4;
using glm::translate;
using glm::rotate;
using glm::lookAt;
using glm::perspective;
using glm::pi;
using namespace std;

class Camera {
public:
	virtual void update(float deltaTime) = 0;
	void setPerspective(float  fieldOfView, float aspectRatio, float near, float far);
	void setLookAt(vec3 from, vec3 to, vec3 up);
	void setPosition(vec3 position);
	mat4 getWorldTransform();
	mat4 getView();
	mat4 getProjection();
	mat4 getProjectionView();
	void updateProjectionViewTransform();
	mat4 worldTransform;
	mat4 viewTransform;
	mat4 projectionTransform;
	mat4 projectionViewTransform;
};

class FlyCamera : public Camera {
public:
	void update(float deltaTime) override;
	void setSpeed(float speed);
	vec3 up;
	float speed;
};