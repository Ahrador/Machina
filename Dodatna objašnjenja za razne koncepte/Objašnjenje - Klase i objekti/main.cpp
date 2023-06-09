#include <iostream>
using namespace std;

// Dodatno objašnjenje - Klase i objekti 

/*
Klasa je šablonski oblik ili definicija koja opisuje kako će objekti izgledati i kako će se ponašati. 
Možete zamisliti klasu kao "plan" ili "projekciju" za stvaranje objekata. U klasama možete definirati 
varijable, funkcije i druge podatke i operacije koje objekti mogu koristiti. 
Na primjer, možete imati klasu "Automobil" koja ima varijable poput boje, brzine i funkcije poput 
"ubrzaj" ili "koči".

Objekat je konkretan primjerak klase. Kada stvorite objekat, stvarate instancu klase prema definiciji 
koju ste postavili. Možete zamisliti objekat kao "kopiju" ili "stvarni primjerak" klase. Na primjer, 
ako imate klasu "Automobil", objekt je određeni automobil, poput crvenog automobila s brzinom od 50 km/h.

*/

// Definicija klase
class Automobil {
public:
    // Varijable
    std::string boja;
    int brzina;

    // Metode (funkcije)
    void ubrzaj(int novaBrzina) {
        brzina = novaBrzina;
    }

    void prikaziPodatke() {
        std::cout << "Boja: " << boja << std::endl;
        std::cout << "Brzina: " << brzina << " km/h" << std::endl;
    }
};

int main() {
    // Stvaranje objekta
    Automobil mojAuto;

    // Pristupanje varijablama objekta i pozivanje metoda
    mojAuto.boja = "Crvena";
    mojAuto.brzina = 50;
    mojAuto.prikaziPodatke();

    mojAuto.ubrzaj(80);
    mojAuto.prikaziPodatke();

    return 0;
}

/*
U ovom primeru, definiramo klasu "Automobil" koja ima varijable "boja" i "brzina" te metode "ubrzaj" i
"prikaziPodatke". Zatim u funkciji main() stvaramo objekat mojAuto tipa Automobil i koristimo operator 
točke (.) da pristupimo varijablama i metodama objekta.
*/