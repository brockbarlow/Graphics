#include <iostream>

int** createIdentity(int rows, int cols)
{
	int** identityMat;
	identityMat = new int*[rows];

	for (int i = 0; i < rows; i++) {
		identityMat[i] = new int[cols];
		for (int j = 0; j < cols; j++) {
			identityMat[i][j] = (i == j);
		}
	}

	return identityMat;
}

void performTranslate(int** identityMat)
{
	int matA[4] = {5,3,2,1};
	int translatedMat[4][4];

	translatedMat[0][0] = identityMat[0][0] * matA[0] + identityMat[0][1] * matA[1] + identityMat[0][2] * matA[2] + identityMat[0][3] * matA[3];
	translatedMat[1][0] = identityMat[1][0] * matA[0] + identityMat[1][1] * matA[1] + identityMat[1][2] * matA[2] + identityMat[1][3] * matA[3];
	translatedMat[2][0] = identityMat[2][0] * matA[0] + identityMat[2][1] * matA[1] + identityMat[2][2] * matA[2] + identityMat[2][3] * matA[3];
	translatedMat[3][0] = identityMat[3][0] * matA[0] + identityMat[3][1] * matA[1] + identityMat[3][2] * matA[2] + identityMat[3][3] * matA[3];

	for (int i = 0; i < 4; i++) {
		std::cout << *translatedMat[i] << " ";
	}
}

int main()
{
	int rows = 4;
	int cols = 4;

	int** identityMat = createIdentity(rows, cols);
	performTranslate(identityMat);

	system("pause");
	return 0;
}