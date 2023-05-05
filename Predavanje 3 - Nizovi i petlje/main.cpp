#include <iostream>
using namespace std;

// () {} [] <> || ""

// Predavanje 3
// Kontrola programskog toka (eng, control flow) & nizovi (eng, arrays)
// Petlje, if else, switch case konstrukti - dijelovi jezika koji dopustaju kontrolu programskog toka
// Programski tok - odozgo prema dolje, s lijeva na desno

int main() {
	int niz[10];
	int i = 0;
	cout << i;
	// svako jaje - petlja
	//   razbij i zamuti -- ovaj komad algoritma se vrti koliko treba

	// krizic kruzic - početna beginner verzija
	// setup
	char polje[9]; // index počinje od nule, tako da 0 - 8 (zadnji broj ne)
	char trenutni_potez = 'x';
	for (int i = 0; i < 9; i++)
		polje[i] = ' '; // ovo je upis u polje a da se doda cout, bilo bi i iscitavanje


	// Data - Efikasniji način s for petljom. Napravi ovo za svaki element.
	// Ponovi 'polje[0] = ' ';' izraz.  i++ je isto kao i = i+1
	for (int i = 0; i < 9; i++) // int = 0; je brojač u nuli, i < 9; brojač se vrti do 9, i++, podize se za 1 u svakom koraku
		polje[i] = ' ';

	for (int i = 0; i < 9; i = i + 4)
		polje[i] = 'o';

	for (int i = 0; i < 9; i = i + 3)
		polje[i] = 'x';

	// Još detaljnije objašnjena petlja
	for (
		int i = 0 // setup
		;
		i < 9 = // uvjet
		;
		i++ // korak
		)
		*/

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

		// Moguće kombinacije za pobjedu križića:
		if
			(polje[0] == polje[1] == polje[2] && polje[0] != ' ')
			||
			(polje[3] == polje[4] == polje[5] && polje[3] != ' ')
			||
			(polje[6] == polje[7] == polje[8] && polje[6] != ' ')
			(polje[0] == polje[3] == polje[6] && polje[0] != ' ')
			(polje[1] == polje[4] == polje[7] && polje[1] != ' ')
			(polje[2] == polje[5] == polje[8] && polje[2] != ' ')
			(polje[2] == polje[3] == polje[6] && polje[2] != ' ')
			(polje[0] == polje[4] == polje[8] && polje[0] != ' ')
		{
			// Provjera pobjede i opcija za novu igru
			cout << "Pobjednik je" << trenutni_potez << "Zelite li ponovno igrati (da/ne)?" << endl;
			string odgovor_igraca;
			cin >> odgovor_igraca;
			if (odgovor_igraca == "da" || odgovor_igraca == "Da" || odgovor_igraca == "DA")
			{
				// View -- transformacija iz raw data iz RAMA u nesto sto se vidi na ekranu
				cout
					<< "------" << endl
					<< polje[0] << '|' << polje[1] << '|' << polje[2] << endl // tako ce svaka 3 bit u svom redu
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

		cout
			<< "------" << endl
			<< polje[0] << '|' << polje[1] << '|' << polje[2] << endl
			<< "-+-+-" << endl
			<< polje[3] << '|' << polje[4] << '|' << polje[5] << endl
			<< "-+-+-" << endl
			<< polje[6] << '|' << polje[7] << '|' << polje[8] << endl
			<< "------" << endl;

		// User input
		cout << "Na redu je igrac " << trenutni_potez << endl;
		cout << "Unesi index polja (0-8) u koje zelis staviti svoj znak: " << endl;
		cin >> koordinata; // vrijednosti od 1-9

		// Primjer do-while petlje za user input
		int koordinata;
		do {
			cout << "Na redu je igrac " << trenutni_potez << endl;
			cout << "Unesi index polja (0-8) u koje zelis staviti svoj znak: " << endl;
			cin >> koordinata; // vrijednosti od 1-9
		} while (koordinata > 8 || koordinata < 0);

		// Modify world
		polje[koordinata] = trenutni_potez; // na koordinatu koju nam je dao igrac, stavi njeg znak

		// Moguće kombinacije za pobjedu kružića:
		// Moguće kombinacije za pobjedu križića:
		if (polje[0] == polje[1] == polje[2] && polje[0] != ' ')
			(polje[3] == polje[4] == polje[5] && polje[3] != ' ')
			(polje[6] == polje[7] == polje[8] && polje[6] != ' ')
			(polje[0] == polje[3] == polje[6] && polje[0] != ' ')
			(polje[1] == polje[4] == polje[7] && polje[1] != ' ')
			(polje[2] == polje[5] == polje[8] && polje[2] != ' ')
			(polje[2] == polje[3] == polje[6] && polje[2] != ' ')
			(polje[0] == polje[4] == polje[8] && polje[0] != ' ');
		{
			// Provjera pobjede i opcija za novu igru
			cout << "Pobjednik je " << trenutni_potez << "Zelite li ponovno igrati (da/ne?)" << endl;
			string odgovor_igraca;
			cin >> odgovor_igraca;
			if (odgovor_igraca == "da" || odgovor_igraca == "Da" || odgovor_igraca == "DA")
			{
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
	}

	// undefined behaviour, slicni nacini za istu stvar
	int polje1;
	polje1 = 1;
	cout << 1;
	polje[0] = 1;
	cin >> polje[0];
	// if (polje[0] == polje1)


	// Setup, postavljanje ploce/svijeta
	// Podatak o tome tko je na redu, x ili o
	// Step, igrac igra potez, provjera pobjede, prebaci na sljed igraca


	// KONTROLA PROGRAMSKOG TOKA (thread/nit)

	if ()// u zagradi uvjet koji se svodi na boolean true or false
	{
		// u slucaju unosa broja iznad raspona ponudenih vrijednosti, ponovni upis trazen
		// izraz, jedna naredba ili blok naredbi, ak je blok, ide u {}
	}
	else  // izraz, jedna naredba ili blok naredbi, ak je blok, ide u {}


	// Petlje  (for, while, do-while)

		for // ako znam tocno koliko puta ce se komad koda izvest use this, ili kad mogu doc do tog podatka
			// Npr, ak se ocu na polju od 9 elemenata se prosetat

			while // ako se nezna tocno koliko puta, ak postoji opcija gdje se nijednom nece izvest
				do - while // ako se nezna tocno koliko puta, obicno se koristi kad se treba neki input validirat
					// Izbor izmedu njih dvije, da li ce se bar jednom izvest il ne

					// Summary: Ako tocno znam koliko ce se izvest, koristit 'for', 
					// ako ne, a izvede se bar jednom, koristite 'do-while' a inace koristite 'while'

					do {
						// input
						// izvrsavaj ovo dok se nesto nije desilo
					} while (); // validirat.  za razliku od svih drugih, do while testira uvjet na kraju

					/*
					ZAGRADE
					- pripadaju naredbi nakon koje idu. Ako se if ili for petlje dodaju
					unutar nekog vec izraza tipa do ili while-a, onda su to izrazi koji pripadaju
					toj do ili while petlji.
					- tipa 'do' ima svoj blok, nikad sam nemre stajat, nakon zagrada ide while.
					- ako hocu vise naradbi u jednoj glavnoj petlji, sve moraju ici pod njen blok
					-
					*/

					// Kad god ima neki copy-paste, treba koristit petlje za efikasnost
					// Ovo dolje staviti u for petlju
						/*
						cout
							<< "------" << endl
							<< polje[0] << '|' << polje[1] << '|' << polje[2] << endl // tako ce svaka 3 bit u svom redu
							<< "-+-+-" << endl
							<< polje[3] << '|' << polje[4] << '|' << polje[5] << endl
							<< "-+-+-" << endl
							<< polje[6] << '|' << polje[7] << '|' << polje[8] << endl
							<< "------" << endl;
						*/

						// Simplified primjer za naucit for petlju
					for (
						int brojac = 0 // setup
						;
						brojac < 9 // uvjet - koji odreduje dal ce se naredba izvest opet, nakon 9, izlazi iz petlje
						;
						brojac = brojac + 1// sljed vrijednost brojaca, 1+1 ...korak, pomak nakone svake iteracije, bez ovog koraka je infinite petlja 
						// ili ovak
						brojac += 1 // zbroji i pridruzi
						// ili ovak
						brojac++ tj i++ najcesce

						)
					{
						cout << polje[brojac]
							// kad se radi petlja, obicno napisi formulu za jedan, i zamijeni index sa varijablog u petlji (brojacem) pa se prosiri na sve elemente
					}

					// FOR  petlja  ( proper look )
					for (int i = 0; i < 9; i++)
					{
						cout << polje[i]
							// kad se radi petlja, obicno napisi formulu za jedan, i zamijeni index sa varijablom u petlji (brojacem) pa se prosiri na sve elemente
					}


					// DO-WHILE  petlja
					// (2:45 mark in predavanje 3)
					// samo ima blok i uvjet u while-u, nema setup i korak
					int koordinata;
					do {
						cout << "Na redu je igrac " << trenutni_potez << endl;
						cout << "Unesi index polja (0-8) u koje zelis staviti svoj znak: " << endl;
						cin >> koordinata;
					} while (koordinata > 8 || koordinata < 0);


					// WHILE  petlja
					// kao if je,  ima uvjet i blok, ali se ne izvodi jednom kao if, vec stalno
					while (true)
					{
					}

					// Primjer za embedded software
					while (true)
					{
						// hardware logic
					}


					// BREAK i CONTINUE 
					// sluze za prijevremen izlazak iz petlje ili da se nastavi sljedeca iteracije petlje
					// ako svaki treci zelim preskocit

					// Continue
					for (int i = 0; i < 9; i++)
					{
						if (i == 2)
							(i % 2) // ako je djeljiv s 2
							(i % 2 == 0) // ako hocu preskocit brojeve djeljive s 2
							continue;  // nastavi petlju a ignoriraj ovo dolje
						cout << i << endl;
					}


					// Break
					for (int i = 0; i < 9; i++)
					{
						if (i == 4)
							break;  // ako dode do 4, izlazak iz petlje
						cout << i << endl;
					}

					// Break i continue se ne koriste za if vec za petlje, te uvijek pripada petlji koja je iznad njega

					// Dvodimenzionalni array (mark 3h i 1 min, predavanje 3)

}