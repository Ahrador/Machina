#include <iostream>
#include <string>
using namespace std;

// Kartaške igre - #1 - Karte
/*
Dizajniraj kartu za kartašku igru.
- Napravi tip podataka (strukturu ili klasu) koji predstavlja Kartu.
- Napiši funkciju koja joj daje slučajnu vrijednost. Karta treba biti drukčija svaki 
put kad se funkcija pozove.
- Instanciraj ("instancirati" znači "napraviti varijablu") jednu takvu kartu u mainu, 
pozovi gore napravljenu funkciju, te ispiši vrijednost karte na konzolu.

Svaka igra ima svoj set karata, pa općeniti "Deck of cards" nema smisla raditi u 
sklopu ovog zadatka, nego samo kartu. Špil ćemo raditi za Belot i Poker posebno.
*/

// Tip podatka koji predstavlja kartu
struct Karta{
	string boja_karte;
	int broj_karte;
};

// Funkcija koja joj daje slučajnu vrijednost
Karta generiranjeSlucajneKarte() {
	string boje[] = { "Crvena", "Zelena", "Crna", "Plava", "Zuta"};
	int brojevi[] = { 1,2,3,4,5,6,7,8,9,10,11 };

	// Seed za generiranje slučajnih brojeva
	srand(static_cast<unsigned int>(time(0)));

	// Generacija slučajnih indeksa za boju i vrijednost karte
	int slucajni_index_boje = rand() % 5;
	int slucajni_index_broja = rand() % 11;

	// Stvori novu kartu s generiranom bojom i vrijednošću
	Karta nova_karta;
	nova_karta.boja_karte = boje[slucajni_index_boje]; 
	nova_karta.broj_karte = brojevi[slucajni_index_broja];

	// Vraćanje nove karte
	return nova_karta;
}


int main() {
	// Instanciranje i poziv funkcije
	Karta karta1 = generiranjeSlucajneKarte();

	// Ispis rezultata
	cout << "Boja: " << karta1.boja_karte << endl;
	cout << "Broj: " << karta1.broj_karte << endl;


}