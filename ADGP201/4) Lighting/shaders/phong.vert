// // classic Phong equation
#version 410

layout(location=0) in vec4 position;
layout(location=2) in vec4 normal;

out vec4 vPosition;
out vec4 vNormal;

uniform mat4 ProjectionViewModel;
uniform mat4 ModelMatrix;
uniform mat4 NormalMatrix;

void main()
{
	vPosition = ModelMatrix * position;
	vNormal = NormalMatrix * normal;

	gl_Position = ProjectionViewModel * position;
}