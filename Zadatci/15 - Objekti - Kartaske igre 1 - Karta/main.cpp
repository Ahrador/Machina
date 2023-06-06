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
struct Karta {
	string boja_karte;
	int broj_karte;
};

// Funkcija koja generira slučajnu kartu
Karta generiranjeSlucajneKarte() { 
	// Generacija slučajnih vrijednosti za boju i broj karte
	string boje[] = { "Crvena", "Zelena", "Crna", "Plava", "Zuta" };

	// Generiranje slučajnog broja od 1 do 10 za broj karte
	int slucajni_broj_karte = (rand() % 10) + 1; 

	// Generiranje slučajnog indeksa za boju
	int slucajni_index_boje = (rand() % 5); 

	// Stvaranje nove karte s generiranim vrijednostima
	Karta nova_karta;
	nova_karta.boja_karte = boje[slucajni_index_boje];
	nova_karta.broj_karte = slucajni_broj_karte;

	// Vraćanje nove karte
	return nova_karta;
}

int main() {
	srand(time(0)); // Postavljanje seeda na trenutno vrijeme 

	Karta karta1 = generiranjeSlucajneKarte();

	// Ispis rezultata
	cout << "Boja: " << karta1.boja_karte << endl; 
	cout << "Broj: " << karta1.broj_karte << endl; 
}