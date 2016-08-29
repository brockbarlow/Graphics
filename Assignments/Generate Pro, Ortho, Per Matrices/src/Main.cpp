/*Write functions to generate projection matrices, orthographic and perspective view matrices. 
Try to do it without looking up the formula for orthographic.  
Think of the matrix and the box it makes, what type of parameters are required to make a cube 
and what are there positions relative to the matrix? Hint: 2/right - left is x*/

#include <iostream>

int genOrthographic(int r, int l, int t, int b, int n, int f)
{
	int matOrtho[4][4];
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matOrtho[i][j] = (i == j) ? 1 : 0;
		}
	}

	matOrtho[0][0] = 2 / r - l;
	matOrtho[0][3] = -(r + l / r - l);

	matOrtho[1][1] = 2 / t - b;
	matOrtho[1][3] = -(t + b / t - b);

	matOrtho[2][2] = -2 / f - n;
	matOrtho[2][3] = -(f + n / f - n);


	return matOrtho;
}

int genPerspective(int fov, int aspect, int n, int f)
{
	int matPersp[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matPersp[i][j] = (i == j) ? 1 : 0;
		}
	}

	//

	return matPersp;
}

int main()
{
	int newOrtho;
	int newPersp;

	newOrtho = genOrthographic();
	newPersp = genPerspective();

	for (int i = 0; i < 4; i++) {
		std::cout << "| ";
		for (int j = 0; j < 4; j++) {
			std::cout << newOrtho[i][j] << " | ";
			if (j == 3) {
				std::cout << "\n";
			}
		}
	}

	std::cout << std::endl;

	for (int i = 0; i < 4; i++) {
		std::cout << "| ";
		for (int j = 0; j < 4; j++) {
			std::cout << newPersp[i][j] << " | ";
			if (j == 3) {
				std::cout << "\n";
			}
		}
	}

	system("pause");
	return 0;
}