/*Write a function that takes a function as a parameter. 
The function it receives should take two arguments (min,max). 
Calculate a random number between those two numbers and 
return it. If the function fails return or assert on the 
call. If the function that takes the min,max function 
fails give feedback to the user.*/

#include <iostream>

int calculate(int max, int min)
{
	int ran;
	std::cout << "enter random.";
	std::cin >> ran;


}

void takeParameter(int(*function)())
{

}

int main()
{
	int max, min;

	std::cout << "enter max.";
	std::cin >> max;
	std::cout << "enter min.";
	std::cin >> min;

	calculate(max, min);
	takeParameter(calculate);

	system("pause");
	return 0;
}