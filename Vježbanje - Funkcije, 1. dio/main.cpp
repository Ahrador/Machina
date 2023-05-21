#include <iostream>
#include <string>
using namespace std;

// 1. Napišite funkciju koja vraća zbroj dva broja.
int zbroji(int prvi, int drugi) {
	return prvi + drugi;
}

// 2. Napišite funkciju koja provjerava je li dani broj paran.
bool jeParan(int broj) {
	if (broj % 2 == 0) {
		return true;
	}
	else {
		return false;
	}
}

// 3. Napišite funkciju koja vraća faktorijel broja N.
int faktorijelBrojaN(int N) {
	int result = 1;
	for (int i = 1; i <= N; i++) {
		result *= 1;
	}
	return result;
}

// 4. Napišite funkciju koja vraća najveći od tri dana broja.
int vratiNajveci(int one, int two, int three) {
	int najveci = one; 
	if (two > najveci) {
		najveci = two;
	}
	if (three > najveci) {
		najveci = three;
	}
	return najveci;
}

int main() {
	// 1. zadatak
	int prviBroj = 4;
	int drugiBroj = 3;
	int rezultat = zbroji(prviBroj, drugiBroj);
	cout << "Zbroj: " << rezultat << endl;

	// 2. zadatak
	int broj;
	cout << "Unesi broj: " << endl;
	cin >> broj;

	if (jeParan(broj)) {
		cout << "Broj je paran." << endl;
	}
	else {
		cout << "Broj je neparan." << endl;
	}

	// 3. zadatak
	int number;
	cout << "Unesi brojario: ";
	cin >> number;

	int result = faktorijelBrojaN(number);
	cout << "Faktorijel broja " << number << " je " << result << endl;

	// 4. zadatak
	int one, two, three;
	cout << "Unesite tri broja: ";
	cin >> one >> two >> three;

	// U rezultat se poziva funkcija te argumenti
	int rezultatikus = vratiNajveci(one, two, three);
	cout << "Najveci broj je: " << rezultatikus << endl;
}