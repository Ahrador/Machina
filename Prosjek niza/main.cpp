#include <iostream>
using namespace std;

// Prosjek niza

/*
Napiši funkciju koja prima niz brojeva i duljinu niza, te vrati aritmetičku 
sredinu (prosjek) njegovih članova.
*/

// Funkcija za računanje prosjeka s dva argumenta
double prosjek(int niz[], int duljina_niza) {
	double suma = 0.0;  // ovdje ce se spremiti
	for (int i = 0; i < duljina_niza; i++) {
		suma += niz[i];  // zbrajanje i pridruzivanje brojeva iz niza u sumu
	}
	double prosjek = suma / duljina_niza;
	return prosjek;
}

int main() {
	int niz[] = { 3, 5, 7, 8, 9 };  // Deklaracija brojeva u nizu
	int duljina_niza = sizeof(niz) / sizeof(niz[0]); // izračunamo duljinu niza --- ovo sam Googlao
	double rezultat = prosjek(niz, duljina_niza);
	cout << "Aritmeticka sredina: " << rezultat << endl; // Ispis rezultata

	return 0;
}