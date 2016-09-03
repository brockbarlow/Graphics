#include <iostream>

void argumentOne();
void argumentTwo();  //prototypes
void argumentThree();

void storeFunctions(void(*function)(), void(*array[3])())
{
	for (int i = 0; i < 3; i++) {
		if (array[i] == 0) {          //adds functions into array
			array[i] = function;
			break;
		}
	}
}

void(*container[3])() = { 0,0,0 }; //void variable array of size three

int main()
{
	storeFunctions(argumentOne, container);
	storeFunctions(argumentTwo, container);   //call container function to add functions to the array
	storeFunctions(argumentThree, container);

	for (int i = 0; i < 3; i++) { //perform functions in array
		(*container[i])();
	}

	system("pause");
	return 0;
}

void argumentOne()
{
	int numOne = 1;
	int numTwo = 2;  //add function
	int answer = 0;

	answer = numOne + numTwo;
	std::cout << answer << std::endl;
}

void argumentTwo()
{
	float numOne = 1.5f;
	float numTwo = 6.3f;  //mulitply function
	float answer = 0.0f;

	answer = numOne * numTwo;
	std::cout << answer << std::endl;
}

void argumentThree()  //print something function
{
	std::cout << "Functions, functions everywhere..." << std::endl;
}