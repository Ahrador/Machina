#include <iostream>

// Predavanje 6 (20.5.2023.) - Vježbanje zadataka

// Zadatak: Vending machine - #1 - coin acceptor
/*
Napiši code koji glumi obračunavanje iznosa za vraćanje u kovanicama na
samoposlužnim aparatima.
- Aparat prima kovanice od €0.10, €0.20, €0.50, €1, €2.
- Napiši strukturu "KolicineKovanica" koja predstavlja količine svakog od tih apoena.
- Napiši funkciju koja prima stanje na računu na aparatu, cijenu artikla, i vraća
  strukturu tipa "KolicineKovanica" koja opisuje koliko kojih kovanica treba vratiti
  kupcu.
- Funkcija treba prioritizirati vraćanje kovanica većeg apoena kad je to moguće.
*/

// Struktura koja opisuje količine kovanica
struct KolicineKovanica {
	unsigned kolicina_10cent;
	unsigned kolicina_20cent;
	unsigned kolicina_50cent;
	unsigned kolicina_1eur;
	unsigned kolicina_2eur;
};

/*
Ovdje definiramo strukturu KolicineKovanica koja sadrži pet varijabli tipa
unsigned koje predstavljaju količine različitih kovanica.
*/

// Funkcija koja pretvara neoznačeni cijeli broj ('iznos') u strukturu 'KolicineKovanica'
KolicineKovanica pretvori_unsigned_u_kolicine_kovanica(unsigned iznos) {
	KolicineKovanica za_vratiti;

	// Inicijalizacija količina kovanica na 0
	za_vratiti.kolicina_10cent = 0;
	za_vratiti.kolicina_20cent = 0;
	za_vratiti.kolicina_50cent = 0;
	za_vratiti.kolicina_1eur = 0;
	za_vratiti.kolicina_2eur = 0;

	return za_vratiti;
}

/*
Varijabla 'za_vratiti' se inicijalizira s nulama za sve količine kovanica, a zatim
se vraća ta inicijalizirana struktura.
*/

// Glavna funkcija koja izračunava količine kovanica za vratiti
KolicineKovanica funkcija(unsigned ubacen_novac, unsigned cijena) {
	// Kreiranje nove instance strukture KolicineKovanica
	KolicineKovanica za_vratiti;

	// Vraćanje prazne strukture jer nema izračuna u ovom primjeru
	return za_vratiti;
}

/*
Ova funkcija izračunava količine kovanica koje treba vratiti na temelju ulaznih
parametara ubacen_novac (ukupni iznos ubačen na račun) i cijena (cijena artikla).
U ovom primjeru, funkcija samo vraća praznu strukturu jer nema stvarnog izračuna.
*/


int main() {
	// Deklaracija i inicijalizacija varijabli / ulaznih vrijednosti
	unsigned ubacen_novac = 300;
	unsigned cijena = 170;

	// Poziv funkcije za izračun količina kovanica
	KolicineKovanica kolicine = funkcija(ubacen_novac, cijena);

	/*
	Ovdje pozivamo funkciju funkcija s argumentima ubacen_novac i cijena te rezultat
	pohranjujemo u varijablu kolicine tipa KolicineKovanica. To znači da će se
	izračunate količine kovanica koje treba vratiti spremiti u kolicine.
	*/

	// Ispis količina kovanica za vratiti
	std::cout << "Kolicine kovanica za vratiti:" << std::endl;
	std::cout << "10 cent: " << kolicine.kolicina_10cent << std::endl;
	std::cout << "20 cent: " << kolicine.kolicina_20cent << std::endl;
	std::cout << "50 cent: " << kolicine.kolicina_50cent << std::endl;
	std::cout << "1 eur: " << kolicine.kolicina_1eur << std::endl;
	std::cout << "2 eur: " << kolicine.kolicina_2eur << std::endl;

	/*
	Ovdje koristimo std::cout za ispis količina kovanica koje treba vratiti. Prvo
	ispisujemo zaglavlje "Kolicine kovanica za vratiti:", a zatim ispisujemo vrijednosti
	količina kovanica za svaku denominaciju (10 centa, 20 centa, 50 centa, 1 eura i 2 eura)
	iz varijable kolicine.
	*/

	return 0;
}