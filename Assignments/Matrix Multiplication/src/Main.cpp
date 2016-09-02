#include <iostream>

void multiply(int, int); //prototype function

int rows = 4; //how many rows matrix has
int cols = 4; //how many columns matrix has

int main()
{
	multiply(rows, cols); //pass variables

	system("pause");
	return 0;
}

void multiply(int r, int c)
{
	int** matA = 0;
	int** matB = 0;            //matrices
	int matC[4][4] = { 0 };

	matA = new int*[r];             //create matrix a
	for (int i = 0; i < r; i++) {
		matA[i] = new int[c];
		for (int j = 0; j < c; j++) {
			std::cin >> matA[i][j];
		}
	}

	matB = new int*[r];            //create matrix b
	for (int i = 0; i < r; i++) {
		matB[i] = new int[c];
		for (int j = 0; j < c; j++) {
			std::cin >> matB[i][j];
		}
	}
	
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

/*Test Case:

Test data for matrix a:
{ { 5,3,1,3 },{ 4,4,4,4 },{ 7,8,4,2 },{ 2,2,2,2 } }

Test data for matrix b:
{ { 1,2,3,4 },{ 4,5,6,7 },{ 7,8,9,10 },{ 10,11,12,13 } }

Test Result:
matrix c will equal: { {54, 66, 78, 90}, {88, 104, 120, 136}, {87, 108, 129, 150}, {44, 52, 60, 68} }
*/