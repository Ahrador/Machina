#include <iostream>
using namespace std;

// FizzBuzz

int main() {

    int broj;
    cout << "Upisi broj: ";
    cin >> broj;

    if (broj % 3 == 0 && broj % 5 == 0) {
        cout << "FizzBuzz!" << endl;
    }
        if (broj % 3 == 0) {
            cout << "Fizz" << endl;
        }
          if (broj % 5 == 0) {
              cout << "Buzz" << endl;
          }
}