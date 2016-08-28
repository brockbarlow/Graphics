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

//app class. holds pure virtual functions
class Application
{
public:
	//pure virtual functions
	virtual bool start() = 0;
	virtual bool update() = 0;
	virtual void draw() = 0;
	virtual void end() = 0;
};

//solar system class. everything is public. inherits from app class.
class SolarApp : public Application
{
public:
	SolarApp();
	//virtual function overrides.
	bool start() override;
	bool update() override;
	void draw() override;
	void end() override;

	GLFWwindow* window;
	vec4 white, black, yellow, blue;
	mat4 view, projection;
	mat4 sun, earth, moon = mat4(1); //planets
	vec3 tes = vec3(4, 0, 0);        //Translation of the Earth from the Sun
	vec3 tme = vec3(2, 0, 0);        //Translation of the Moon from the Earth
	float angle = 0.0f;              //used with rotate
	//
	float previous = 0;
	float current;
	float delta;
};