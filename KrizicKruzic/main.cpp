#include <iostream>
using namespace std;

// () {} [] <> || ""

// Krizic Kruzic zadatak

int main() {
	// setup
	char polje[9]; // index počinje od nule, tako da 0 - 8 (zadnji broj ne)
	char trenutni_potez = 'x';
	for (int i = 0; i < 9; i++)
		polje[i] = ' ';

	// Game step
	{

		// Crtanje polje
		// View -- transformacija iz raw data iz RAMA u nesto sto se vidi na ekranu
		cout
			<< "------" << endl
			<< polje[0] << '|' << polje[1] << '|' << polje[2] << endl // tako ce svaka 3 bit u svom redu
			<< "-+-+-" << endl
			<< polje[3] << '|' << polje[4] << '|' << polje[5] << endl
			<< "-+-+-" << endl
			<< polje[6] << '|' << polje[7] << '|' << polje[8] << endl
			<< "------" << endl;

		// User input
		int koordinata;
		cout << "Na redu je igrac " << trenutni_potez << endl;
		cout << "Unesi index polja (0-8) u koje zelis staviti svoj znak: " << endl;
		cin >> koordinata; // vrijednosti od 1-9

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
			(polje[2] == polje[3] && polje[3] == polje[6] && polje[2] != ' ') ||
			(polje[0] == polje[4] && polje[4] == polje[8] && polje[0] != ' '))
		{
			// Opcija za novu igru
			cout << "Pobjednik je " << trenutni_potez << ". Zelite li ponovno igrati (da/ne)?" << endl;
			string odgovor_igraca;
			cin >> odgovor_igraca;
			if (odgovor_igraca == "da" || odgovor_igraca == "Da" || odgovor_igraca == "DA")
			{
				for (int i = 0; i < 9; i++)
					polje[i] = ' ';
				// View -- transformacija iz raw data iz RAMA u nesto sto se vidi na ekranu
				cout
					<< "------" << endl
					<< polje[0] << '|' << polje[1] << '|' << polje[2] << endl
					<< "-+-+-" << endl
					<< polje[3] << '|' << polje[4] << '|' << polje[5] << endl
					<< "-+-+-" << endl
					<< polje[6] << '|' << polje[7] << '|' << polje[8] << endl
					<< "------" << endl;
			}
			else
				cout << "Hvala na igranju. Dodite nam opet!" << endl;
		}
		else {
			trenutni_potez = 'o'; // prebacivanje poteza na sljedeceg igraca
		}
		{
			cout
				<< "------" << endl
				<< polje[0] << '|' << polje[1] << '|' << polje[2] << endl
				<< "-+-+-" << endl
				<< polje[3] << '|' << polje[4] << '|' << polje[5] << endl
				<< "-+-+-" << endl
				<< polje[6] << '|' << polje[7] << '|' << polje[8] << endl
				<< "------" << endl;
		}

		// User input
		cout << "Na redu je igrac " << trenutni_potez << endl;
		cout << "Unesi index polja (0-8) u koje zelis staviti svoj znak: " << endl;
		cin >> koordinata; // vrijednosti od 1-9

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
			(polje[2] == polje[3] && polje[3] == polje[6] && polje[2] != ' ') ||
			(polje[0] == polje[4] && polje[4] == polje[8] && polje[0] != ' '))
		{
			// Opcija za novu igru
			cout << "Pobjednik je " << trenutni_potez << ". Zelite li ponovno igrati (da/ne?)" << endl;
			string odgovor_igraca;
			cin >> odgovor_igraca;
			if (odgovor_igraca == "da" || odgovor_igraca == "Da" || odgovor_igraca == "DA")
			{
				for (int i = 0; i < 9; i++)
					polje[i] = ' ';
				// View -- transformacija iz raw data iz RAMA u nesto sto se vidi na ekranu
				cout
					<< "------" << endl
					<< polje[0] << '|' << polje[1] << '|' << polje[2] << endl
					<< "-+-+-" << endl
					<< polje[3] << '|' << polje[4] << '|' << polje[5] << endl
					<< "-+-+-" << endl
					<< polje[6] << '|' << polje[7] << '|' << polje[8] << endl
					<< "------" << endl;
			}
			else
				cout << "Hvala na igranju. Dodite nam opet!" << endl;
		}
		else {
			trenutni_potez = 'x';  // prebacivanje poteza na sljedeceg igraca
		}
		{
			cout
				<< "------" << endl
				<< polje[0] << '|' << polje[1] << '|' << polje[2] << endl
				<< "-+-+-" << endl
				<< polje[3] << '|' << polje[4] << '|' << polje[5] << endl
				<< "-+-+-" << endl
				<< polje[6] << '|' << polje[7] << '|' << polje[8] << endl
				<< "------" << endl;
		}

		// User input
		cout << "Na redu je igrac " << trenutni_potez << endl;
		cout << "Unesi index polja (0-8) u koje zelis staviti svoj znak: " << endl;
		cin >> koordinata; // vrijednosti od 1-9

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
			(polje[2] == polje[3] && polje[3] == polje[6] && polje[2] != ' ') ||
			(polje[0] == polje[4] && polje[4] == polje[8] && polje[0] != ' '))
		{
			// Opcija za novu igru
			cout << "Pobjednik je " << trenutni_potez << ". Zelite li ponovno igrati (da/ne?)" << endl;
			string odgovor_igraca;
			cin >> odgovor_igraca;
			if (odgovor_igraca == "da" || odgovor_igraca == "Da" || odgovor_igraca == "DA")
			{
				for (int i = 0; i < 9; i++)
					polje[i] = ' ';
				// View -- transformacija iz raw data iz RAMA u nesto sto se vidi na ekranu
				cout
					<< "------" << endl
					<< polje[0] << '|' << polje[1] << '|' << polje[2] << endl
					<< "-+-+-" << endl
					<< polje[3] << '|' << polje[4] << '|' << polje[5] << endl
					<< "-+-+-" << endl
					<< polje[6] << '|' << polje[7] << '|' << polje[8] << endl
					<< "------" << endl;
			}
			else
				cout << "Hvala na igranju. Dodite nam opet!" << endl;
		}
		else {
			trenutni_potez = 'o';  // prebacivanje poteza na sljedeceg igraca
		}
		{
			cout
				<< "------" << endl
				<< polje[0] << '|' << polje[1] << '|' << polje[2] << endl
				<< "-+-+-" << endl
				<< polje[3] << '|' << polje[4] << '|' << polje[5] << endl
				<< "-+-+-" << endl
				<< polje[6] << '|' << polje[7] << '|' << polje[8] << endl
				<< "------" << endl;
		}

		// User input
		cout << "Na redu je igrac " << trenutni_potez << endl;
		cout << "Unesi index polja (0-8) u koje zelis staviti svoj znak: " << endl;
		cin >> koordinata; // vrijednosti od 1-9

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
			(polje[2] == polje[3] && polje[3] == polje[6] && polje[2] != ' ') ||
			(polje[0] == polje[4] && polje[4] == polje[8] && polje[0] != ' '))
		{
			// Opcija za novu igru
			cout << "Pobjednik je " << trenutni_potez << ". Zelite li ponovno igrati (da/ne?)" << endl;
			string odgovor_igraca;
			cin >> odgovor_igraca;
			if (odgovor_igraca == "da" || odgovor_igraca == "Da" || odgovor_igraca == "DA")
			{
				for (int i = 0; i < 9; i++)
					polje[i] = ' ';
				// View -- transformacija iz raw data iz RAMA u nesto sto se vidi na ekranu
				cout
					<< "------" << endl
					<< polje[0] << '|' << polje[1] << '|' << polje[2] << endl
					<< "-+-+-" << endl
					<< polje[3] << '|' << polje[4] << '|' << polje[5] << endl
					<< "-+-+-" << endl
					<< polje[6] << '|' << polje[7] << '|' << polje[8] << endl
					<< "------" << endl;
			}
			else
				cout << "Hvala na igranju. Dodite nam opet!" << endl;
		}
		else {
			trenutni_potez = 'x';  // prebacivanje poteza na sljedeceg igraca
		}
		{
			cout
				<< "------" << endl
				<< polje[0] << '|' << polje[1] << '|' << polje[2] << endl
				<< "-+-+-" << endl
				<< polje[3] << '|' << polje[4] << '|' << polje[5] << endl
				<< "-+-+-" << endl
				<< polje[6] << '|' << polje[7] << '|' << polje[8] << endl
				<< "------" << endl;
		}

		// User input
		cout << "Na redu je igrac " << trenutni_potez << endl;
		cout << "Unesi index polja (0-8) u koje zelis staviti svoj znak: " << endl;
		cin >> koordinata; // vrijednosti od 1-9

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
			(polje[2] == polje[3] && polje[3] == polje[6] && polje[2] != ' ') ||
			(polje[0] == polje[4] && polje[4] == polje[8] && polje[0] != ' '))
		{
			// Opcija za novu igru
			cout << "Pobjednik je " << trenutni_potez << ". Zelite li ponovno igrati (da/ne?)" << endl;
			string odgovor_igraca;
			cin >> odgovor_igraca;
			if (odgovor_igraca == "da" || odgovor_igraca == "Da" || odgovor_igraca == "DA")
			{
				for (int i = 0; i < 9; i++)
					polje[i] = ' ';
				// View -- transformacija iz raw data iz RAMA u nesto sto se vidi na ekranu
				cout
					<< "------" << endl
					<< polje[0] << '|' << polje[1] << '|' << polje[2] << endl
					<< "-+-+-" << endl
					<< polje[3] << '|' << polje[4] << '|' << polje[5] << endl
					<< "-+-+-" << endl
					<< polje[6] << '|' << polje[7] << '|' << polje[8] << endl
					<< "------" << endl;
			}
			else
				cout << "Hvala na igranju. Dodite nam opet!" << endl;
		}
		else {
			trenutni_potez = 'o';  // prebacivanje poteza na sljedeceg igraca
		}
		{
			cout
				<< "------" << endl
				<< polje[0] << '|' << polje[1] << '|' << polje[2] << endl
				<< "-+-+-" << endl
				<< polje[3] << '|' << polje[4] << '|' << polje[5] << endl
				<< "-+-+-" << endl
				<< polje[6] << '|' << polje[7] << '|' << polje[8] << endl
				<< "------" << endl;
		}

		// User input
		cout << "Na redu je igrac " << trenutni_potez << endl;
		cout << "Unesi index polja (0-8) u koje zelis staviti svoj znak: " << endl;
		cin >> koordinata; // vrijednosti od 1-9

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
			(polje[2] == polje[3] && polje[3] == polje[6] && polje[2] != ' ') ||
			(polje[0] == polje[4] && polje[4] == polje[8] && polje[0] != ' '))
		{
			// Opcija za novu igru
			cout << "Pobjednik je " << trenutni_potez << ". Zelite li ponovno igrati (da/ne?)" << endl;
			string odgovor_igraca;
			cin >> odgovor_igraca;
			if (odgovor_igraca == "da" || odgovor_igraca == "Da" || odgovor_igraca == "DA")
			{
				for (int i = 0; i < 9; i++)
					polje[i] = ' ';
				// View -- transformacija iz raw data iz RAMA u nesto sto se vidi na ekranu
				cout
					<< "------" << endl
					<< polje[0] << '|' << polje[1] << '|' << polje[2] << endl
					<< "-+-+-" << endl
					<< polje[3] << '|' << polje[4] << '|' << polje[5] << endl
					<< "-+-+-" << endl
					<< polje[6] << '|' << polje[7] << '|' << polje[8] << endl
					<< "------" << endl;
			}
			else
				cout << "Hvala na igranju. Dodite nam opet!" << endl;
		}
		else {
			trenutni_potez = 'x';  // prebacivanje poteza na sljedeceg igraca
		}
		{
			cout
				<< "------" << endl
				<< polje[0] << '|' << polje[1] << '|' << polje[2] << endl
				<< "-+-+-" << endl
				<< polje[3] << '|' << polje[4] << '|' << polje[5] << endl
				<< "-+-+-" << endl
				<< polje[6] << '|' << polje[7] << '|' << polje[8] << endl
				<< "------" << endl;
		}

		// User input
		cout << "Na redu je igrac " << trenutni_potez << endl;
		cout << "Unesi index polja (0-8) u koje zelis staviti svoj znak: " << endl;
		cin >> koordinata; // vrijednosti od 1-9

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
			(polje[2] == polje[3] && polje[3] == polje[6] && polje[2] != ' ') ||
			(polje[0] == polje[4] && polje[4] == polje[8] && polje[0] != ' '))
		{
			// Opcija za novu igru
			cout << "Pobjednik je " << trenutni_potez << ". Zelite li ponovno igrati (da/ne?)" << endl;
			string odgovor_igraca;
			cin >> odgovor_igraca;
			if (odgovor_igraca == "da" || odgovor_igraca == "Da" || odgovor_igraca == "DA")
			{
				for (int i = 0; i < 9; i++)
					polje[i] = ' ';
				// View -- transformacija iz raw data iz RAMA u nesto sto se vidi na ekranu
				cout
					<< "------" << endl
					<< polje[0] << '|' << polje[1] << '|' << polje[2] << endl
					<< "-+-+-" << endl
					<< polje[3] << '|' << polje[4] << '|' << polje[5] << endl
					<< "-+-+-" << endl
					<< polje[6] << '|' << polje[7] << '|' << polje[8] << endl
					<< "------" << endl;
			}
			else
				cout << "Hvala na igranju. Dodite nam opet!" << endl;
		}
		else {
			trenutni_potez = 'o';  // prebacivanje poteza na sljedeceg igraca
		}
		{
			cout
				<< "------" << endl
				<< polje[0] << '|' << polje[1] << '|' << polje[2] << endl
				<< "-+-+-" << endl
				<< polje[3] << '|' << polje[4] << '|' << polje[5] << endl
				<< "-+-+-" << endl
				<< polje[6] << '|' << polje[7] << '|' << polje[8] << endl
				<< "------" << endl;
		}

		// User input
		cout << "Na redu je igrac " << trenutni_potez << endl;
		cout << "Unesi index polja (0-8) u koje zelis staviti svoj znak: " << endl;
		cin >> koordinata; // vrijednosti od 1-9

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
			(polje[2] == polje[3] && polje[3] == polje[6] && polje[2] != ' ') ||
			(polje[0] == polje[4] && polje[4] == polje[8] && polje[0] != ' '))
		{
			// Opcija za novu igru
			cout << "Pobjednik je " << trenutni_potez << ". Zelite li ponovno igrati (da/ne?)" << endl;
			string odgovor_igraca;
			cin >> odgovor_igraca;
			if (odgovor_igraca == "da" || odgovor_igraca == "Da" || odgovor_igraca == "DA")
			{
				for (int i = 0; i < 9; i++)
					polje[i] = ' ';
				// View -- transformacija iz raw data iz RAMA u nesto sto se vidi na ekranu
				cout
					<< "------" << endl
					<< polje[0] << '|' << polje[1] << '|' << polje[2] << endl
					<< "-+-+-" << endl
					<< polje[3] << '|' << polje[4] << '|' << polje[5] << endl
					<< "-+-+-" << endl
					<< polje[6] << '|' << polje[7] << '|' << polje[8] << endl
					<< "------" << endl;
			}
			else
				cout << "Hvala na igranju. Dodite nam opet!" << endl;
		}
		else {
			trenutni_potez = 'x';  // prebacivanje poteza na sljedeceg igraca
		}
		{
			cout
				<< "------" << endl
				<< polje[0] << '|' << polje[1] << '|' << polje[2] << endl
				<< "-+-+-" << endl
				<< polje[3] << '|' << polje[4] << '|' << polje[5] << endl
				<< "-+-+-" << endl
				<< polje[6] << '|' << polje[7] << '|' << polje[8] << endl
				<< "------" << endl;
		}

		// User input
		cout << "Na redu je igrac " << trenutni_potez << endl;
		cout << "Unesi index polja (0-8) u koje zelis staviti svoj znak: " << endl;
		cin >> koordinata; // vrijednosti od 1-9

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
			(polje[2] == polje[3] && polje[3] == polje[6] && polje[2] != ' ') ||
			(polje[0] == polje[4] && polje[4] == polje[8] && polje[0] != ' '))
		{
			// Opcija za novu igru
			cout << "Pobjednik je " << trenutni_potez << ". Zelite li ponovno igrati (da/ne?)" << endl;
			string odgovor_igraca;
			cin >> odgovor_igraca;
			if (odgovor_igraca == "da" || odgovor_igraca == "Da" || odgovor_igraca == "DA")
			{
				for (int i = 0; i < 9; i++)
					polje[i] = ' ';
				// View -- transformacija iz raw data iz RAMA u nesto sto se vidi na ekranu
				cout
					<< "------" << endl
					<< polje[0] << '|' << polje[1] << '|' << polje[2] << endl
					<< "-+-+-" << endl
					<< polje[3] << '|' << polje[4] << '|' << polje[5] << endl
					<< "-+-+-" << endl
					<< polje[6] << '|' << polje[7] << '|' << polje[8] << endl
					<< "------" << endl;
			}
			else
				cout << "Hvala na igranju. Dodite nam opet!" << endl;
		}
		else {
			trenutni_potez = 'o';  // prebacivanje poteza na sljedeceg igraca
		}
		{
			cout
				<< "------" << endl
				<< polje[0] << '|' << polje[1] << '|' << polje[2] << endl
				<< "-+-+-" << endl
				<< polje[3] << '|' << polje[4] << '|' << polje[5] << endl
				<< "-+-+-" << endl
				<< polje[6] << '|' << polje[7] << '|' << polje[8] << endl
				<< "------" << endl;
		}

		// User input
		cout << "Na redu je igrac " << trenutni_potez << endl;
		cout << "Unesi index polja (0-8) u koje zelis staviti svoj znak: " << endl;
		cin >> koordinata; // vrijednosti od 1-9

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
			(polje[2] == polje[3] && polje[3] == polje[6] && polje[2] != ' ') ||
			(polje[0] == polje[4] && polje[4] == polje[8] && polje[0] != ' '))
		{
			// Opcija za novu igru
			cout << "Pobjednik je " << trenutni_potez << ". Zelite li ponovno igrati (da/ne?)" << endl;
			string odgovor_igraca;
			cin >> odgovor_igraca;
			if (odgovor_igraca == "da" || odgovor_igraca == "Da" || odgovor_igraca == "DA")
			{
				for (int i = 0; i < 9; i++)
					polje[i] = ' ';
				// View -- transformacija iz raw data iz RAMA u nesto sto se vidi na ekranu
				cout
					<< "------" << endl
					<< polje[0] << '|' << polje[1] << '|' << polje[2] << endl
					<< "-+-+-" << endl
					<< polje[3] << '|' << polje[4] << '|' << polje[5] << endl
					<< "-+-+-" << endl
					<< polje[6] << '|' << polje[7] << '|' << polje[8] << endl
					<< "------" << endl;
			}
			else
				cout << "Hvala na igranju. Dodite nam opet!" << endl;
		}
		else {
			trenutni_potez = 'x';  // prebacivanje poteza na sljedeceg igraca
		}
		{
			cout
				<< "------" << endl
				<< polje[0] << '|' << polje[1] << '|' << polje[2] << endl
				<< "-+-+-" << endl
				<< polje[3] << '|' << polje[4] << '|' << polje[5] << endl
				<< "-+-+-" << endl
				<< polje[6] << '|' << polje[7] << '|' << polje[8] << endl
				<< "------" << endl;
		}

		// User input
		cout << "Na redu je igrac " << trenutni_potez << endl;
		cout << "Unesi index polja (0-8) u koje zelis staviti svoj znak: " << endl;
		cin >> koordinata; // vrijednosti od 1-9

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
			(polje[2] == polje[3] && polje[3] == polje[6] && polje[2] != ' ') ||
			(polje[0] == polje[4] && polje[4] == polje[8] && polje[0] != ' '))
		{
			// Opcija za novu igru
			cout << "Pobjednik je " << trenutni_potez << ". Zelite li ponovno igrati (da/ne?)" << endl;
			string odgovor_igraca;
			cin >> odgovor_igraca;
			if (odgovor_igraca == "da" || odgovor_igraca == "Da" || odgovor_igraca == "DA")
			{
				for (int i = 0; i < 9; i++)
					polje[i] = ' ';
				// View -- transformacija iz raw data iz RAMA u nesto sto se vidi na ekranu
				cout
					<< "------" << endl
					<< polje[0] << '|' << polje[1] << '|' << polje[2] << endl
					<< "-+-+-" << endl
					<< polje[3] << '|' << polje[4] << '|' << polje[5] << endl
					<< "-+-+-" << endl
					<< polje[6] << '|' << polje[7] << '|' << polje[8] << endl
					<< "------" << endl;
			}
			else
				cout << "Hvala na igranju. Dodite nam opet!" << endl;
		}
		else {
			trenutni_potez = 'o';  // prebacivanje poteza na sljedeceg igraca
		}
		{
			cout
				<< "------" << endl
				<< polje[0] << '|' << polje[1] << '|' << polje[2] << endl
				<< "-+-+-" << endl
				<< polje[3] << '|' << polje[4] << '|' << polje[5] << endl
				<< "-+-+-" << endl
				<< polje[6] << '|' << polje[7] << '|' << polje[8] << endl
				<< "------" << endl;
		}

		// User input
		cout << "Na redu je igrac " << trenutni_potez << endl;
		cout << "Unesi index polja (0-8) u koje zelis staviti svoj znak: " << endl;
		cin >> koordinata; // vrijednosti od 1-9

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
			(polje[2] == polje[3] && polje[3] == polje[6] && polje[2] != ' ') ||
			(polje[0] == polje[4] && polje[4] == polje[8] && polje[0] != ' '))
		{
			// Opcija za novu igru
			cout << "Pobjednik je " << trenutni_potez << ". Zelite li ponovno igrati (da/ne?)" << endl;
			string odgovor_igraca;
			cin >> odgovor_igraca;
			if (odgovor_igraca == "da" || odgovor_igraca == "Da" || odgovor_igraca == "DA")
			{
				for (int i = 0; i < 9; i++)
					polje[i] = ' ';
				// View -- transformacija iz raw data iz RAMA u nesto sto se vidi na ekranu
				cout
					<< "------" << endl
					<< polje[0] << '|' << polje[1] << '|' << polje[2] << endl
					<< "-+-+-" << endl
					<< polje[3] << '|' << polje[4] << '|' << polje[5] << endl
					<< "-+-+-" << endl
					<< polje[6] << '|' << polje[7] << '|' << polje[8] << endl
					<< "------" << endl;
			}
			else
				cout << "Hvala na igranju. Dodite nam opet!" << endl;
		}
		else {
			trenutni_potez = 'x';  // prebacivanje poteza na sljedeceg igraca
		}
	}

}