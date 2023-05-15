#include <iostream>
using namespace std;

int main() {

	// For petlje
	// Write a program to print the numbers from 1 to 10 using a for loop.
	for (int i = 1; i <= 10; i++) { // i je na 1 a ne na 0 jer je cilj isprintat brojeve od 1-10 a ne 0-10
		cout << i << " " << endl;
	}

	// Write a program to calculate the sum of all numbers from 1 to 100 using a for loop.
	int sum = 0;

	for (int i = 1; i <= 100; i++) {
		sum += i;
		cout << "Sum of all numbers from 1 to 100: " << sum << endl;
	}

	// Write a program to print the multiplication table of a given number using a for loop.
	int broj;
	cout << "Unesite broj: ";
	cin >> broj;

	for (int i = 1; i <= 10; i++) {
		cout << broj << " x " << i << " = " << (broj * i) << endl;
	}

	// If-else
	// Napišite program koji će provjeriti je li uneseni broj pozitivan, negativan ili jednak nuli.
	int number;
	cout << "Unesi broj: ";
	cin >> number;

	if (number < 0) {
		cout << "Broj je negativan" << endl;
	}
	else if (number == 0) {
		cout << "Broj je jednak nuli" << endl;
	}
	else {
		cout << "Broj je pozitivan" << endl;
	}

	// Napišite program koji će provjeriti je li uneseni broj paran ili neparan. Ispisati odgovarajuću poruku za svaki slučaj.
	int brojikus;
	cout << "Upisi brojario: ";
	cin >> brojikus;

	if (brojikus % 2 == 0) {
		cout << "Broj je paran." << endl;
	}
	else cout << "Broj je neparan." << endl;

	// Provjera ocjene. Napišite program koji će provjeriti je li unesena ocjena vrednovanja (1 - 5) dovoljna za prolazak.Ispisati odgovarajuću poruku za svaki slučaj.
	int ocjena;
	cout << "Upisi ocjenu: ";
	cin >> ocjena;

	if (ocjena == 1) {
		cout << "Nedovoljan" << endl;
	}
	else if (ocjena == 2) {
		cout << "Dovoljan" << endl;
	}
	else if (ocjena == 3) {
		cout << "Dobar" << endl;
	}
	else if (ocjena == 4) {
		cout << "Vrlo dobar" << endl;
	}
	else if (ocjena == 5) {
		cout << "Odličan" << endl;
	}
}