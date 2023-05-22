#include <iostream>
using namespace std;

int main(){
    /*
    For petlja je konstrukcija u programiranju koja se koristi za ponavljanje 
    određenog bloka koda određeni broj puta. Ona vam omogućava izvršavanje istog 
    koda nekoliko puta bez potrebe za ponavljanjem istog koda ručno.

    For petlja se sastoji od tri dijela:

    Inicijalizacija: 
    Ovdje postavljate početnu vrijednost za brojač petlje. Obično se koristi 
    varijabla koja će se koristiti kao brojač petlje.

    Uvjet: 
    Uvjet je izraz koji se provjerava prije svakog prolaza petlje. Ako je uvjet 
    ispunjen (true), petlja će se nastaviti izvršavati. Ako je uvjet netačan 
    (false), petlja će se završiti.

    Inkrement (ili dekrement): 
    Ovdje određujete kako se brojač petlje mijenja nakon svakog prolaza petlje. 
    Obično se koristi inkrement (povećanje) ili dekrement (smanjenje) brojača.
    */

    // Primjer jednostavne for petlje:
    for (int i = 0; i < 5; i++) {
        // Blok koda koji će se izvršiti u svakom prolazu petlje
        std::cout << i << " ";
    }

    /*
    U ovom gore primjeru:

    Inicijalizacija: int i = 0 postavlja brojač i na početnu vrijednost 0.
    Uvjet: i < 5 provjerava je li brojač i manji od 5. Ako je to točno, petlja će se 
       nastaviti izvršavati.
    Inkrement: i++ povećava vrijednost brojača i za 1 nakon svakog prolaza petlje.
    Blok koda std::cout << i << " "; će se izvršiti u svakom prolazu petlje i 
    ispisati vrijednost brojača i.

    Ova petlja će se izvršiti 5 puta, s vrijednostima brojača i od 0 do 4, i 
    ispisati: 0 1 2 3 4.
    */

    // DODATNI PRIMJERI:

    // 1. Ispis brojeva od 1 do 5:
    for (int i = 1; i <= 5; i++) {
        std::cout << i << " ";
    }


    // 2. Ispis brojeva od 10 do 1 unatrag:
    for (int i = 10; i >= 1; i--) {
        std::cout << i << " ";
    }


    // 3. Ispis parnih brojeva od 0 do 10:
    for (int i = 0; i <= 10; i += 2) {
        std::cout << i << " ";
    }


    // 4. Zbroj brojeva od 1 do 10:
    int suma = 0;
    for (int i = 1; i <= 10; i++) {
        suma += i;
    }
    std::cout << "Zbroj: " << suma << std::endl;


    // 5. Ispis slova abecede:
    for (char c = 'a'; c <= 'z'; c++) {
        std::cout << c << " ";
    }
    // Ova petlja će ispisati sva mala slova abecede od 'a' do 'z', inkrementirajući karakter c za 1 u svakom prolazu.


    // 6. Ispis faktorijela broja:
    int broj = 5;
    int faktorijel = 1;
    for (int i = 1; i <= broj; i++) {
        faktorijel *= i;
    }
    std::cout << "Faktorijel broja " << broj << " je " << faktorijel << std::endl;
    // Ova petlja će izračunati faktorijel broja 5, množeći sve brojeve od 1 do 5. Nakon petlje, ispisuje se dobiveni faktorijel.


    // 7. Prolazak kroz elemente niza unatrag:
    int niz[] = { 1, 2, 3, 4, 5 };
    int velicina = sizeof(niz) / sizeof(niz[0]);

    for (int i = velicina - 1; i >= 0; i--) {
        std::cout << niz[i] << " ";
    }
    /*
    Na primjer, ako je veličina niza 5, velicina - 1 će biti 4, što je indeks 
    posljednjeg elementa. Započinjanje brojača petlje s ovim indeksom znači da 
    će petlja započeti prolazak od posljednjeg elementa prema prvom elementu.

    Ova inicijalizacija omogućuje petlji da započne s pravilnim indeksom i 
    osigurava prolazak kroz sve elemente niza unatrag.
    */
}