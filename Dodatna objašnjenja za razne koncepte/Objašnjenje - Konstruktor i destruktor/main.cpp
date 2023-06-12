#include <iostream>

// Dodatno objašnjenje - Konstruktor i destruktor

// PRVI PRIMJER -------------------------------------------------------

#include <iostream>

class MojObjekt {
public:
    MojObjekt() {
        std::cout << "Pozvan je konstruktor!" << std::endl;
    }

    ~MojObjekt() {
        std::cout << "Pozvan je destruktor!" << std::endl;
    }
};

int main() {
    // Stvaranje objekta
    MojObjekt objekt; // Pozvat će se konstruktor

    // ...

    // Kraj programa
    return 0; // Pozvat će se destruktor
}

/*
U ovom primjeru definiramo klasu MojObjekt s konstruktorom i destruktorom. Kada 
stvorimo objekt objekt tipa MojObjekt, konstruktor će se automatski pozvati i 
ispisati poruku "Pozvan je konstruktor!" na standardni izlaz. Kada program dođe 
do kraja, destruktor će se automatski pozvati i ispisati poruku "Pozvan je 
destruktor!".

Ova jednostavna demonstracija pokazuje kako konstruktor i destruktor rade u vezi 
s objektima. U pravim scenarijima, konstruktor i destruktor mogu obavljati 
složenije zadatke, kao što je alociranje i dealociranje memorije, inicijalizacija 
članova objekta, otvaranje i zatvaranje datoteka, itd.
*/


// DRUGI PRIMJER -------------------------------------------------------
class Rectangle {
private:
    int length;
    int width;

public:
    // Konstruktor
    Rectangle(int len, int wid) {
        length = len;
        width = wid;
        std::cout << "Kreiran pravokutnik." << std::endl;
    }

    // Destruktor
    ~Rectangle() {
        std::cout << "Uništen pravokutnik." << std::endl;
    }

    void calculateArea() {
        int area = length * width;
        std::cout << "Površina pravokutnika: " << area << std::endl;
    }
};

int main() {
    // Stvaranje objekta pravokutnik
    Rectangle rect(5, 3);

    // Pozivanje metode za izračunavanje površine
    rect.calculateArea();

    // Kraj programa
    return 0;
}

/*
U ovom primjeru, klasa "Rectangle" predstavlja pravokutnik s određenom duljinom 
i širinom. Konstruktor se koristi za inicijalizaciju objekta pravokutnik s 
zadanim vrijednostima duljine i širine. 

Destruktor se poziva kad objekt pravokutnik više nije potreban i služi za čišćenje 
i oslobađanje resursa koji su možda bili zauzeti tijekom životnog vijeka objekta.

U glavnoj funkciji main(), stvaramo objekt rect klase Rectangle s duljinom 5 i 
širinom 3. Nakon toga, pozivamo metodu calculateArea() koja izračunava površinu 
pravokutnika i ispisuje je. 

Na kraju programa, kada objekt rect izađe iz dosega (scope), poziva se destruktor 
koji ispisuje poruku "Uništen pravokutnik".
*/