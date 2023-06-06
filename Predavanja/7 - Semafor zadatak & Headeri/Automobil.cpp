#include "Automobil.h"
#include <iostream>

void Automobil::vozi()
{
	std::cout << "Automobil vozi.\n";
}

void Automobil::skreni(int kut)
{
	std::cout << "Automobil skreće za kut: " << kut << " stupnjeva.\n";
}

void Automobil::koci()
{
	std::cout << "Automobil koči.\n";
}

void Automobil::upali_motor()
{
	std::cout << "Motor je upaljen.\n";
}