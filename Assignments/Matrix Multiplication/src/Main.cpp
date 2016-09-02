#include <iostream>

void multiply(int, int); //prototype

int main()
{
	int rows = 4; //how many rows matrix has
	int cols = 4; //how many columns matrix has

	multiply(rows, cols); //pass variables

	system("pause");
	return 0;
}

void multiply(int r, int c)
{
	int matA[4][4] = { { 5,3,1,3 },{ 4,4,4,4 },{ 7,8,4,2 },{ 2,2,2,2 } };
	int matB[4][4] = { { 1,2,3,4 },{ 4,5,6,7 },{ 7,8,9,10 },{ 10,11,12,13 } }; //matrices
	int matC[4][4] = { 0 };

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			for (int x = 0; x < 4; x++)  //muliply matrix a and b
			{
				matC[i][j] += matA[i][x] * matB[x][j];
			}
		}
	}

	for (int i = 0; i < 4; i++) {   //print matrix c
		std::cout << "| ";
		for (int j = 0; j < 4; j++) {
			std::cout << matC[i][j] << " | ";
			if (j == 3) {
				std::cout << "\n";
			}
		}
	}
}