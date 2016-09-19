/*Write a function that multiplies two numbers. 
You can only use addition or subtraction and you can only 
check whether a number is positive, negative or 0. You can 
not use >, >=, <, or <=. Return and parameters are unsigned 
integers. Ex: Uint mult(uint x1, uint x2){}*/

#include <iostream>

unsigned int multiply(unsigned int num1, unsigned int num2)
{
	unsigned int value = 0;

	while (num2 != 0)
	{
		value = value + num1;
		num2--;
	}

	return value;
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

Possible solution to Problem 1:
Instead of using >, >=, <, and <=, we could use:
!>, !>=, !<, !<=, ==, = and !=.

Problem 2:
Confused about question. We need a multiply function, but
we can only addition and subtraction?

Possible solution to Problem 2:
Use a while loop to check if the second number doesn't
equal zero. Take the value variable and number one variable
and add them. Then decrement the second number.

Side Note:
Unsigned ints are always positive. If unsigned ints
become negative, program will throw a compile error or
will not fully function, so we don't need to check for
negative values. Since uints are always positive, we 
don't need to check if the values are positive. So for 
this gist, we just need to check for zero.
*/