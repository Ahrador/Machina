#include <iostream>
#include <string>
using namespace std;

// Kartaške igre - #2 - osnovni Poker engine
/*
Koristeći code iz zadatka "Kartaške igre - #1 - Karte", napiši program koji će biti temelj za 
jednostavnu Poker igru baziranu na Texas Hold'em varijanti.

- Dizajniraj objekt "Igrač". Igrač u Texas hold'emu ima određeni broj čipova i dvije karte.
- Dizajniraj objekt "PokerDeckOfCards" koji predstavlja špil karata za ovu igru. Treba sadržavati 
52 karte, sa postavljenim vrijednostima. 
    - Za postavljanje vrijednosti tih karata možeš dodati funkciju initializeDeck(). 
    - Dodaj mu funkciju drawRandomCard() koja predstavlja izvlačenje karte iz špila karata; i vraća 
    Kartu preko return naredbe. Jednom tako "izvučena" karta ne smije se ponovno izvući dok se 
    špil ne resetira. 
    - Dodaj i funkciju resetDeck() koja će resetirati špil tako  da se iz njega opet mogu izvući 
    sve karte.
- Dizajniraj objekt "PokerGame". PokerGame sadrži 8 igrača i špil karata. Po potrebi možeš dodati 
još elemenata u objekt ako su potrebni za uspješno izvršavanje igre (npr: karte na stolu, količina 
čipova na stolu, koji igrač je na redu, i slično).
- Dodaj funkciju play() u "PokerGame". Nakon što se instancira varijabla u mainu, poziv funkcije 
play() treba započeti igranje pokera. Primjer toga je priložen kao "main.cpp" u ovom zadatku.

--- VAŽNO: Funkciju play() ne treba napisati do kraja. Napravite samo podjelu karata igračima 
(pre-flop) i 5 karata na stolu, bez faza ulaganja. Ostatak igre će se rješavati u budućem zadatku.
- Na kraju ispiši sve karte svih igrača i karte na stolu.

Ispravno rješenje ovog zadatka će svaki put ispisati različite i jedinstvene karte: karte su 
svaki put drukčije i nijedna od karata igrača/karata na stolu se ne ponavlja.
*/


// Tip podatka koji predstavlja kartu
struct Karta {
	string boja_karte;
	int broj_karte;
};

class Igrac {
private:
	int brojCipova;


};

// Funkcija koja joj daje slučajnu vrijednost
Karta generiranjeSlucajneKarte() {
	string boje[] = { "Crvena", "Zelena", "Crna", "Plava", "Zuta" };
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


int main() {
    PokerGame poker;
    poker.play();
}