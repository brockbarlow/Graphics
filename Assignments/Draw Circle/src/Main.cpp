/*
Write a function that takes arguments to create a 
half circle. Parameters should be a radius number of 
points and the return value should be the half circle.

If you want to pass by ref that is fine too.

This function should be tested and done on paper first. 
Prove your answer for a set amount of points.
*/

#include <iostream>
#include <cmath>

struct vec3
{
	float x;
	float y;
	float z;
};

float halfCircle(float np, float rad)
{
	float pi = 3.14159265359f;
	vec3 vertex[5];
	float angle;

	for (int i = 0; i < np - 1; i++)
	{
		angle = pi * (i / (np - 1));
		vertex[i].x = rad + cos(angle);
		vertex[i].y = rad + sin(angle);
		vertex[i].z = 0;
	}
	return 0;
}

int main()
{
	float points = 5;
	float rads = 1;

	halfCircle(points, rads);

	system("pause");
	return 0;
}