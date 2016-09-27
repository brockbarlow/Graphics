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
	Weapon() {}
	float minDamage;
	float maxDamage;
	float speed;
};

class HandGun : public Weapon {};
class ShotGun : public Weapon {};
class SniperRifle : public Weapon {};
class FatMan : public Weapon {};
class SubMachineGun : public Weapon {};

float GetDPS(Weapon w)
{           
	return ((w.minDamage + w.maxDamage) / 2) / w.speed;
}

int main()
{
	HandGun h;
	h.minDamage = 12.0f;
	h.maxDamage = 18.0f;
	h.speed = 3.25f;

	ShotGun s;
	s.minDamage = 22.0f;
	s.maxDamage = 36.0f;
	s.speed = 2.09f;

	SniperRifle sr;
	sr.minDamage = 52.0f;
	sr.maxDamage = 75.0f;
	sr.speed = 1.18f;

	FatMan f;
	f.minDamage = 175.0f;
	f.maxDamage = 268.0f;
	f.speed = 0.38f;

	SubMachineGun smg;
	smg.minDamage = 11.0f;
	smg.maxDamage = 15.0f;
	smg.speed = 5.85f;

	float temp_H = round(GetDPS(h) * 100) / 100;
	float temp_S = round(GetDPS(s) * 100) / 100;
	float temp_SR = round(GetDPS(sr) * 100) / 100;
	float temp_F = round(GetDPS(f) * 100) / 100;
	float temp_SMG = round(GetDPS(smg) * 100) / 100;

	std::cout << "Handgun DPS is: " << temp_H << std::endl;
	std::cout << "Shotgun DPS is: " << temp_S << std::endl;
	std::cout << "Sniper Rigle DPS is: " << temp_SR << std::endl;
	std::cout << "Fatman DPS is: " << temp_F << std::endl;
	std::cout << "Sub Machinegun DPS is: " << temp_SMG << std::endl;
	std::cout << std::endl;

	system("pause");
	return 0;
}