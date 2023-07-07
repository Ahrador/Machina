#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// Stringovi

// Definiranje strukture Ucenik koja sadrži dva stringa za ime i prezime
struct Ucenik {
	string ime;
	string prezime;
};

int main() {
	// Deklaracija stringa 'tekst'
	string tekst;

	// Dodjeljivanje vrijednosti stringu 'tekst'
	tekst = "Ovo je neki tekst";

	// Nadodavanje teksta na postojeći string 'tekst'
	tekst += ", a ovo je nastavak";

	// Ispisivanje sadržaja stringa 'tekst' u konzolu
	cout << tekst << endl;

	// Deklaracija objekta 'ucenik' tipa Ucenik i inicijalizacija njegovih članova
	Ucenik ucenik{ "Pero", "Peric" };

	// Dodjeljivanje vrijednosti stringu 'tekst' s konstrukcijom teksta koji koristi stringove i promjenljive
	tekst = "Dobar dan gosp. " + ucenik.prezime + ", ...";

	cout << tekst;
}