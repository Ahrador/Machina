#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

// Predavanje 5 - Objekti i klase te setter & getter
// Rekurzija
// stack overflow se dogodi kada funkcija pozove samu sebe.
// anti pattern (ne koristiti inace) = rekurzija, globalne varijable, go to naredba...
void rekurzija() {
	rekurzija();
}

// Faktorijal nekog broja
unsigned faktorijal(unsigned broj) {  // unsigned int je 0-4 milijarde
	if (broj == 0)
		return 1;
	
	return broj* faktorijal(broj - 1);
}

// Zasto se stack overflow desava? javlja se kada je količina podataka koju program pohranjuje na stogu veća od dostupnog prostora na stogu. Memorija ima dva segmenta, stack i heap.
// Svrha stacka je da pamti operativne podatke - tipa kolko velik niz moze bit, tu idu lokalne varijable
/*
Stack se koristi za čuvanje lokalnih varijabli i konteksta izvođenja funkcija, 
dok se heap koristi za dinamičku alokaciju memorije za objekte i polja. 
Stack ima ograničenu veličinu i automatsko upravljanje memorijom, dok heap 
može biti veći i zahtijeva ručno upravljanje memorijom.
*/
 

// Unutar funkcije mozemo napraviti isto sto i u mainu
int main() {
//rekurzija();
	
// cout << faktorijal(6);
for (int i = 0; i < 10; i++)
	cout << "Faktorijal broja " << i << " je " << faktorijal(i) << endl;
}

//--------------------------------------------------------------------------

// Objekti  (od 13:40)
// user defined data types
// varijable --- data, opis, osobine
// funkcije --- ponasanje 

// U C++ objekti se definiraju sa:  class, struct ili union.
// Klase imaju vitičaste zagrade u koje idu elementi.

// Definicija klase (šablona)
class Ucenik {
public:
// private (by default):
	string ime_ucenika;  // Ime ucenika
	int datum_rodenja_ucenika;  // Datum rodenja
	int ocjena_math; // Ocjena iz matematike
	int ocjena_history; // Ocjena iz povijesti
	float prosjek() {}
	//Image slika;

// Funkcija za prikaz informacija o uceniku (šablona)
	void prikaz_info_o_uceniku() {
		cout << "Ime ucenika: " << ime_ucenika << endl;
		cout << "Datum rodenja: " << datum_rodenja_ucenika << endl;
		cout << "Ocjena iz matematike: " << ocjena_math << endl;
		cout << "Ocjena iz povijesti: " << ocjena_history << endl;
	}

	// Getter i Setter
public:
	int get_ocjena_math() { return ocjena_math; }
	void set_ocjena_math(int new_value) {
		ocjena_math = new_value;
	}
};


/*
Razlika izmedu class i struct:
- vidljivost:  class = private, struct = public	
- Nasljeđivanje:  class = private, struct = public	
- Upotreba:  Klase za definiranje složenih objekata s internim stanjem 
(privatnim članovima) i javnim sučeljem (javne metode). 
Strukture za definiranje jednostavnih grupa podataka koje nemaju složeno ponašanje.
*/

int main() {
	// member access operator je '.'
	// Stvaranje objekta klase Ucenik

	Ucenik ucenik1;

	// Postavljanje vrijednosti 
	ucenik1.ime_ucenika = "Alen";
	ucenik1.datum_rodenja_ucenika = 13'06'1991;
	ucenik1.ocjena_math = 4;
	ucenik1.ocjena_history = 5;

	// Prikaz informacija 
	//ucenik1.prikaz_info_o_uceniku();
	ucenik1.get_ocjena_math();

//--------------------------------------------------------------------------------

// Drugi primjer, koji se koristi u industriji
class Accessory {
	int damage_reduction;
public:
	bool hasDamageReduction() { return damage_reduction != 0; }
	int getDamageReduction() {
		return damage_reduction;
	}
};

class Hero {
	int HP;
	int fire_reduction = 0.5;
	int water_reduction = -0.5;
	Accessory items[10];
public:
	void takeDamage(int value, int spell_type) {
		// transform damage value before applying damage
		if (spell_type == 3)
			value = value * fire_reduction;
		else if (spell_type == 4)
			value = value * water_reduction;
		else

			// do accessories do any damage reduction?
			if (items[0].hasDamageReduction)
				value = value * items[0]getDamageReduction();

		HP -= value;
	}
	void AddAccessory(Accessory new_item, int slot) {
		items[5] = new_item;
	}
};

//----------------------------------------------------------------------

// Enumi

struct Semafor {

	enum class StanjeNaSemaforu { // moze bit izvan struc Semafor, less code
	CRVENO,
	ZELENO,
	ŽUTO,
	CRVENO_ZUTO	
	};

	StanjeNaSemaforu stanje_na_semaforu = StanjeNaSemaforu::CRVENO;
	void setStanje(StanjeNaSemaforu newState) {
		stanje_na_semaforu = newState;
	}
	
	void printStanje() {
		if (stanje_na_semaforu == StanjeNaSemaforu::CRVENO)
			cout << "Na semaforu je crveno svjetlo" << endl;
		if (stanje_na_semaforu == StanjeNaSemaforu::ZELENO)
			cout << "Na semaforu je zeleno svjetlo" << endl;
		if (stanje_na_semaforu == StanjeNaSemaforu::CRVENO_ZUTO)
			cout << "Na semaforu je crveno+zuto svjetlo" << endl;
		if (stanje_na_semaforu == StanjeNaSemaforu::ZUTO)
			cout << "Na semaforu je zuto svjetlo" << endl;
	}
};

int main() {
	Semafor semafor;

	while (1) {
		semafor.setStanje(Semafor::StanjeNaSemaforu::CRVENO);  // prijelaz
		semafor.printStanje();  // status
		Sleep(5 * 1000); // wait for 1000ms = 1 second  // duration

		semafor.setStanje(Semafor::StanjeNaSemaforu::CRVENO_ZUTO);
		semafor.printStanje();
		Sleep(3 * 1000); // wait for 3000ms = 3 second

		semafor.setStanje(Semafor::StanjeNaSemaforu::ZELENO);
		semafor.printStanje();
		Sleep(8 * 1000); // wait for 8000ms = 8 second

		semafor.setStanje(Semafor::StanjeNaSemaforu::ZUTO);
		semafor.printStanje();
		Sleep(3 * 1000); // wait for 3000ms = 3 second
	}

}

/*
	// zadaca ovakvu funkciju napisat
	void Prijelaz() {
	// prijelaz u sljedece
		if (trenutno)
			trenutno = sljedeće;
		print
			wait
	}
*/