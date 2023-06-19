#include <iostream>
#include <string>
#include <vector>
#include <array>
// vecina tipova podataka je u headeru definirana
using namespace std;

// Predavanje 8 - Vektori

int main() {

	// vector je template tip podataka
	string tekst; 
	int niz[10]; // niz podataka s fiksnom veličinom od 10 elemenata
	vector<int> veki;  // deklaracija varijabilnog vektora podataka 'veki', koji je tipa int.
	veki.push_back(10); // dodaje broj 10 na kraj vektora 

	// Dva načina pristupu prvom elementu vektora
	veki.at(0); // provjera granice ektora da nismo ivan raspona
	veki[0]; // ne provjerava granice i pretpostavlja da je indeks ispravan.

	// -------------------------------------------------------------------------

	vector<int>brojevi; // nema elemenata

	// Prolazak kroz petlju i dodavanje slučajno generiranih brojeva u vektor
	for (int i = 0; i < 45; i++) 
		brojevi.push_back(rand());  //Svaki put kad se pozove, push_back() dodaje novi element na kraj vektora.

	cout << brojevi[0] << endl;
	cout << brojevi[1] << endl;
	cout << brojevi[2] << endl;
	cout << brojevi[3] << endl;
	cout << brojevi[4] << endl;
	cout << brojevi[5] << endl;

	brojevi.empty(); // ispituje je li vektor 'brojevi' prazan
	brojevi.clear(); // briše sve elemente unutar vektora brojevi, čime se vektor prazni

	cout << brojevi.size() << endl; // vraća trenutni broj elemenata u vektoru brojevi
	
	// Vraća kapacitet (broj elemenata koje vektor može pohraniti prije nego što se mora proširiti)
	cout << "Cap 1: " << brojevi.capacity() << endl;

	/*
	Rezervira prostor za 500 elemenata u vektoru brojevi. Ovo omogućuje vektoru da 
	unaprijed rezervira memoriju kako bi mogao pohraniti veći broj elemenata bez 
	potrebe za ponovnom alokacijom memorije.
	*/
	brojevi.reserve(500); 
	cout << "Cap 2: " << brojevi.capacity() << endl; 

	// Do-while petlja se izvršava dok vektor 'brojevi' nije prazan
	do {
		// generator
	} while (brojevi.size()); 

	// -------------------------------------------------------------------------
	
	// Vježba
	// Deklaracija vektora 'brojevi2' za pohranu cjelobrojnih vrijednosti
	vector<int> brojevi2; 

	for (int i = 0; i < 6; i++) // Petlja se izvodi 6 puta
		brojevi2.push_back(rand() % 42 + 1); // Generira se slučajan broj između 1 i 42 (uključivo) te se dodaje u vektor 'brojevi2'

	for (int i = 0; i < 6; i++) // Petlja se izvodi 6 puta
		cout << brojevi2[0] << endl; // Ispisuje se vrijednost na indeksu 0 vektora 'brojevi2' (ista vrijednost će biti ispisana 6 puta)

	cout << brojevi2[1] << endl; // Ispisuje se vrijednost na indeksu 1 vektora 'brojevi2'
	cout << brojevi2[2] << endl; // ...
	cout << brojevi2[3] << endl; 
	cout << brojevi2[4] << endl; 
	cout << brojevi2[5] << endl; 
}
