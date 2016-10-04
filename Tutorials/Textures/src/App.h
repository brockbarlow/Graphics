#pragma once
#include <iostream>
#include "gl_core_4_4.h"
#include "Gizmos.h"
#include <GLFW\glfw3.h>
#include <glm.hpp>
#include <ext.hpp>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <FBXFile.h>
#include "Camera.h"

class Application
{
public:
	virtual bool start() = 0;
	virtual bool update() = 0;
	virtual void draw() = 0;
	virtual void destroy() = 0;
};

struct Vertex {
	float x, y, z, w;
	float nx, ny, nz, nw;
	float tx, ty, tz, tw;
	float s, t;
};

class Textures : public Application {
public:
	Textures();
	bool start() override;
	bool update() override;
	void draw() override;
	void destroy() override;
	std::string ReadFromFile(std::string text);
	void createPlane();
	void createData();
	void createOpenGLBuffers(FBXFile* fbx);
private:
	GLFWwindow* window;
	FlyCamera myCamera;
	FBXFile* m_fbx;
	unsigned int m_programID;
	unsigned int m_texture;
	unsigned int m_normal;
	unsigned int m_VAO;
	unsigned int m_VBO;
	unsigned int m_IBO;
	float previous = 0;
	float current;
	float delta;
};