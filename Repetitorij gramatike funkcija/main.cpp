#include <iostream>
using namespace std;

// Repetitorij gramatike funkcija

/*
Napiši po 5 od svakih:

Funkcija koja ne prima argument, i ne vraća vrijednost.
Funkcija koja ne prima argument, ali vraća vrijednost.
Funkcija koja prima argument, ali ne vraća vrijednost.
Funkcija koja prima argument, i vraća vrijednost.

Svaka koja prima argumente može primiti jedan ili više njih.
Provjerite rade li funkcije kako očekujete tako što ćete ih pozvati iz main().
*/


// 1/5  -  Funkcija koja ne prima argument, i ne vraća vrijednost.
void beskorisna_funkcija() {  // Nikakvi argumenti unutar funkcije
	cout << "Useless" << endl;
}
 
// 2/5  -  Funkcija koja ne prima argument, i ne vraća vrijednost.
void izbornik() {
	cout << "Izbornik:" << endl;
	cout << "1. Prva opcija" << endl;
	cout << "2. Druga opcija" << endl;
	cout << "3. Treca opcija" << endl;
}

// 3/5  -  Funkcija koja ne prima argument, i ne vraća vrijednost.
void print_welcome_message() {
	cout << "Welcome!" << endl;
}

// 4/5  -  Funkcija koja ne prima argument, i ne vraća vrijednost.
void lista_brojeva_do_10() {
	cout << "Lista brojeva:" << endl;
	cout << "1, 2, 3, 4, 5, 6, 7, 8, 9, 10" << endl;
}

//--------------------------------------------------------------------------------

// 1/5  -  Funkcija koja ne prima argument, ali vraća vrijednost.
char ascii_vrijednost_broja() {
	int i = 33;
	return char(i);
}

// 2/5  -  Funkcija koja ne prima argument, ali vraća vrijednost.
int dobivanje_random_brojeva() {
	srand(time(0));
	return rand() % 10 + 1;
}

//--------------------------------------------------------------------------------

// 1/5  -  Funkcija koja prima argument, ali ne vraća vrijednost.
void pozdrav(string ime) {
	cout << "Pozdrav, " << ime << "!" << endl;
}

// 2/5  -  Funkcija koja prima argument, ali ne vraća vrijednost.
void zbroj(int a, int b) {
	int rezultat = a + b;
	cout << "Zbroj brojeva " << a << " i " << b << " je " << rezultat << endl;
}

// 3/5  -  Funkcija koja prima argument, ali ne vraća vrijednost.
void ispis_kvadrata(int number) {
	cout << "Kvadrat broje " << number << " je " << number * number << endl;
}

//--------------------------------------------------------------------------------

int main() {

	// Poziv funkcija koje ne primaju argument i ne vraćaju vrijednost
	beskorisna_funkcija();
	izbornik();
	print_welcome_message();
	lista_brojeva_do_10();

	// Poziv funkcija koje ne primaju argument ali vraćaju vrijednost
	cout << ascii_vrijednost_broja() << endl;
	cout << dobivanje_random_brojeva() << endl;

	// Poziv funkcija koje primaju argument ali ne vraćaju vrijednost
	// 1/5
	pozdrav("Alen");
	
	// 2/5
	int x = 5, y = 2;
	zbroj(x, y);
	
	// 3/5
	int number;
	cout << "Unesi broj: ";
	cin >> number;
	ispis_kvadrata(number);
	return 0;

	// Napomena:  Nisu mi pale ideje za više funkcija pa sam samo ove napisao.
}