/*Create a function to calculate a prime number (Show on 
paper or in comments what you think a prime number is. Do 
not google it...). 

Write a function that uses that function to find all prime 
numbers under 100.

Write a function that determines if a number is a multiple 
of another number. 

Use your functions together to find all prime numbers below 
1000.
*/

#include <iostream>

int isPrime(const int num)
{
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return num;
}

void isMultiple()
{

}

void calculate()
{
	const int under100 = 100;
	const int under1000 = 1000;
	int temp;

	for (int i = 2; i < under100; i++)
	{
		temp = isPrime(i);
		std::cout << temp << std::endl;
	}
}

int main()
{
	calculate();

	system("pause");
	return 0;
}

/*A prime number is a number greater than one that has
no positive divisors other than one and itself.*/