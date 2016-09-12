/*The passed function can not be overloaded when being
called with callFunc. Trying to do so will give an 
"too many arguments" error. However, when calling the 
addFunc by itself, it is possible to overload it.*/

#include <iostream>

int addFunc(const int, const int); //prototypes.
int addFunc(const int, const int, const int);

void callFunc(int(*function)(const int, const int), const int a, const int b)
{
	std::cout << function(a, b) << std::endl;
}

int main()
{
	const int num1 = 2;
	const int num2 = 4; //Test numbers.
	const int num3 = 9;

	//callFunc(addFunc, num1, num2); //This will print out 6.
	//callFunc(addFunc, num1, num2, num3); //Error! Too many arguments.

	addFunc(num1, num2); //this function will return the answer 6.
	addFunc(num1, num2, num3); //calling addFunc again with a new const int, the answer will change to 15.

	system("pause");
	return 0;
}

int addFunc(const int a, const int b)
{
	int answer = 0;
	answer = a + b;
	std::cout << answer << std::endl; //prints out 6.
	return answer;
}

int addFunc(const int a, const int b, const int c)
{
	int answer = 0;
	answer = a + b + c;
	std::cout << answer << std::endl; //prints out 15.
	return answer;
}