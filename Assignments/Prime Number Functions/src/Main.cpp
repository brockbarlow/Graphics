/*Create a function to calculate a prime number 
(Show on paper or in comments what you think a prime 
number is. Do not google it...). 
Write a function that uses that function to find all 
prime numbers under 100.
Write a function that determines if a number is a 
multiple of another number. 
Use your functions together to find all prime numbers 
below 1000.
*/

#include <iostream>

void calculatePrime()
{
	/*for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			std::cout << "number is not prime" << std::endl;
			break;
		}
		else if (num % i != 0)
		{
			std::cout << "number is prime" << std::endl;
			break;
		}
	}*/
}

void findUnder100()
{
	for (int i = 2; i < 100; i++)
	{
		bool prime = true;
		for (int j = 2; j * j <= i; j++)
		{
			if (i % j == 0)
			{
				prime = false;
				break;
			}
		}
		if (prime)
		{
			std::cout << i << " " << std::endl;
		}
	}
}

void determineMultiple()
{

}

void findUnder1000()
{
	for (int i = 2; i < 1000; i++)
	{
		bool prime = true;
		for (int j = 2; j * j <= i; j++)
		{
			if (i % j == 0)
			{
				prime = false;
				break;
			}
		}
		if (prime)
		{
			std::cout << i << " " << std::endl;
		}
	}
}

int main()
{
	//int num;
	//std::cout << "Enter number:" << std::endl;
	//std::cin >> num;
	calculatePrime();

	system("pause");
	return 0;
}

/*A prime number is a number greater than one that has
no positive divisors other than one and itself.*/

/*Was able to complete Part 1 of assignment.*/