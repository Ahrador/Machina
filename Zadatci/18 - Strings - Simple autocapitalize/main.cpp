#include <iostream>
#include <string>
#include <cctype>
/*
Ova linija uključuje biblioteku <cctype> koja pruža funkcionalnosti za rad s 
karakterima, uključujući provjeru vrste znaka, konverziju u velika/mala slova i druge 
srodne operacije.
*/

// Simple autocapitalize

/*
Napiši funkciju koja prima std::string, prvo slovo na početku svake rečenice u 
stringu postavi na veliko slovo, te vrati rezultantni string.
*/


// Funkcija za kapitalizaciju prvog slova u svakoj rečenici u nizu
std::string capitalizeSentences(const std::string& input) {
    std::string result;  // Rezultujući string koji će sadržavati transformirani tekst
    bool capitalizeNext = true;  // Promjenljiva koja označava da li treba velikim slovom napisati sljedeći karakter

    for (char c : input) {
        // Petlja prolazi kroz sve karaktere u ulaznom stringu

        if (capitalizeNext && std::isalpha(c)) {
            // Provjera da li treba velikim slovom napisati trenutni karakter, ako je slovo

            result += std::toupper(c);  // Dodavanje trenutnog karaktera u rezultujući string pretvorenog u veliko slovo
            capitalizeNext = false;  // Postavljanje promjenljive na false jer smo već napisali karakter velikim slovom
        }
        else {
            result += c;  // Dodavanje trenutnog karaktera u rezultujući string onakav kakav jeste (neveliko slovo)
        }

        if (c == '.' || c == '?' || c == '!') {
            // Provjera da li je trenutni karakter tačka, upitnik ili uzvičnik

            capitalizeNext = true;  // Postavljanje promjenljive na true jer sljedeći karakter u rečenici treba biti velikim slovom
        }
    }
    return result;  // Vraćanje rezultujućeg stringa sa transformiranim tekstom
}

int main() {
    std::string input;
    std::cout << "Unesite rečenicu: ";
    std::getline(std::cin, input);

    // Poziva se funkcija capitalizeSentences za kapitalizaciju unesene rečenice
    std::string capitalized = capitalizeSentences(input);
    std::cout << "Kapitalizirana rečenica: " << capitalized << std::endl;

    return 0;
}

