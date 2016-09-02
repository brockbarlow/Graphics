#include <iostream>

void createIdentity(int, int);

int main()
{
	int rows, cols;

	std::cout << "Enter rows and columns" << "\n" << std::endl;
	
	std::cout << "Rows: ";
	std::cin >> rows;

	std::cout << "Columns: ";
	std::cin >> cols;
	std::cout << "\n" << std::endl;
	 
	createIdentity(rows, cols);
	std::cout << "\n" << std::endl;

	system("pause");
	return 0;
}

void createIdentity(int r, int c)
{
	int** identityMat = 0;

	identityMat = new int*[r];

	for (int i = 0; i < r; i++)
	{
		identityMat[i] = new int[c];
		for (int j = 0; j < c; j++)
		{
			identityMat[i][j] = (i == j);
		}
	}

	for (int i = 0; i < r; i++) {
		std::cout << "| ";
		for (int j = 0; j < c; j++) {
			std::cout << identityMat[i][j] << " | ";
		}
	}
}