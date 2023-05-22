#include <iostream>

// Predavanje 6 (20.5.2023.) - Vježbanje zadataka

// Zadatak: Vending machine - #2 - Catalogue

/*Koristeci code iz zadataka #1, napisi program koji glumi smaoposluzni aparat.
- Napravi katalog proizvoda.
- proizvodi su rasporedeni po redovima koji su odredeni brojem.
- svaki red pojedinog proizvoda treba imati ime, cijenu i kolicinu preostalih proizvoda u tome redu.
- aparat treba znati trenutnu kolicinu kovanica u spremniku.
- ukoliko aparat nema dovoljno kovanica za vratiti, treba odustati od kupovine, vratiti kupcu novac koji je ubacio i ispisati razlog odustajanja.
- dodajte opciju Punjenje aparata. koja ubaci "proizvode" i kovanice u aparat.
*/

// Broj kovanica različitih vrijednosti
struct KolicineKovanica {
	unsigned kolicina_10cent;
	unsigned kolicina_20cent;
	unsigned kolicina_50cent;
	unsigned kolicina_1eur;
	unsigned kolicina_2eur;
};

// Ova funkcija pretvara cijeli broj u objekt tipa KolicineKovanica koji sadrži 
// informacije o broju kovanica potrebnih za taj iznos.
KolicineKovanica pretvori_unsigned_u_kolicine_kovanica(unsigned iznos) {
	KolicineKovanica za_vratiti;
	// inicijaliziraj strukturu
	za_vratiti.kolicina_10cent = 0;
	za_vratiti.kolicina_20cent = 0;
	za_vratiti.kolicina_50cent = 0;
	za_vratiti.kolicina_1eur = 0;
	za_vratiti.kolicina_2eur = 0;

	// prvo vrati vece
	if (iznos >= 200) {
		za_vratiti.kolicina_2eur = iznos / 200;
		iznos %= 200;
	}
	if (iznos >= 100) {
		za_vratiti.kolicina_1eur = iznos / 100;
		iznos %= 100;
	}
	if (iznos >= 50) {
		za_vratiti.kolicina_50cent = iznos / 50;
		iznos %= 50;
	}
	if (iznos >= 20) {
		za_vratiti.kolicina_20cent = iznos / 20;
		iznos %= 20;
	}
	if (iznos >= 10) {
		za_vratiti.kolicina_10cent = iznos / 10;
		iznos %= 10;
	}

	return za_vratiti;
}

// Ova funkcija izračunava količinu kovanica potrebnih za vraćanje kusura na temelju ubačenog novca i cijene proizvoda.
KolicineKovanica izracunaj_kusur(unsigned ubacen_novac, unsigned cijena) {
	KolicineKovanica za_vratiti;
	// izracunati kolicinu za vratiti

	// prvo provjeri ima li dovoljno novca na racunu
	if (cijena > ubacen_novac)
	{
		// ako nema, nema smisla racunati koliko novca treba vratiti
		std::cout << "Nedovoljno novca na racunu" << std::endl;
		return pretvori_unsigned_u_kolicine_kovanica(ubacen_novac);
	}

	// ima dovoljno novca, izracunaj prvo koju vrijednost treba vratiti...
	unsigned ostatak = ubacen_novac - cijena;
	return pretvori_unsigned_u_kolicine_kovanica(ostatak);
}

// Ova struktura predstavlja redak proizvoda u aparatu.
struct RedProizvoda {
	//char ime_artikla[20];
	unsigned cijena_artikla;
	unsigned preostalo_artikala;
};

/*
Ova struktura predstavlja aparat za prodaju proizvoda. Sadrži informacije o količinama 
kovanica i katalogu proizvoda. Također ima dvije funkcije: punjenjeAparata za 
inicijalizaciju aparata s početnim vrijednostima i ispisiStanje za ispis trenutnog 
stanja aparata.
*/
struct Aparat {
	KolicineKovanica kolicine_kovanica;
	RedProizvoda katalog[6];

	void punjenjeAparata() {
		// "napuni" coin acceptor kovanicama
		kolicine_kovanica.kolicina_10cent = 20;
		kolicine_kovanica.kolicina_20cent = 20;
		kolicine_kovanica.kolicina_50cent = 20;
		kolicine_kovanica.kolicina_1eur = 20;
		kolicine_kovanica.kolicina_2eur = 20;
		// "napuni" katalog proizvoda
		katalog[0].cijena_artikla = 150;
		katalog[0].preostalo_artikala = 7;
		katalog[1].cijena_artikla = 150;
		katalog[1].preostalo_artikala = 7;
		katalog[2].cijena_artikla = 200;
		katalog[2].preostalo_artikala = 7;
		katalog[3].cijena_artikla = 250;
		katalog[3].preostalo_artikala = 7;
		katalog[4].cijena_artikla = 2000;
		katalog[4].preostalo_artikala = 7;
		katalog[5].cijena_artikla = 100;
		katalog[5].preostalo_artikala = 7;
	}

