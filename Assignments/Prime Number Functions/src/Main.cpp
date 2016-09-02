/*A prime number is a number greater than one that has no positive divisors
other than one and itself.*/

#include <iostream>

bool isPrime(const int &);
bool isMultiple(int);

const int under100 = 100;
const int under1000 = 1000;

int main()
{
	for (int i = 0; i < under100; i++) {
		if (isPrime(i)) {
			std::cout << i << " is prime." << std::endl;
		}
	}

	std::cout << std::endl;

	for (int i = 0; i < under1000; i++) {
		if (isPrime(i)) {
			std::cout << i << " is prime." << std::endl;
		}
	}

	system("pause");
	return 0;
}

bool isPrime(const int &num)
{
	if (isMultiple(num)) {
		return false;
	}
	return true;
}

bool isMultiple(int prime)
{
	for (int i = 2; i < prime; i++) {
		if (prime % i == 0) {
			return true;
		}
	}
	return false;
}