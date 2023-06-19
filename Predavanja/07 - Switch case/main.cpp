#include <iostream>
using namespace std;

// Predavanje 7 - Switch, Function overloading, headeri, STL string

/*
Timestamps:
12:13 - if else / switch case
12:33 - function overloading
12:47 ---- setPosition putem struct
12:51 ---- SFML setPosition
12:53 ---- Razlika izmedu C++ i C# compilera za function overload ?
13:03 - Pauza 10 min (zadatak na satu: semafor sa if else i switch)
13:12 - Semafor zadatak
13:22 - Podjela klasa radi modularnosti (header za deklaracije), (.cpp za definicije)
14:16 - Overloading 2
14:21 - Pauza 15 min
14:37 - Stringovi
*/

// SWITCH case

enum class SpellType {
	FIRE,
	WATER,
	EARTH,
	WIND,
	UNDEAD
};

int main() {

	SpellType type_of_spell = SpellType::FIRE;

	// uvjetno grananje

	switch (type_of_spell) // u switch uvjet bude ono sto se ispituje i ciju vrijednost po granama testiramo (type of spell)
	{
	case SpellType::FIRE: // argument case-u je ona vrijednost koju testiramo
	{
		cout << "Napadam te vatrom!" << endl;
	}
	break;
	case SpellType::WATER:
	{
		cout << "Napadam te tsunamijem!" << endl;
	}
	break;
	case SpellType::EARTH:
	{
		cout << "Napadam te zemljotresom!" << endl;
	}
	break;
	case SpellType::WIND:
	{
		cout << "Napadam te tornadom!" << endl;
	}
	break;
	case SpellType::UNDEAD:
	{
		cout << "Napadam te čupakabarom!" << endl;
	}
	// u default se ulazi ako nijedna gore ne prode
	default:
		cout << "This shouldn't happen. We got a bug!" << endl;
		//send_error_report();
		//crash_app();
		break;
	}

	enum class BojaKarte {
		KARO, HERC, TREF, PIK
	};

	BojaKarte boja = BojaKarte::HERC;

	switch (boja)
	{
	case BojaKarte::KARO:
	case BojaKarte::HERC:
	{ cout << "Imam crvenu kartu." << endl; }
	break;
	case BojaKarte::TREF:
	case BojaKarte::PIK:
	{ cout << "Imam crnu kartu." << endl; }

	break;
	default:
		break;
	}

}
