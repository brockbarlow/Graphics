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

	...I don't understand.
	*/

	//my calculation for random number.
	int ranNum = 0;
	ranNum = max / min;
	return ranNum;
}

void takeParameter(int(*function)(int max, int min))
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

/*
Things that I understood about assignment:
1) Create functions.
2) Have functions take arguments.
3) Understand the "function takes a function parameter"
   concept.
4) Understood that the calculate function needs to return
   something.

Problems with assignment:
1) Had trouble passing a function to another function as
   a parameter.
2) Never used assert before (refer to test case in 
   calculate function).
3) Didn't understand how calculation needed to be performed
   for calculate function.
4) Didn't understand how to perform fail check for the
   function taking a function parameter.
*/