#include <iostream>
#include <string>
using namespace std;

// Luhn Algoritam

/*
Napišite program koji na ulazu primi 15-znamenkasti broj i izračuna njegovu checksum 
znamenku koristeći Luhnov algoritam.

Checksum znamenka se računa tako da:
1. se sve znamenke zbroje, ali svaka druga znamenka se prije toga udvostruči (ako je 
udvostručeni broj dvoznamenkast, treba zbrojiti njegove dvije znamenke; npr. 7 
udvostručen je 14, pa je rezultat broj 1+4 = 5);
2. nakon dobivanja zbroja svih znamenki, izračunate koji broj je potrebno dodati zbroju 
da bi se dobio broj koji je djeljiv s 10. Npr. ako je zbroj znamenki 52, checksum je 8 
jer je 52+8 = 60; ako je zbroj 85 checksum je 5; ako je zbroj 81 checksum je 9; ako je 
zbroj 90 checksum je 0.

Napomena: broj koji se traži nije među udvostručenim znamenkama, tako da se udvostručuje 
svaka druga od unesenih brojeva, počevši s desne strane.
*/

int main() 
{

	int broj_kartice;
	cout << "Upiši 15-znamenkasti broj: ";
	cin >> broj_kartice;

	// Deklaracija varijable za izracun zbroja znamenki, incijalizirnao na 0.
	int zbroj_znamenki = 0;

	// deklaracija varijable koja prati trebamo li udvostrucit trenutnu znamenku
	bool udvostruci = false;

	// pomoćna varijabla za računanje udvostručenih znamenki.
	int faktor = 1; 

	/*
	Ove linije izdvajaju posljednju znamenku broja kartice i ažuriraju broj tako da 
	se ukloni ta znamenka. Na primjer, ako je broj bio 12345, znamenka će biti 5, a 
	broj će postati 1234.
	*/
	for (int i = 0; i < 15; i++) { 
		int znamenka = broj_kartice % 10; 
		/*
		Kada primijenimo % 10 na broj, dobivamo ostatak pri dijeljenju tog broja s 10.
		Na primjer, ako je broj kartice 12345, kada primijenimo % 10, dobivamo ostatak 5.
		*/
		broj_kartice /= 10;  // dijeljenje varijable s 10 i rezultat nazad u nju 
	
		if (udvostruci) {  // ako je udvostruci true, ulazimo u blok viticastih zagrada
			znamenka *= 2; // znamenka se udvostruci mnozenjem s 2 i rezultat joj se pridaje
			if (znamenka > 9) { // Ako je veća od 9, to znači da je rezultat dvocifren broj. 
				znamenka = znamenka / 10 + znamenka % 10;
			  // U tom slučaju, znamenke se zbrajaju pojedinačno kako bi se dobio jednocifreni rezultat.
				/*
				Na primjer, ako je znamenka bila 14, dijeljenje s 10 daje 1, a ostatak pri 
				dijeljenju s 10 je 4. Konačno, znamenka postaje 5, što je zbroj rezultata dijeljenja 
				i ostatka.
				*/
			}
		}
		/*
		ova linija dodaje vrijednost znamenka na postojeću vrijednost varijable zbroj.To je način na 
		koji se zbrajaju sve znamenke kako bismo dobili ukupni zbroj.
		*/
		zbroj_znamenki += znamenka; 

		/*
		ova linija mijenja vrijednost varijable udvostruci u suprotno od trenutne vrijednosti. 
		Ako je bila true, postaje false, a ako je bila false, postaje true. Ovo se koristi za 
		odlučivanje kada treba udvostručiti znamenku u sljedećoj iteraciji petlje.
		*/
		udvostruci = !udvostruci; 


		/*
		ova linija izračunava checksum znamenku. Provjerava se ostatak dijeljenja zbroj s 10. 
		Ako je ostatak 0, checksum je 0, inače je 10 minus taj ostatak.
		*/
		int checksum = (zbroj_znamenki % 10 == 0) ? 0 : 10 - (zbroj_znamenki % 10); 
		
		std::cout << "Checksum znamenka: " << checksum << std::endl;
		return 0;
	}
}