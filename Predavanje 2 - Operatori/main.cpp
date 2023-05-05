#include <iostream>
#include <fstream>
using namespace std;

// PREDAVANJE 2 - Operatori (matematički, logički i bitwise (binarni)

int predavanje2() {
	int broj = 999999;
	char znak = broj;
	// 4 * 8 // 4 byta po 8 bitova, svaka dolje znamenka je 1 bit = 32
	//	0000 0000 1111 0100 0010 0011 1111  // U RAMU se nalazi ova vrijednost, prvih 8 nula kalkulator nije dao
	cout << (int)znak << endl;  // Pri pretvaranju int u char ostaje 0011 1111 = DEC 63
	// Drugi primjer, s manjeg u veći, predstavljanje broja 99 u 6 znamenki = 000099

	// Kako spremiti ovaj broj u RAM, imajuci na umu da imamo samo cijele brojeve tamo:
	float brojjj = 9.3;  // 93 * 10

	// Pisanje floata na dva načina:
	float decimalni = 9;
	float brojj = 9.0;  // Kad se float pretvara u int, reže se decimalni dio

	// Matematički operatori:
	int zbrajanje = 7 + 3;
	int oduzimanje = 5 - 2;
	int množenje = 3 * 5;
	int dijeljenje = 9 / 4;
	int modulo = 10 % 3;  // Lijevo se dijeli s desnim, ostatak je modulo vrijednost

	// Dijeljenje s floatom
	float broj3 = 9;
	int broj4 = 4;

	// (float) = (int) - pretvaranja int u float
	// (int) = (float) - pretvaranje float u int

	// Dobivanje prve znamenke ovog broja, dijeli se sa 100
	int brojjjj = 572;
	cout << brojjj / 100; // rezultat je 5
	cout << brojjj / 10 // rezultat je 57
		cout << brojjj / 10 % 10 // rezultat je 7 - nije mi jasno kako se zna da je 572/10%10=7 napamet
		cout << brojjj % 10 // rezultat je 5 7 2, znamenka po znamenka, isto pitanje ko gore

		// Veći int tipovi podataka - kad se veci pretvaraju u manje, rezu se veci dijelovi
		long long
		long
		short
		int
		char

		cout
		<< zbrajanje << '\n' << oduzimanje << '\n' << množenje << '\n' << dijeljenje
		<< '\n' << broj3 / broj4 << '\n' << modulo << '\n' << endl;


	// Prikazivanje prvih 15 znamenki od kartice
	long long int broj_kreditne_kartice;  // deklaracija varijable (tip i naziv)
	cin >> broj_kreditne_kartice;  // input za broj kartice
	cout << "Prvih 15 znamenki vaše kreditne kartice je: " << broj_kreditne_kartice << endl;  // output

	// Prije objašnjenja logičkih operatora, if else konstrukt i boolean je objašnjen:
	// if je konstrukt koji moze dio programa izvesti ili ne (uvjetno)
	cout << "Dio prije if-a\n";
	if (false)  // kad je vrijednost u zagradi if-a false, 'if dio' se ne ispisuje a kad je true, onda se taj komad koda izvodi
		cout << "if dio";
	cout << "\ndio poslije if-a\n";
	// NOTE:  true i false se ne pise tako u zagradi, to je samo radi primjera

	// Logički operatori, pravilni primjer:
	while (true) {  // beskonacna petlja, dok je unutra true, ovaj blok koda se izvrsava

		int temperatura_u_sobi;  // fejkam senzor, na jobu se taj podatak fetcha/dostavi
		cin >> temperatura_u_sobi;
		int granicna_temperatura = 28;
		if (temperatura_u_sobi > granicna_temperatura)  // ili usporedi dvije varijable ili konstantu
			cout << "Upali ventilator";
	}

	// Operatori usporedbe:  
	// < > <= >=  (manji od, veći od, manji ili jednak, veći ili jednak
	// !=  (operator različitosti, ! u C++ znaci negaciju) - pogleda dvije vrijednosti, i ak su razlicite, kaze DA a ak su iste, kaze NE
	// ==  (operator usporedbe)

	while (true) {
		int pin;
		cin >> pin;
		if (pin != 1234) {
			cout << "Pin je neispravan";
		}
		else {
			cout << "Točan pin!";
		}
	}

	// Logički operatori koji obavljaju operaciju nad Boolean vrijednostima
	char znak;				 // 1 bit, brojevi od 0-255 stanu unutra
	bool logička_vrijednost; // 1 bit.  moze biti 0 ili 1 vrijednost

	/*
	logička_vrijednost = true; ili false;
	false = 0
		true = sve sto nije false
		cout << logička_vrijednost << endl;

	int stanje_na_racunu_u_eurima = 0;
	if (stanje_na_racunu_u_eurima == 350000)
		cout << "Bogati ste" << endl;
	*/

	// Logički NOT (negacija):  !(bool) s desne strane prima vrijednost koja je boolean
	// Logički AND (i):  &&  uzme bool vrijednost s jedne i druge strane, ako su oba uvjeta true, njeg rezultat je true
	// Logički OR (ili):  || dovoljno je da je samo jedan od njih true

	// Logički NOT, !(bool), primjeri:
	bool vrijednost = false;
	!vrijednost // onda je ovo true

		if (!(starost_u_godinama >= 18))  // još jedan primjer za logički NOT
			if (starost_u_godinama < 18)
				cout << "Ne smiješ piti alkohol";

	// Treći primjer
	while (!(paused)) {  // Dok igra NIJE pauzirana
		// game is running
		// read joystick
		// move enemies
		// draw frame
	}

	// Logički AND (i), &&, primjeri:
	if (imaš_auto && imaš_vozačku)
		cout << "Možeš se voziti";

	// Logički OR (ili): ||, primjeri:
	if (KEY_UP || KEY_W)
		cout << "Move up";

	if (Temp < 7 || Temp > 20)  // Prvo se usporedba ima smisla provjerit a zatim OR
		cout << "Do something";

	// Napredniji primjer:
	if ((first == 3) && (second == 4) || (second == 7))
		if (first == 3 && second == 4 || first == 3 && second == 7) // ovakvo pisanje dođe s vremenom
		{
			printf("AMEX\n");
		}

	return 0;
}



