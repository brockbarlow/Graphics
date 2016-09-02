#include <iostream>

void createIdentity(int, int);

int main()
{
	int rows, cols;

	std::cout << "Enter rows and columns" << std::endl;
	
	std::cout << "Rows:" << std::endl;
	std::cin >> rows;

	std::cout << "Columns:" << std::endl;
	std::cin >> cols;

	createIdentity(rows, cols);
	std::cout << "\n" << std::endl;

	system("pause");
	return 0;
}

void createIdentity(int r, int c)
{
	int identityMat[4][4] = { 0 };

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			identityMat[i][j] = (i == j);
		}
	}

	for (int i = 0; i < 4; i++) {
		std::cout << "| ";
		for (int j = 0; j < 4; j++) {
			std::cout << identityMat[i][j] << " | ";
			if (j == 3) {
				std::cout << "\n";
			}
		}
	}
}