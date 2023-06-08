#include <iostream>
using namespace std;

// Ispis svih ASCII znakova

/*
Koristeći petlju po vašem izboru, pošaljite na konzolu sve char vrijednosti 
(0-255, odnosno -128 do 127).
Ispis izvršite tako da se u svakom redu ispiše: redni broj (tj. vrijednost 0 - 255), 
dvotočka ili crta, te taj znak.

Očekivani ispis je nešto u obliku:

0: ???
1: ???
2: ???
3: ???
// ... i tako sve do 255
*/


int main() 
{
    for (int i = 0; i <= 255; i++) {
        std::cout << i << ": " << (char)i << std::endl;
    }
}