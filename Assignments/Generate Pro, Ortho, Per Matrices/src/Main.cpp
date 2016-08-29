/*Write functions to generate projection matrices, orthographic and perspective view matrices. 
Try to do it without looking up the formula for orthographic.  
Think of the matrix and the box it makes, what type of parameters are required to make a cube 
and what are there positions relative to the matrix? Hint: 2/right - left is x*/

#include <iostream>

void genOrthographic(float r, float l, float t, float b, float n, float f)
{
	int matOrtho[4][4];
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matOrtho[i][j] = (i == j) ? 1 : 0;
		}
	}

	matOrtho[0][0] = 2 / r - l;
	matOrtho[0][3] = -((r + l) / (r - l));
	
	matOrtho[1][1] = 2 / t - b;
	matOrtho[1][3] = -((t + b) / (t - b));
	
	matOrtho[2][2] = -2 / f - n;
	matOrtho[2][3] = -((f + n) / (f - n));
	
	matOrtho[3][3] = 1;

	for (int i = 0; i < 4; i++) {
		std::cout << "| ";
		for (int j = 0; j < 4; j++) {
			std::cout << matOrtho[i][j] << " | ";
			if (j == 3) {
				std::cout << "\n";
			}
		}
	}

	std::cout << std::endl;
}

void genPerspective(float fov, float aspect, float n, float f)
{
	int matPersp[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matPersp[i][j] = (i == j) ? 1 : 0;
		}
	}

	float radians = (fov * 3.14159265359) / 180;

	//calculations formed from aie slides
	matPersp[0][0] = 1 / (aspect * (tan(fov / 2)));
	matPersp[1][1] = 1 / tan(fov / 2);
	matPersp[2][2] = -((f + n) / (f - n));
	matPersp[2][3] = -((2 * f * n) / (f - n));
	matPersp[3][2] = -1;
	matPersp[3][3] = 0;

	//prints perspective matrix
	for (int i = 0; i < 4; i++) {
		std::cout << "| ";
		for (int j = 0; j < 4; j++) {
			std::cout << matPersp[i][j] << " | ";
			if (j == 3) {
				std::cout << "\n";
			}
		}
	}
}

int main()
{
	//              r    l    t    b    n    f
	genOrthographic(5.f, 3.f, 7.f, 2.f, 1.f, 2.f);
	
	//             fov        aspect        n    f
	genPerspective(1.f, (float)1920 / 1080, 5.f, 7.f);

	system("pause");
	return 0;
}