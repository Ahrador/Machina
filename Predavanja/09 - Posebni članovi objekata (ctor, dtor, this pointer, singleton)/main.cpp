#include <iostream>
using namespace std;


// Predavanje 9 (10.6.2023.)
// Posebni clanovi objekata - konstruktor, destruktor, this pointer, class clanovi, singleton.
/*
Konstruktor (Constructor):
Konstruktor je posebna metoda unutar klase koja se automatski poziva prilikom stvaranja 
objekta te klase. On se koristi za inicijalizaciju članova objekta i izvođenje drugih 
potrebnih operacija prije nego što objekt bude spreman za upotrebu. Konstruktor ima isto 
ime kao i klasa u kojoj se nalazi. Primjer konstruktora u C++-u:
*/

class Osoba {
public:
    string ime;
    int godine;

    Osoba(string i, int g) {
        ime = i;
        godine = g;
    }
};

int main() {
    Osoba osoba1("Marko", 25);
    // Konstruktor je pozvan prilikom stvaranja objekta osoba1
    return 0;
}

// --------------------------------------------------------------------------------------

/*
Destruktor (Destructor):
Destruktor je također posebna metoda unutar klase, ali se poziva automatski prilikom 
uništavanja objekta te klase. Destruktor se koristi za oslobađanje resursa koje je objekt 
zauzeo tijekom svog životnog vijeka, kao što su dinamički alocirane memorije ili otvoreni 
tokovi. Destruktor ima isto ime kao i klasa, ali počinje znakom tilde (~) ispred. 
Primjer destruktora u C++-u:
*/

class Osoba {
public:
    string ime;
    int godine;

    Osoba(string i, int g) {
        ime = i;
        godine = g;
    }

    ~Osoba() {
        // Destruktor koji oslobađa resurse
    }
};

int main() {
    Osoba osoba1("Marko", 25);
    // Destruktor će biti pozvan prilikom uništavanja objekta osoba1
    return 0;
}

// --------------------------------------------------------------------------------------

/*
Pokazivač "this" (This Pointer):
"this" je pokazivač unutar metoda klase koji pokazuje na trenutni objekt na kojem je 
metoda pozvana. Koristi se za razlikovanje lokalnih varijabli od članova objekta koji 
imaju isto ime. Pokazivač "this" omogućuje pristup članovima objekta unutar metode. 
Primjer korištenja pokazivača "this" u C++-u:
*/

class Osoba {
public:
    string ime;

    void postaviIme(string ime) {
        this->ime = ime;
    }
};

int main() {
    Osoba osoba1;
    osoba1.postaviIme("Marko");
    // Pokazivač "this" omogućuje pristup članu ime objekta osoba1 unutar metode postaviIme
    return 0;
}

// --------------------------------------------------------------------------------------

/*
Članovi klase (Class Members):
Članovi klase su varijable i funkcije definirane unutar klase. Mogu biti privatni (samo 
dostupni unutar same klase), javni (dostupni izvan klase) ili zaštićeni (dostupni samo u 
klasi i u nasljeđenim klasama). Članovi klase omogućavaju pohranjivanje podataka i 
definiranje funkcionalnosti specifične za tu klasu. Primjeri članova klase u C++-u:
*/

class Osoba {
public:
    string ime; // Javni član klase

private:
    int godine; // Privatni član klase

protected:
    void pozdravi() { // Zaštićeni član klase
        cout << "Pozdrav, ja sam " << ime << endl;
    }
};

int main() {
    Osoba osoba1;
    osoba1.ime = "Marko"; // Pristup javnom članu klase
    // osoba1.godine = 25; // Greška - pristup privatnom članu klase nije dozvoljen izvan klase
    // osoba1.pozdravi(); // Greška - pristup zaštićenom članu klase nije dozvoljen izvan klase

    return 0;
}

// --------------------------------------------------------------------------------------

/*
Singleton:
Singleton je dizajn uzorak koji ograničava instanciranje klase na samo jedan objekt. 
To znači da postoji samo jedna jedinstvena instanca klase koja je globalno dostupna. 
Singleton se često koristi kada želimo da postoji samo jedan objekt koji kontrolira 
određene resurse ili kada želimo dijeliti podatke između različitih dijelova programa. 
Primjer singletona u C++-u:
*/

class Singleton {
private:
    static Singleton* instance;
    int brojac;

    Singleton() {
        brojac = 0;
    }

public:
    static Singleton* getInstance() {
        if (!instance) {
            instance = new Singleton();
        }
        return instance;
    }

    void povecajBrojac() {
        brojac++;
    }

    int getBrojac() {
        return brojac;
    }
};

Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* objekt1 = Singleton::getInstance();
    objekt1->povecajBrojac();
    cout << objekt1->getBrojac() << endl; // Ispis: 1

    Singleton* objekt2 = Singleton::getInstance();
    objekt2->povecajBrojac();
    cout << objekt2->getBrojac() << endl; // Ispis: 2

    return 0;
}
