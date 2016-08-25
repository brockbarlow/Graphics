/*Write a program that multiplies two 4x4 matrices and returns 1 matrix*/

#include <iostream>
using namespace std;

int main()
{
	int matA[4][4] = { { 5,3,1,3 },{ 4,4,4,4 },{ 7,8,4,2 },{ 2,2,2,2 } };
	int matB[4][4] = { { 1,2,3,4 },{ 4,5,6,7 },{ 7,8,9,10 },{ 10,11,12,13 } };
	int matC[4][4] = { 0 };

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int x = 0; x < 4; x++) {
				matC[i][j] += matA[i][x] * matB[x][j];
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		cout << "| ";
		for (int j = 0; j < 4; j++) {
			cout << matC[i][j] << " | ";
			if (j == 3) {
				cout << "\n";
			}
		}
	}

	system("pause");
	return 0;
}