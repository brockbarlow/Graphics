//#pragma once
//#include <iostream>
//#include "gl_core_4_4.h"
//#include "Gizmos.h"
//#include <GLFW\glfw3.h>
//#include <glm.hpp>
//#include <ext.hpp>
//
////app class. holds pure virtual functions
//class Application
//{
//public:
//	//pure virtual functions
//	virtual bool start() = 0;
//	virtual bool update() = 0;
//	virtual void draw() = 0;
//	virtual void end() = 0;
//};
//
////solar system class. everything is public. inherits from app class.
//class SolarApp : public Application
//{
//public:
//	SolarApp();
//	//virtual function overrides.
//	bool start() override;
//	bool update() override;
//	void draw() override;
//	void end() override;
//private:
//	GLFWwindow* window;
//	glm::vec4 white, black, yellow, blue;
//	glm::mat4 view, projection;
//	glm::mat4 sun, earth, moon = glm::mat4(1); //planets
//	glm::vec3 tes = glm::vec3(4, 0, 0);        //Translation of the Earth from the Sun
//	glm::vec3 tme = glm::vec3(2, 0, 0);        //Translation of the Moon from the Earth
//	float angle = 0.0f;                        //used with rotate
//};