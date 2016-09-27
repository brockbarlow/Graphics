/*
Question: Weapon DPS

We expect this question to take approximately 30-45 minutes.
Write a function that calculates the damage per second of a given weapon.

Requirements: Function must take a parameter of type that inherits from Weapon.
Return value must be to the nearest second decimal place. Ex: 35.6
You may make additions to the structures if you deem it appropriate.

class Weapon
{
}

float GetDps(Weapon w)
{
}
*/

#include <iostream>

class Weapon
{
public:
	Weapon()
	{

	}
};

class Handgun : public Weapon
{

};

class Shotgun : public Weapon
{

};

class Rifle : public Weapon
{

};

float GetDPS(Weapon w)
{

}

int main()
{


	system("pause");
	return 0;
}