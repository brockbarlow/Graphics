/*Write functions to generate projection matrices, orthographic and perspective view matrices. 
Try to do it without looking up the formula for orthographic.  
Think of the matrix and the box it makes, what type of parameters are required to make a cube 
and what are there positions relative to the matrix? Hint: 2/right - left is x*/

#include <iostream>

int genOrthographic(int m, int r, int l, int t, int b, int n, int f)
{
	int matOrtho[4][4] = {0};


	return matOrtho;
}

int genPerspective(int m, int fov, int aspect, int n, int f)
{
	int matPersp;


	return matPersp;
}

int main()
{
	int matA;

	//genOrthographic(matA);
	//genPerspective(matA);

	system("pause");
	return 0;
}