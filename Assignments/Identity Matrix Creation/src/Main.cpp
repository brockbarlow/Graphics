#include <iostream>

void createIdentity(int, int); //prototype

int rows, cols; //size of matrix. user defined

int main()
{
	std::cout << "Enter rows and columns" << "\n" << std::endl;
	
	std::cout << "Rows: ";
	std::cin >> rows; //user input data

	std::cout << "Columns: ";
	std::cin >> cols; //user input data
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
		identityMat[i] = new int[c];      //create matrix
		for (int j = 0; j < c; j++)
		{
			identityMat[i][j] = (i == j);
		}
	}

	for (int i = 0; i < r; i++) {   //print matrix
		std::cout << "| ";
		for (int j = 0; j < c; j++) {
			std::cout << identityMat[i][j] << " | ";
		}
	}
}

/*Test Case One:

User inputs 3, 3 (3 rows and 3 columns).

Test Result:
identityMat = {{1,0,0}, {0,1,0}, {0,0,1}}

Test Case Two:

User inputs 4, 4 (4 rows and 4 columns).

Test Result:
identityMat = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}}
*/