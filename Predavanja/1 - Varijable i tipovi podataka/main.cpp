#include <iostream>
#include <fstream>
using namespace std;

// PREDAVANJE 1 - Uvod u arhitekturu racunala, tipovi podataka, varijable

// Ovo je funkcija main
int predavanje1() {
	int pin;
	std::cout << "Unesi PIN" << std::endl;
	std::cin >> pin;

	if (pin == 1234)
		std::cout << "PIN je ispravan" << std::endl;
	else
		std::cout << "Pogrešan pin!" << std::endl;
	//return 0;  // int mora imati neki return value

	int broj;
	std::cout << "Unesi neki broj : ";
	std::cin >> broj;
	std::cout << "Unijeli ste broj : ";
	std::cout << broj;

	// Varijable
	// Deklaracija varijable gramatički: TYPE NAME;
	int broj = 65;
	int broj2 = 66;
	int broj3 = 75;

	std::cout
		<< (char)broj
		<< (char)broj2
		<< (char)broj3
		<< std::endl;

	// char varijabla = VRIJEDNOST;  // inicijalizer daje pocetno stanje kutiji, else its ?
	// char broj = 67;
	// unsigned int broj14 = -5; // (0 , 4 mlr)
	// int broj11 = 67; // (-2 mlrd, 2 mlrd)
	// int broj3 = 10 + 2; try 10 % 3 // modulo

	return 0;
}
