/*Write a function that takes another function as an argument.
Store this argument in an array.
Then execute every function in the array.
This is gist 5*/

#include <iostream>

void argumentOne()
{
	std::cout << "argument function one" << std::endl;
	std::cout << std::endl;
}

void argumentTwo()
{
	int num1, num2, answer;

	answer = num1 + num2;

	std::cout << answer << std::endl;
}

int main()
{

	system("pause");
	return 0;
}