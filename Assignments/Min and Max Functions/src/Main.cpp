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
	std::cout << "Passed test check... \n";

	/*Test case for assert:
	max = 1, min = 2
	code will pass.

	max = 2, min = 1
	program will freak out and ask to abort.
	*/

	//my calculation for random number.
	int ranNum = 0;
	ranNum = max / min;
	return ranNum;
}

//void takeParameter(int(*function)(int max, int min))
//{
//
//}

int main()
{
	int max, min = 0;

	std::cout << "Enter max." << std::endl;
	std::cin >> max;
	std::cout << "Enter min." << std::endl;
	std::cin >> min;

	calculate(max, min);
	//takeParameter(calculate);

	system("pause");
	return 0;
}

/*
Things that I understood about assignment:
1) create functions.
2) have functions take arguments.

Problems with assignment:
1) Had trouble passing a function to another function as
   a parameter.
2) Never used assert before (refer to test case in function).
3) Didn't understand how calculation needed to be performed
   for calculate function.
4) Didn't understand how to perform fail check for the
   function taking a function parameter.
*/