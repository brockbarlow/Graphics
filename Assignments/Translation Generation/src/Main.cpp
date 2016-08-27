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

	return identityMat;
}

void performTranslate(int** identityMat)
{
	int matA[4] = {5,3,2,1};
	int translatedMat[4][4];

	////////////////////////////////////////////////////////////////////
	/*for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int x = 0; x < 4; x++) {
				translatedMat[i][j] = identityMat[i][x] * matA[x];
			}                                                     
		}                                                         
	}
	                                                              
	for (int i = 0; i < 4; i++) {
		cout << *translatedMat[i] << " ";                         
	}*/
	////////////////////////////////////////////////////////////////////

	translatedMat[0][0] = identityMat[0][0] * matA[0] + identityMat[0][1] * matA[1] + identityMat[0][2] * matA[2] + identityMat[0][3] * matA[3];
	translatedMat[1][0] = identityMat[1][0] * matA[0] + identityMat[1][1] * matA[1] + identityMat[1][2] * matA[2] + identityMat[1][3] * matA[3];
	translatedMat[2][0] = identityMat[2][0] * matA[0] + identityMat[2][1] * matA[1] + identityMat[2][2] * matA[2] + identityMat[2][3] * matA[3];
	translatedMat[3][0] = identityMat[3][0] * matA[0] + identityMat[3][1] * matA[1] + identityMat[3][2] * matA[2] + identityMat[3][3] * matA[3];

	for (int i = 0; i < 4; i++) {
		cout << *translatedMat[i] << " ";
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