	void ispisiStanje() {
		for (unsigned indeks_reda = 0; indeks_reda < 6; indeks_reda++)
		{
			auto trenutni_red = katalog[indeks_reda];
			std::cout << "Red " << indeks_reda <<
				"- cijena : EUR " << float(trenutni_red.cijena_artikla) / 100
				<< ", preostalo artikala: " << trenutni_red.preostalo_artikala << std::endl;
		}
	}
};

// Ova funkcija ispisuje liniju razdvajanja kako bi se poboljšala čitljivost ispisa.
void PrintSeparatorLine() {
	std::cout << "------------------------------" << std::endl;
}

/*
Stvara se objekt aparat i poziva se funkcija punjenjeAparata za inicijalizaciju aparata. 
Zatim se pokreće glavna petlja koja se izvršava sve dok ne završi program.
*/
int main() {
	Aparat aparat;
	aparat.punjenjeAparata();

	while (true) {
		PrintSeparatorLine();
		// pokazi stanje robe
		aparat.ispisiStanje();

		PrintSeparatorLine();
		// primi novac
		std::cout << "Ubaci novac (EUR)" << std::endl;
		float ubaceni_novac;
		std::cin >> ubaceni_novac;

		PrintSeparatorLine();
		// selektiraj robu
		int izabrani_proizvod;
		do {
			std::cout << "Izaberi nesto iz kataloga (0-5) : " << std::endl;
			std::cin >> izabrani_proizvod;
		} while (!(izabrani_proizvod > 0 && izabrani_proizvod < 6));

		// obradi transakciju (kupovinu) - prihvati novac i vrati ostatak ILI odbij novac
		const auto cijena_izabranog_proizvoda = aparat.katalog[izabrani_proizvod].cijena_artikla;
		if (aparat.katalog[izabrani_proizvod].preostalo_artikala == 0) {
			std::cout << "Nema vise tog proizvoda" << std::endl;
			std::cout << "Vracam " << ubaceni_novac << "EUR" << std::endl;
		}
		else if (cijena_izabranog_proizvoda > (ubaceni_novac * 100)) {
			std::cout << "Cijena robe je veca od iznosa ubacenog novca" << std::endl;
			std::cout << "Vracam " << ubaceni_novac << "EUR" << std::endl;
		}
		else {
			// izracunaj koliko bi trebalo vratiti
			auto kusur = izracunaj_kusur(ubaceni_novac * 100, cijena_izabranog_proizvoda);
			const auto kolicine_kovanica_u_aparatu = aparat.kolicine_kovanica;

			// provjeri ima li dovoljno za vratitit
			if (kusur.kolicina_2eur > kolicine_kovanica_u_aparatu.kolicina_2eur
				|| kusur.kolicina_1eur > kolicine_kovanica_u_aparatu.kolicina_1eur
				|| kusur.kolicina_50cent > kolicine_kovanica_u_aparatu.kolicina_50cent
				|| kusur.kolicina_20cent > kolicine_kovanica_u_aparatu.kolicina_20cent
				|| kusur.kolicina_10cent > kolicine_kovanica_u_aparatu.kolicina_10cent
				)
			{
				// odustani jer u aparatu nema dovoljno za vratiti
				std::cout << "U aparatu nema dovoljno novca za vratiti" << std::endl;
				std::cout << "Vracam " << ubaceni_novac << "EUR" << std::endl;
			}
			else {
				// ima dovoljno kovanica za vratiti
				// izvrsi transakciju

				// artikl je izbacen van iz aparata
				std::cout << "Izbacujem proizvod (Cola)" << std::endl;
				aparat.katalog[izabrani_proizvod].preostalo_artikala--;
				// vracen je kusur
				if (kusur.kolicina_10cent) {
					std::cout << "Vracam " << kusur.kolicina_10cent << "x 0.1 EUR " << std::endl;
					aparat.kolicine_kovanica.kolicina_10cent -= kusur.kolicina_10cent;
				}
				if (kusur.kolicina_20cent) {
					std::cout << "Vracam " << kusur.kolicina_20cent << "x 0.2 EUR " << std::endl;
					aparat.kolicine_kovanica.kolicina_20cent -= kusur.kolicina_20cent;
				}
				if (kusur.kolicina_50cent) {
					std::cout << "Vracam " << kusur.kolicina_50cent << "x 0.5 EUR " << std::endl;
					aparat.kolicine_kovanica.kolicina_50cent -= kusur.kolicina_50cent;
				}
				if (kusur.kolicina_1eur) {
					std::cout << "Vracam " << kusur.kolicina_1eur << "x 1 EUR " << std::endl;
					aparat.kolicine_kovanica.kolicina_1eur -= kusur.kolicina_1eur;
				}
				if (kusur.kolicina_2eur) {
					std::cout << "Vracam " << kusur.kolicina_2eur << "x 2 EUR " << std::endl;
					aparat.kolicine_kovanica.kolicina_2eur -= kusur.kolicina_2eur;
				}
			}
		}

		PrintSeparatorLine();
	}
}
