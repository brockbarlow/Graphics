/*Write a function that takes a function as a parameter. 
The function it receives should take two arguments (min,max). 
Calculate a random number between those two numbers and 
return it. If the function fails return or assert on the 
call. If the function that takes the min,max function 
fails give feedback to the user.*/

#include <iostream>
#include <assert.h>

int calculate(int max, int min)
{
	assert(min >= max && "Error! Min is greater!");
}

void takeParameter(int(*function)())
{

}

int main()
{
	int max, min = 0;

	std::cout << "Enter max." << std::endl;
	std::cin >> max;
	std::cout << "Enter min." << std::endl;
	std::cin >> min;

	calculate(max, min);
	takeParameter(calculate);

	system("pause");
	return 0;
}