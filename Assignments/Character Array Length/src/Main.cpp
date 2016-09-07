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

typedef int(*pointer)(const char* c);

bool checkCalculation(int pointer, int size)
{
	//assert(pointer == size && "Error! ");

	/*if (pointer == size)
	{
		return true;
	}
	else
	{
		return false;
	}*/
}

int calculateLength(const char* c)
{

}

int main()
{
	const char* c = { "Hello." };

	//checkCalculation(calculateLength(c));

	system("pause");
	return 0;
}