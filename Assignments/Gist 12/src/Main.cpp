/*Write a function that multiplies two numbers. 
You can only use addition or subtraction and you can only 
check whether a number is positive, negative or 0. You can 
not use >, >=, <, or <=. Return and parameters are unsigned 
integers. Ex: Uint mult(uint x1, uint x2){}*/

#include <iostream>

unsigned int multiply(unsigned int num1, unsigned int num2)
{

}

int main()
{
	unsigned int num1, num2, returnedValue;

	std::cout << "Enter number one: " << std::endl;
	std::cin >> num1;
	std::cout << "Enter number two: " << std::endl;
	std::cin >> num2;

	returnedValue = multiply(num1, num2);
	std::cout << returnedValue << std::endl;


	system("pause");
	return 0;
}

/*
Problem 1:
How is it possible to check if a number is positive,
negative or zero without using >, >=, <, <=?
*/