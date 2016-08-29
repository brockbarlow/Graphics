/*Write functions to generate projection matrices, orthographic and perspective view matrices. 
Try to do it without looking up the formula for orthographic.  
Think of the matrix and the box it makes, what type of parameters are required to make a cube 
and what are there positions relative to the matrix? Hint: 2/right - left is x*/

#include <iostream>

//function that generates a orthographic matrix
void genOrthographic(float r, float l, float t, float b, float n, float f)
{
	//matrix variable
	int matOrtho[4][4];
	
	//creates matrix
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matOrtho[i][j] = (i == j) ? 1 : 0;
		}
	}

	//calculations formed from aie slides
	matOrtho[0][0] = 2 / (r - l);
	matOrtho[0][3] = -((r + l) / (r - l));
	matOrtho[1][1] = 2 / (t - b);
	matOrtho[1][3] = -((t + b) / (t - b));
	matOrtho[2][2] = -2 / (f - n);
	matOrtho[2][3] = -((f + n) / (f - n));
	matOrtho[3][3] = 1;

	//prints orthographic matrix
	for (int i = 0; i < 4; i++) {
		std::cout << "| ";
		for (int j = 0; j < 4; j++) {
			std::cout << matOrtho[i][j] << " | ";
			if (j == 3) {
				std::cout << "\n";
			}
		}
	}

	//blank space to read output better
	std::cout << std::endl;
}

//function that generates a perspective matrix
void genPerspective(float fov, float aspect, float n, float f)
{
	//matrix variable
	int matPersp[4][4];

	//creates matrix
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matPersp[i][j] = (i == j) ? 1 : 0;
		}
	}

	//needs to be radians to calculate the scale 
	//for x and y axis in the transform.
	float radians = (fov * 3.14159265359) / 180;

	//calculations formed from aie slides
	matPersp[0][0] = 1 / (aspect * (tan(fov / 2)));
	matPersp[1][1] = 1 / (tan(fov / 2));
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
	//            right left top bottom near far
	genOrthographic(5.f, 3.f, 7.f, 2.f, 1.f, 2.f);
	//calls orthographic function

	//             fov        aspect      near   far
	genPerspective(1.f, (float)1080 / 720, 1.f, 2.f);
	//calls perspective function

	system("pause");
	return 0;
}

/*
Output for orthographic:
1|0|0|-4
0|0|0|-1
0|0|-2|-3
0|0|0|1

Output for perspective:
1|0|0|0
0|1|0|0
0|0|-3|-4
0|0|-1|0
*/