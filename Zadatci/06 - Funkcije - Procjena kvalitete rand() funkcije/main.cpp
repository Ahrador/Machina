#include <iostream>
#include <cstdlib> // za korištenje funkcije std::rand
#include <ctime> // za korištenje funkcije std::srand
using namespace std;

// Procjena kvalitete rand() funkcije

/*
Generirajte milijun slučajnih brojeva između 1 i 100.
Ispišite koliko se puta pojavio svaki broj.

Pojavljuju li se svi brojevi otprilike jednako puta?
Za svaki broj napiši koliko njegovo pojavljivanje odstupa od očekivanog prosjeka, i
na temelju toga donesi ocjenu kvalitete tog generatora slučajnih brojeva.

Ponovite postupak, sa 10 milijuna slučajnih brojeva iz istog raspona. Ocijenite
koliko se kvaliteta RNG-a promijenila.
*/

int main() {
    // Granice raspona brojeva koje treba generirati (1-100)
    const int minBroj = 1;
    const int maxBroj = 100;

    // Koliko slučajnih brojeva treba generirati (1 milijun)
    const int količinaVrijednosti = 1'000'000;

    int brojač[maxBroj] = { 0 }; // Niz za brojanje koliko se puta pojavio svaki broj

    // Postavljanje seed-a za generator slučajnih brojeva na trenutno vrijeme 
    // Svaki puta kad se pokrene program, generirani niz brojeva če biti drugačiji
    std::srand(std::time(0));


    // Za svaku iteraciju petlje, generiramo slučajan broj između minBroj i maxBroj koristeći std::rand().
    for (int i = 0; i < količinaVrijednosti; i++) {
        int randomNumber = minBroj + (std::rand() % (maxBroj - minBroj + 1));
        brojač[randomNumber - 1]++; // Povećaj brojač za generirani broj
    }

    // Ova petlja ispisuje rezultate brojanja. Prolazimo kroz svaki broj od 1 do maxNumber i ispisujemo koliko se puta pojavio taj broj.
    for (int i = 0; i < maxBroj; i++) {
        std::cout << "Broj " << (i + 1) << " se pojavio " << brojač[i] << " puta." << std::endl;
    }

    /*
    Ovdje računamo očekivanu prosječnu vrijednost broja pojavljivanja za svaki broj.
    To činimo dijeljenjem ukupnog broja generiranih brojeva količinaVrijednosti s brojem
    mogućih brojeva maxBroj. Korištenje static_cast<double> osigurava da rezultat
    dijeljenja bude decimalni broj, a ne cjeli broj.
    */
    double očekivaniProsjek = količinaVrijednosti / static_cast<double>(maxBroj);


    /*
    Ovdje ocjenjujemo kvalitetu generatora slučajnih brojeva. Prolazimo kroz svaki broj
    od 1 do maxBroj i izračunavamo odstupanje između broja pojavljivanja brojač[i] i
    očekivanog prosjeka očekivaniProsjek. To odstupanje pohranjujemo u varijablu devijacija
    i ispisujemo ga zajedno s brojem na standardni izlaz.
    */
    std::cout << "\nProcjena kvalitete slucajnih brojeva:" << std::endl;
    for (int i = 0; i < maxBroj; i++) {
        int devijacija = brojač[i] - očekivaniProsjek;
        std::cout << "Broj " << (i + 1) << " devijacija: " << devijacija << std::endl;
    }

    // -------------------------------------------------------------------------------------

    /*
    ponavljamo postupak generiranja i brojanja slučajnih brojeva, ovaj put s 10 milijuna
    (10,000,000) brojeva. Pohranjujemo broj pojavljivanja svakog broja u novo polje noviBrojač
    i ponovno ocjenjujemo kvalitet generatora, uspoređujući odstupanje novih rezultata s
    očekivanim prosjekom.
    Konačno, vraćamo 0 iz glavne funkcije main() kako bismo označili uspješan završetak
    programa.
    */

    const int novaKoličinaVrijednosti = 10000000;
    int noviBrojač[maxBroj] = { 0 };

    for (int i = 0; i < novaKoličinaVrijednosti; i++) {
        int randomNumber = minBroj + (std::rand() % (maxBroj - minBroj + 1));
        noviBrojač[randomNumber - 1]++;
    }

    std::cout << "\nProcjena promjene kvalitete generatora slucajnih brojeva:" << std::endl;
    for (int i = 0; i < maxBroj; i++) {
        int devijacija = noviBrojač[i] - očekivaniProsjek;
        std::cout << "Broj " << (i + 1) << " devijacija: " << devijacija << std::endl;
    }

    return 0;
}