#include <iostream>
using namespace std;
// () {} [] <> || "" && % << >>

// Nizovi (dodatno objašnjenje)

int main() { 
	/*
	Nizovi (arrays) u C++-u su strukture podataka koje omogućuju pohranjivanje
	više elemenata istog tipa podataka, grupiranih zajedno pod jednim imenom.
	Svaki element u nizu ima svoj indeks koji ga jedinstveno identificira.
	*/

	/*
	Deklaracija niza:
	Niz se deklarira navođenjem tipa elemenata koje će niz sadržavati, a zatim
	niza imena i veličine niza u uglatim zagradama ([]). Na primjer:
	*/

	// Ova deklaracija stvara niz brojevi koji može sadržavati 5 cjelobrojnih vrijednosti.
	int brojevi[5];

	/*
	Inicijalizacija niza:
	Niz se može inicijalizirati pri deklaraciji ili kasnije dodjeljivanjem vrijednosti
	pojedinačnim elementima. Primjeri:
	*/

	// Ova inicijalizacija stvara niz brojevi i dodjeljuje mu početne vrijednosti.
	int brojevi[5] = { 1, 2, 3, 4, 5 };

	/*
	Pristupanje elementima niza:
	Elementima niza se pristupa putem njihovih indeksa. Indeksi počinju od 0 za prvi
	element i povećavaju se za 1 za svaki sljedeći element. Primjer:
	*/

	// U ovom primjeru, vrijednost trećeg elementa niza brojevi se dodjeljuje varijabli trećiBroj.
	int trećiBroj = brojevi[2]; // pristup trećem elementu

	/*
	Petlje i nizovi:
	Nizovi se često koriste zajedno s petljama kako bi se olakšalo rukovanje svim elementima niza.
	Primjer petlje za ispisivanje svih elemenata niza:
	*/

	// Ova petlja prolazi kroz sve elemente niza brojevi i ispisuje ih.
	for (int i = 0; i < 5; i++) {
		cout << brojevi[i] << endl;
	}
}