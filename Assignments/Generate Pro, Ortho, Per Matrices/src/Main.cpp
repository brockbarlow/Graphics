#include <iostream>

void genOrthographic(float, float, float, float, float, float, int**);
void genPerspective(float, float, float, float, int**);
int** createIdentity(int, int);

int rows = 4;
int cols = 4;

int main()
{
	int** identityMat = createIdentity(rows, cols);

	//            right left top bottom near far
	genOrthographic(5.f, 3.f, 7.f, 2.f, 1.f, 2.f, identityMat);
	//calls orthographic function

	//             fov        aspect      near   far
	genPerspective(1.f, (float)1080 / 720, 1.f, 2.f, identityMat);
	//calls perspective function

	system("pause");
	return 0;
}

int** createIdentity(int r, int c)
{
	int** identityMat = 0;

	identityMat = new int*[r];
	for (int i = 0; i < r; i++) {
		identityMat[i] = new int[c];
		for (int j = 0; j < c; j++) {
			identityMat[i][j] = (i == j);
		}
	}
	return identityMat;
}

//function that generates a orthographic matrix
void genOrthographic(float r, float l, float t, float b, float n, float f, int** idMat)
{
	//calculations formed from aie slides
	idMat[0][0] = 2 / (r - l);
	idMat[0][3] = -((r + l) / (r - l));
	idMat[1][1] = 2 / (t - b);
	idMat[1][3] = -((t + b) / (t - b));
	idMat[2][2] = -2 / (f - n);
	idMat[2][3] = -((f + n) / (f - n));
	idMat[3][3] = 1;

	//prints orthographic matrix
	for (int i = 0; i < 4; i++) {
		std::cout << "| ";
		for (int j = 0; j < 4; j++) {
			std::cout << idMat[i][j] << " | ";
			if (j == 3) {
				std::cout << "\n";
			}
		}
	}

	//blank space to read output better
	std::cout << std::endl;
}

//function that generates a perspective matrix
void genPerspective(float fov, float aspect, float n, float f, int** idMat)
{
	//calculations formed from aie slides
	idMat[0][0] = 1 / (aspect * (tan(fov / 2)));
	idMat[1][1] = 1 / (tan(fov / 2));
	idMat[2][2] = -((f + n) / (f - n));
	idMat[2][3] = -((2 * f * n) / (f - n));
	idMat[3][2] = -1;
	idMat[3][3] = 0;

	//prints perspective matrix
	for (int i = 0; i < 4; i++) {
		std::cout << "| ";
		for (int j = 0; j < 4; j++) {
			std::cout << idMat[i][j] << " | ";
			if (j == 3) {
				std::cout << "\n";
			}
		}
	}
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