#include <iostream>
using namespace std;

// Predavanje 7 - Function overloading, switch, headeri, STL string

/*
* Timestamps:
12:13 - switch-case
12:33 - Function overloading
13:12 - Zadatak: semafor
13:22 - Podjela klasa radi modularnosti (header za deklaracije, source za definicije)
14:16 - Function overloading (nast.)
14:37 - STL string
*/


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
		cout << "Napadam te vatrom!" << endl;
	}
	break;
	case SpellType::WIND:
	{
		cout << "Napadam te tsunamijem!" << endl;
	}
	break;
	case SpellType::UNDEAD: 
	{
		cout << "Napadam te tsunamijem!" << endl;
	}
	// u default se ulazi ako nijedna gore ne prode
	default:
		cout << "This shouldn't happen. We got a bug!" << endl;
		//send_error_report();
		//crash_app();
		break;
	}
}
