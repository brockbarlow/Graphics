/*Write a program that generates a matrix translation for any identity matrix. 
For example, what is the resulting matrix when the transformation of [5,3,2,1] is applied 
to the identity? This should work for any arbitrary matrix*/

#include <iostream>
using namespace std;

int** createIdentity(int rows, int cols)
{
	int** identityMat;
	identityMat = new int*[rows];

	for (int i = 0; i < rows; i++) {
		identityMat[i] = new int[cols];
		for (int j = 0; j < cols; j++) {
			identityMat[i][j] = (i == j) ? 1 : 0;
		}
	}

	//double offset = sqrt(rows * cols) - 1;

	/*for (int i = 0; i < rows; i++) {
		cout << "| ";
		for (int j = 0; j < cols; j++) {
			cout << identityMat[i][j] << " | ";
			if (j == 3) {
				cout << "\n";
			}
		}
	}*/

	return identityMat;
}

void performTranslate()
{

}

int main()
{
	int rows = 4;
	int cols = 4;

	int** identityMat = createIdentity(rows, cols);
	//performTranslate(identityMat);

	system("pause");
	return 0;
}