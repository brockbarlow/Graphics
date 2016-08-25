/*Write a c++ program that creates the identity matrix. 
When they are done, run it from the desktop and output it.*/

#include <iostream>
using namespace std;

void createIdentity()
{
	int identityMat[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			identityMat[i][j] = (i == j) ? 1 : 0;
		}
	}

	for (int i = 0; i < 4; i++) {
		cout << "| ";
		for (int j = 0; j < 4; j++) {
			cout << identityMat[i][j] << " | ";
			if (j == 3) {
				cout << "\n";
			}
		}
	}
}

int main()
{
	createIdentity();
	cout << "\n" << endl;

	system("pause");
	return 0;
}