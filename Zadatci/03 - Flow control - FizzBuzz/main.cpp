#include <iostream>
using namespace std;

// FizzBuzz

/*
Napišite program koji sa konzole učita neki broj.

Ako je broj djeljiv s 3, treba ispisati "Fizz".
Ako je broj djeljiv s 5, treba ispisati "Buzz".
Ako je broj djeljiv i sa 3 i sa 5, treba ispisati "FizzBuzz!".
*/


int main() {

    int broj;
    cout << "Upisi broj: ";
    cin >> broj;

    if (broj % 3 == 0 && broj % 5 == 0) {
        cout << "FizzBuzz!" << endl; // Ispisuje "FizzBuzz!" ako je broj djeljiv s 3 i 5
    }
    if (broj % 3 == 0 && broj % 15 != 0) {
        cout << "Fizz" << endl; // Ispisuje "Fizz" ako je broj djeljiv samo s 3, ali ne i s 15
    }
    if (broj % 5 == 0 && broj % 15 != 0) {
        cout << "Buzz" << endl; // Ispisuje "Buzz" ako je broj djeljiv samo s 5, ali ne i s 15
    }
}