#include <iostream>
using namespace std;
// () {} [] <> || "" && % << >>

// Nizovi (zadatci za vježbu, 1. dio)

int main() {
	// 1. Ispiši sve elemente niza - prvi način za rješavanje

	// Deklaracija i inicijalizacija niza
	int niz[5] = { 1,2,3,4,5 };

	// Dodjeljivanje svakog elementa niza varijabli
	int prviBroj = niz[0];
	int drugiBroj = niz[1];
	int treciBroj = niz[2];
	int cetvrtiBroj = niz[3];
	int petiBroj = niz[4];

	// Ispis rezultata
	cout << "Ispis svih elemenata niza: " << prviBroj << drugiBroj << treciBroj
		<< cetvrtiBroj << petiBroj << endl;
	

	// 1. Ispiši sve elemente niza - drugi način za rješavanje

	// Deklaracija i inicijalizacija niza
	int brojevi[] = { 1, 2, 3, 4, 5 };

	// Izračun veličine niza dijeljenjem ukupne veličine niza s veličinom svakog elementa
	int velicina = sizeof(brojevi) / sizeof(brojevi[0]);

	// For petlja i ispis
	for (int i = 0; i < velicina; i++) {
		std::cout << brojevi[i] << " ";
	}


	// 2. Ispiši svaki drugi element niza.
	
	// Deklaracija i inicijalizacija niza
	int nizario[] = { 1,2,3,4,5,6,7,8 };

	// Izračun veličine niza
	int velicinario = sizeof(nizario) / sizeof(nizario[0]);

	// For petlja i ispis
	for (int i = 0; i < velicinario; i += 2) {
		cout << nizario[i] << " ";
	}


	// 3. Izračunaj sumu svih elemenata niza.

	int NIZ[] = { 1,2,3,4,5,6 }; // Deklaracija i inicijalizacija niza
	int sumaNiza = 0; // Inicijalizacija varijable 'sumaNiza' koja ce predstavlja sumu elemenata
	int velicinaNiza = sizeof(NIZ) / sizeof(NIZ[0]);  // izračun veličine niza

	// Prolazak kroz elemente niza i akumuliranje njihovih vrijednosti u varijabli sumaNiza
	for (int i = 0; i < velicinaNiza; i++) {
		sumaNiza += NIZ[i];
	// Svaki put kada petlja prolazi, dodajemo trenutni element niza (NIZ[i]) u varijablu sumaNiza pomoću operatora +=
	}
	// Ispis
	cout << "Suma svih elemenata niza: " << sumaNiza << endl;


}