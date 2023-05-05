#include <iostream>
using namespace std;

// () {} [] <> || ""

// Krizic Kruzic zadatak

int main() {
	// setup
	char polje[9];
	char trenutni_potez = 'x';

	// Inicijalizacija niza 
	for (int i = 0; i < 9; i ++)
		polje[i] = ' ';
	cout << "Dobrodosli u igru Krizic Kruzic!" << endl;

	while (true) { 
		// Crtanje polja
		for (int i = 0; i < 9; i += 3) {
			cout << "------" << endl;
			cout << polje[i] << '|' << polje[i + 1] << '|' << polje[i + 2] << endl;
			}
		cout << "------" << endl;
	
		// User input
		int koordinata;
		cout << "Na redu je igrac " << trenutni_potez << endl;
		cout << "Unesi index polja (0-8) u koje zelis staviti svoj znak: " << endl;
		cin >> koordinata;
		if (koordinata > 8 || koordinata < 0) 
		{
			cout << "Unesi index polja (0-8) u koje zelis staviti svoj znak: " << endl;
			cin >> koordinata;
		}
		

		// Modify world
		polje[koordinata] = trenutni_potez; // na koordinatu koju nam je dao igrac, stavi njeg znak

		// Provjera pobjede
		if (
			(polje[0] == polje[1] && polje[1] == polje[2] && polje[0] != ' ') ||
			(polje[3] == polje[4] && polje[4] == polje[5] && polje[3] != ' ') ||
			(polje[6] == polje[7] && polje[7] == polje[8] && polje[6] != ' ') ||
			(polje[0] == polje[3] && polje[3] == polje[6] && polje[0] != ' ') ||
			(polje[1] == polje[4] && polje[4] == polje[7] && polje[1] != ' ') ||
			(polje[2] == polje[5] && polje[5] == polje[8] && polje[2] != ' ') ||
			(polje[2] == polje[4] && polje[4] == polje[6] && polje[2] != ' ') ||
			(polje[0] == polje[4] && polje[4] == polje[8] && polje[0] != ' '))
		{
			// Opcija za novu igru
			cout << "Pobjednik je " << trenutni_potez << ". Zelite li ponovno igrati (da/ne)?" << endl;
			string odgovor_igraca;
			cin >> odgovor_igraca;
			if (odgovor_igraca == "da" || odgovor_igraca == "Da" || odgovor_igraca == "DA")
			{
				// Reset ploče za novu igru
				for (int i = 0; i < 9; i++)
					polje[i] = ' ';
			}
			else
				cout << "Hvala na igranju. Dodite nam opet!" << endl;
		}
		else {
			trenutni_potez = 'o'; // prebacivanje poteza na sljedeceg igraca
		}
		{
			// Crtanje polja
				for (int i = 0; i < 9; i += 3) {
					cout << "------" << endl;
					cout << polje[i] << '|' << polje[i + 1] << '|' << polje[i + 2] << endl;
				}
			cout << "------" << endl;
		}

		// User input
		cout << "Na redu je igrac " << trenutni_potez << endl;
		cout << "Unesi index polja (0-8) u koje zelis staviti svoj znak: " << endl;
		cin >> koordinata; // vrijednosti od 1-9
		if (koordinata > 8 || koordinata < 0)
		{
		cout << "Unesi index polja (0-8) u koje zelis staviti svoj znak: " << endl;
		cin >> koordinata; // vrijednosti od 1-9"
		}
		// Modify world
		polje[koordinata] = trenutni_potez; // na koordinatu koju nam je dao igrac, stavi njeg znak

		// Prebacivanje na drugog igraca
		if (trenutni_potez == 'x') {
			trenutni_potez = 'o';
		}
		else {
			trenutni_potez = 'x';
		}
	}
	return 0;

}