#include <iostream>
using namespace std;

// Zbroj znamenki

/*
Napiši funkciju koja vraća zbroj znamenki predanog broja.
Npr. ako ta funkcija primi broj 123 kao argument, vraća 6; ako primi broj 91765 
kao argument, vraća 28.
*/

// Funkcija
int zbroj_znamenki(int broj) {
	int zbroj = 0;
	for (int i = broj; i > 0; i /= 10) {
		zbroj += i % 10;
	}
	return zbroj;
}

int main() {
	// Deklaracija varijable i upis broja
	int broj;
	cout << "Unesite broj: ";
	cin >> broj;

	// Poziv funkcije 
	int zbroj = zbroj_znamenki(broj); 
	cout << "Zbroj znamenki broja " << broj << " je " << zbroj << endl;
}

