#include <iostream>
using namespace std;

// Ispis svih ASCII znakova

int main() {

    for (int i = 0; i <= 255; i++) {
        cout << i << ": " << (char)i << endl;
    }
}