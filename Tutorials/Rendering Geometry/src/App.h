#pragma once
#include <iostream>
#include "gl_core_4_4.h"
#include "Gizmos.h"
#include <GLFW\glfw3.h>
#include <glm.hpp>
#include <ext.hpp>

class Application
{
public:
	virtual bool startUp() = 0;
	virtual bool update() = 0;
	virtual void Draw() = 0;
	virtual void Destroy() = 0;
};