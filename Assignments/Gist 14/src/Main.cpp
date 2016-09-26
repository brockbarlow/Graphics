/*
Question 1: Distance from a Rectangle

We expect this question to take approximately 20-40 minutes.

Write a function that tests if a point falls within a 
specified distance (“dist”) of any part of a solid, 2D rectangle. 
The rectangle is specified by the bottom left corner, a width, 
and a height.

A function prototype and data structures you can assume exist 
are supplied below. You may make additions to the structures 
if you deem it appropriate. If you answer in a different language, 
you should follow a similar format:

struct Point
{
    float x;
    float y;
};

struct Rectangle
{
    Point bottomLeft;
    float width;
    float height;
};

bool IsPointWithinDistOfRectangle( const Rectangle& rect, const Point& point, float dist)
{
    // TODO: implement
}
*/

#include <iostream>

struct Point
{
	float x;
	float y;
};

struct Rectangle
{
	Point bottomLeft;
	float width; 
	float height; 
};

bool IsPointWithinDistOfRectangle(const Rectangle &rect, const Point &point, float dist)
{
	if (point.x <= (rect.bottomLeft.x + rect.width + dist) && point.x >= (rect.bottomLeft.x - dist))
	{
		if (point.y <= (rect.bottomLeft.y + rect.height + dist) && point.y >= (rect.bottomLeft.y - dist))
		{
			std::cout << "Point is within dist of rectangle.\n" << std::endl;
			return true;
		}
	}
	std::cout << "Error! Point is not within dist of rectangle.\n" << std::endl;
	return false;
}

int main()
{
	Point p;
	p.x = 0.0f;
	p.y = 0.0f;

	Point p_test;
	p_test.x = 10.0f;
	p_test.y = 10.0f;

	Rectangle r;
	r.bottomLeft = p;
	r.height = 5.0f;
	r.width = 5.0f;

	float dist = 5.0f;

	IsPointWithinDistOfRectangle(r, p_test, dist); //PASSED. Point is within range.

	/*This was to check if the function could fail.*/
	/////////////////////////////////////////////////////////////////////////////////////
	//p.x = 0.0f;
	//p.y = 0.0f;
	//
	//p_test.x = 25.0f;
	//p_test.y = 25.0f;
	//
	//r.bottomLeft = p;
	//r.height = 10.0f;
	//r.width = 10.0f;
	//
	//dist = 10.0f;
	//
	//IsPointWithinDistOfRectangle(r, p_test, dist); //PASSED. Point is not within range.
	/////////////////////////////////////////////////////////////////////////////////////

	system("pause");
	return 0;
}