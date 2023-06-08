#include <iostream>
#include <cstdlib> // za generiranje slučajnih brojeva
#include <ctime> // za postavljanje sjemena slučajnog brojača
using namespace std;

// Loto 6/45

/*
Napišite program koji simulira igranje lutrije "Lotto 6/45".

- Od igrača se na početku treba učitati 6 brojeva koji su između 1 i 45.
- Svih 6 brojeva moraju biti različiti.
- Nakon toga program generira 6 slučajnih brojeva između 1 i 45.
- Svih 6 generiranih brojeva moraju biti različiti.
- Nakon toga program ispiše igraču koliko je brojeva pogodio, i koje.
*/

int main() {

    // Definicija konstanti za broj brojeva koje igrač treba odabrati
    const int broj_odabira = 6;

    // Definicija konstanti za ukupan broj brojeva u lutriji
    const int ukupanBrojULutriji = 45;

    // Deklaracija dva niza
    int odabraniBrojevi[broj_odabira]; // za spremanje odabranih brojeva igrača
    int generiraniBrojevi[broj_odabira]; // za spremanje slučajno generiranih brojeva

    cout << "Unesi 6 brojeva između 1 i 45: " << endl;
    for (int i = 0; i < broj_odabira; i++) {
        cin >> odabraniBrojevi[i];

        // Provjeri ispravnost unosa
        if (odabraniBrojevi[i] < 1 || odabraniBrojevi[i] > ukupanBrojULutriji) {
            cout << "Odabrali ste broj izvan raspona 1-45. Molimo pokušajte ponovno." << endl;
            return 0; // Izlaz iz programa jer je unos neispravan
        }

        // Provjeri duplikate
        for (int j = 0; j < i; j++) {
            if (odabraniBrojevi[j] == odabraniBrojevi[i]) {
                cout << "Duplikati nisu dozvoljeni. Molimo pokušajte ponovno." << endl;
                return 0; // Izlaz iz programa jer je unos neispravan
            }
        }
    }

    // Inicijalizacija generatora slučajnih brojeva
    srand(time(nullptr));

    // Generiranje 6 slučajnih brojeva
    for (int i = 0; i < broj_odabira; i++) {
        bool duplikat;
        int broj;

        do {
            broj = rand() % ukupanBrojULutriji + 1;

            // Provjeri duplikate
            duplikat = false;
            for (int j = 0; j < i; j++) {
                if (generiraniBrojevi[j] == broj) {
                    duplikat = true;
                    break;
                }
            }
        } while (duplikat);

        generiraniBrojevi[i] = broj;
    }

    // Ispis generiranih brojeva
    cout << "Generirani brojevi su: ";
    for (int i = 0; i < broj_odabira; i++) {
        cout << generiraniBrojevi[i] << " ";
    }
    cout << endl;

    // Provjeri koliko brojeva je igrač pogodio
    int brojPogodaka = 0;
    cout << "Pogodili ste sljedeće brojeve: ";
    for (int i = 0; i < broj_odabira; i++) {
        for (int j = 0; j < broj_odabira; j++) {
            if (odabraniBrojevi[i] == generiraniBrojevi[j]) {
                cout << odabraniBrojevi[i] << " ";
                brojPogodaka++;
                break;
            }
        }
    }
    cout << endl;
    cout << "Broj pogodaka: " << brojPogodaka << endl;
    return 0;
}