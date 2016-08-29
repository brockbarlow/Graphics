/*Write functions to generate projection matrices, orthographic and perspective view matrices. 
Try to do it without looking up the formula for orthographic.  
Think of the matrix and the box it makes, what type of parameters are required to make a cube 
and what are there positions relative to the matrix? Hint: 2/right - left is x*/

#include <iostream>

int** createIdentity(int rows, int cols)
{
	int** identityMat;
	identityMat = new int*[rows];

	for (int i = 0; i < rows; i++) {
		identityMat[i] = new int[cols];
		for (int j = 0; j < cols; j++) {
			identityMat[i][j] = (i == j) ? 1 : 0;
		}
	}

	return identityMat;
}

int genProjection()
{

	return 0;
}

int genOrthographic()
{

	return 0;
}

int genPerspective()
{

	return 0;
}

int main()
{
	int rows = 4;
	int cols = 4;

	int** identityMat = createIdentity(rows, cols);

	system("pause");
	return 0;
}