#include <iostream>
using namespace std;

// Triple equality check

/*
Napiši funkciju koja prima tri argumenta i vraća true ako su svi isti, 
a false ako nisu.
*/


// Funkcija koja provjerava jesu li sva tri argumenta ista
bool triple_kill(int a, int b, int c) {  // bool jer je true/false
	if (a == b && b == c) { 
		cout << true;
	}
	else {
		return false;
	}
}

int main() {
	// Brojevi upisani
	int prvi_argument = 10;
	int drugi_argument = 3;
	int treci_argument = 8;
	if (triple_kill(prvi_argument, drugi_argument, treci_argument)) {
		cout << "Svi brojevi su isti" << endl;
	}
	else {
		cout << "Nisu svi isti" << endl;
	}
	return 0;
}