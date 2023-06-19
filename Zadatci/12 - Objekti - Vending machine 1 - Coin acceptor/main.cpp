#include <iostream>
using namespace std;

// Zadatak - Vending machine - 01 - coin acceptor

/*
Napiši kod koji glumi obračunavanje iznosa za vraćanje u kovanicama na 
samoposlužnim aparatima.

Aparat prima kovanice od €0.10, €0.20, €0.50, €1, €2. 
Napiši strukturu "KolicineKovanica" koja predstavlja količine svakog od tih poena.
Napiši funkciju koja prima stanje na računu na aparatu, cijenu artikla, i vraća 
strukturu tipa "KolicineKovanica" koja opisuje koliko kojih kovanica treba vratiti kupcu.
Funkcija treba prioritizirati vraćanje kovanica većeg apoena kad je to moguće.
*/

struct KolicineKovanica {
	int kovanice_10c;
	int kovanice_20c;
	int kovanice_50c;
	int kovanice_1e;
	int kovanice_2e;
};

KolicineKovanica izracunajKovaniceZaVracanje(double stanjeNaRacunu, double cijenaArtikla) { 
	// Inicijaliziramo strukturu za praćenje količina kovanica koje treba vratiti 
	KolicineKovanica kolicineVracenihKovanica = { 0, 0, 0, 0, 0 }; 

    // Izračunaj iznos koji treba vratiti kupcu
    double iznosZaVracanje = stanjeNaRacunu - cijenaArtikla;

    // Provjeri iznos za vracanje po kovanicama većeg apoena
    while (iznosZaVracanje >= 2.0) {
        kolicineVracenihKovanica.kovanice_2e++;
        iznosZaVracanje -= 2.0;
    }

    while (iznosZaVracanje >= 1.0) {
        kolicineVracenihKovanica.kovanice_1e++; 
        iznosZaVracanje -= 1.0;
    }

    while (iznosZaVracanje >= 0.5) {
        kolicineVracenihKovanica.kovanice_50c++;
        iznosZaVracanje -= 0.5;
    }

    while (iznosZaVracanje >= 0.2) {
        kolicineVracenihKovanica.kovanice_20c++;
        iznosZaVracanje -= 0.2;
    }

    while (iznosZaVracanje >= 0.1) {
        kolicineVracenihKovanica.kovanice_10c++;
        iznosZaVracanje -= 0.1;
    }

    return kolicineVracenihKovanica;
}

/*
Primjer korištenja funkcije:
   - Kako bismo provjerili ispravnost implementirane funkcije, možemo je koristiti u primjeru 
   koji simulira kupovinu na samoposlužnom aparatu. U primjeru ćemo definirati stanje na 
   računu, cijenu artikla i ispisati količine kovanica koje treba vratiti kupcu.
*/

int main() {
    double stanjeNaRacunu = 5.0;  // Primjer stanja na računu
    double cijenaArtikla = 2.7;   // Primjer cijene artikla

    KolicineKovanica kolicineVracenihKovanica = izracunajKovaniceZaVracanje(stanjeNaRacunu, cijenaArtikla); 

    // Ispis količina kovanica koje treba vratiti kupcu
    std::cout << "Količine kovanica za vratiti kupcu:" << std::endl; 
    std::cout << "€2: " << kolicineVracenihKovanica.kovanice_2e << std::endl; 
    std::cout << "€1: " << kolicineVracenihKovanica.kovanice_1e << std::endl; 
    std::cout << "€0.50: " << kolicineVracenihKovanica.kovanice_50c << std::endl; 
    std::cout << "€0.20: " << kolicineVracenihKovanica.kovanice_20c << std::endl; 
    std::cout << "€0.10: " << kolicineVracenihKovanica.kovanice_10c << std::endl; 

    return 0;
}