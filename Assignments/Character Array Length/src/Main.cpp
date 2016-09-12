/*Write a function that calculates the length of a 
character array using only pointers. Pass that function 
as an argument to another function to evaluate it's 
correctness.

ex: char c[] = {"hello"}

ex 2: typedef (void*)Callback(char c[]);
      char c[] = "hello";
	  Invoke ((Callback)doit, c);
*/

#include <iostream>

void checkCalculation(int(*f)(char*), char* ex)
{
	std::cout << f(ex);
}

int calculateLength(char* c)
{
	char* p = &c[0];			
	int result = 0;		
	for (; *p != NULL; p++) {		
		result++;
	}
	return result;
}

int main()
{
	char c[] = { "Hello." };

	checkCalculation(calculateLength, c);

	system("pause");
	return 0;
}