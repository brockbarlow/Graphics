#pragma once
#include <iostream>
#include "gl_core_4_4.h"
#include "Gizmos.h"
#include <GLFW\glfw3.h>
#include <glm.hpp>
#include <ext.hpp>
#include "Camera.h"

class Application
{
public:
	virtual bool start() = 0;
	virtual bool update() = 0;
	virtual void draw() = 0;
	virtual void end() = 0;
};

class SolarApp : public Application
{
public:
	SolarApp();
	bool start() override;
	bool update() override;
	void draw() override;
	void end() override;
private:
	GLFWwindow* window;
	FlyCamera myCamera;
	glm::vec4 white, black, yellow, blue;
	glm::mat4 sun, earth, moon = glm::mat4(1); 
	glm::vec3 tes = glm::vec3(4, 0, 0);        
	glm::vec3 tme = glm::vec3(2, 0, 0);        
	float angle = 0.0f;                        
	float previous = 0;
	float current;
	float delta;
};