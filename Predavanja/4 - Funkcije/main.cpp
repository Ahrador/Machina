#include <iostream>
#include <string>
using namespace std;
// using main1 = int;  ili  typedef void main1 --- main1 postane tip podataka pa moze pisat main1 beskorisna()

// Predavanje 4 - Funkcije

// Include je način da ne moramo imat milijun funkcija ispred maina napisanih, već
// je svrha include-a da uzme te sve funkcije i izbaci ih u vanjski file #include <funkcije_koje_koristim>
// Te funkcije se dodaju pod Header files, new Header file.

/*
Funkcije u C++-u su način grupiranja skupa naredbi koje obavljaju određeni zadatak.
Korisne su kada želite izvršiti određeni zadatak više puta u svom programu, bez
potrebe da ponovno pišete iste naredbe iznova i iznova.

Da biste stvorili funkciju, trebate definirati njezino ime, odrediti vrstu
podataka koju vraća (ako postoji) i navedite popis argumenata (ako postoje) koje
prima. Jednom kada se funkcija definira, možete je pozvati bilo gdje u programu
jednostavnim pozivom njenog imena.

Funkcije su posebno korisne kada trebate izvršiti određeni skup operacija na
određenom skupu podataka. Te podatke možete prenijeti funkciji kao argument, a
funkcija može izvršiti potrebne operacije nad tim podacima i vratiti rezultat.

Funkcije se također mogu koristiti za razbijanje velikog programa na manje,
lakše upravljive dijelove. To olakšava otklanjanje pogrešaka i održavanje vašeg
koda, budući da se možete usredotočiti na jednu funkciju u jednom trenutku
umjesto da pratite cijeli program.
*/

// Function definition:
// TYPE NAME ( [PARAMETERS] ) CODE-BLOCK

// Function declaration:  
// TYPE NAME ( [PARAMETERS] );

// Funkcije - modularizacija code-a
// Funkcija je ime za komad koda koji se nalazi unutar te funkcije.
// Kada se zeli taj kod izvesti samo se pozove ime te funkcije.
// Funkcije se nalaze izvan 'int main' glavne funkcije.
// Operatori rade na isti način kao i funkcije
// Npr. cout << "Print"; --- je funkcija s dva parametra, print desno, cout lijevo
// int i = 10;  --- isto, funkcija s dva parametra 
// Otici kupiti banane (parametar, npr kolicina, moze bit vise parametara)
// Odi upali auto (bez parametra)
// voide funkcije ne returnaju ništa
// Unutar funkcija su parametri odvojeni zarezom

// Deklaracija funkcija
int zbroji(int prvi, int drugi) {
	return prvi + drugi;
}

void beskorisna(int i);

// Glavna main funkcija
int main() {

	zbroji(8, 1); // poziv funkcije 
	cout << zbroji(8, 1);

	int i = 4;
	beskorisna(i); // "poziv funkcije" - izvodi se njen kod
	return 0;
}

// Definicija funkcija (izvan/nakon glavne main funkcije)
void beskorisna(int i) {
	cout << "The number is: " << i;
}

// -----------------------------------------------------------------------

int slucajni_broj() {
	return 41; // uvijek vraća zadanu vrijednost
}

void main() {
	cout << slucajni_broj();
	cout << rand() << endl; // funkcija rand() "vraća" slučajnu vrijednost ali istim redoslijedom

	time_t rezultat = time(0); // varijabla time_t za spremanje rezultata funkcije time(0)
	srand(rezultat);
	srand(8); // srand funkcija prima broj od kojeg želite krenuti, uvijek ce biti 8
	srand(time(0)); // postavljanje ("seed") pocetka generatora slucajnih brojeva
	cout << time(0);
}

// -----------------------------------------------------------------------

int slučajni_broj_izmedu_1_i_42() {  // return type mora biti isti kao int ak je int ispred naziva funkcije
	return rand() % 42 + 1; // tu moze biti bilo kaj se moze pretvorit u int
}

int main() {

	// globalne funkcije su one koje ne spadaju u nikoju funkciju, dostupna svida, avoid if possible
	int broj; // "broj" je lokalna varijabla unutar funkcije main()

	// Loto, dobivanje slučajnih brojeva izmedu 1 i 42 - Ispisivanje
	cout << rand() % 42 + 1 << endl; // Funkcija rand() ''vraca'' slucajnu vrijednost
	cout << rand() % 42 + 1 << endl;
	cout << rand() % 42 + 1 << endl;

	// Loto, dobivanje slučajnih brojeva izmedu 1 i 42 - Ispisivanje u petlji s funkcijom
	while (true)
		cout << slučajni_broj_izmedu_1_i_42() << endl;

}
// -----------------------------------------------------------------------

// Liste - lista je varijabla

bool desila_se_pobjeda(char polje[], int max_size) { // max size za ogranicit to polje
	// ???
	// char polje[];
	if (false)
		return true;

	return false;
}

// U argument je potrebno navest ili int duljina_niza ili unsigned duljina_niza ili size_t duljina_niza
// tako da se zna dokle ide niz, tako da ne stavljat samo int niz[]
void ispisi_int_array(int niz[], unsigned duljina_niza) {
	for (int i = 0; i < duljina_niza; i++) // i ce ici od 0 do duljine_niza
		cout << niz[i] << ", ";
	cout << endl;
}

// U 2D listama prvi mora biti prazan
// void napuni_niz_slucajnim_brojevima(int niz[][4][7][3][2] unsigned duljina_niza)

void napuni_niz_slucajnim_brojevima(int niz[], unsigned duljina_niza) {
	for (int i = 0; i < duljina_niza; i++)
		niz[i] = rand(); // random brojevi
	//	niz[i] = i; // printa od 0 do 99
}

int main() {

	// Deklaracija varijabli
	srand(time(0));
	int deset_brojeva[10];
	int sto_brojeva[100] = { 0 }; // 0 u array da se ispuni

	cout << sto_brojeva[0] << endl; // ispis prvog elementa arraya = 0
	cout << sto_brojeva << endl; // ispis ime arraya, bez indeksa = adresa u RAMU di se niz nalazi
	// to je vrijednost koja se proslijedi funkciji prilikom poziva

	// Punjenje niza slučajnim brojevima
	napuni_niz_slucajnim_brojevima(sto_brojeva, 100);
	// umjesto pisanja koraka, pozivam st0_brojeva funkciju da ona ispuni 100 brojeva randomly

	// Primjer funkcije sa zadanim parametrima
	// Dolje for nije potreban, tu je radi primjera, dovoljan je for izvan main-a.
	// Glavno da se int deklariraju i napisu i onda ubace u funkciju kao parametri
	ispisi_int_array(sto_brojeva, 100); // ispis tog niza
	/*
	{
		for (int i = 0; i < 10; i++) // i ce ici od 0 do zadane vrijednosti
			cout << deset_brojeva[i] << ", ";
		cout << endl;
	}
	*/
	char polje[9];

	// Slanje arraya, rijetki slucaj, funkcija mijenja orginalnu varijablu
	// Proslijeđivanje array-eva, on se proslijeduje tak da se vrijednost proslijeduje funkciji
	// a vrijednost koja se porslijeduje je pocetak adrese tih varijabli u ramu. 
	// Kad funkcija mijenja nesto preko adrese, ona mijenja original

	// -----------------------------------------------------------------------


	// Ako zelite da funkcija promjeni neku varijablu unutar maina, primjer dolje
	// Učiti se se vise u lekciji o pointerima 

	int rezultat() {
		return 10;
	}

	// Promjena preko pokazivaca, 2h,44min, 55 sec mark
	// Primjer funkcije koja primi adresu neke varijable
	void promijeni_preko_pokazivaca(int* adresa) {
		*adresa = 123;  // upis vrijednosti koju trazimo u *adresu
	}

	void main() {
		int i;
		i = rezultat(); // najjednostavniji način je promjena preko maina preko funkcije
		// problem, dobiva se samo jedna vrijednost od funkcije, funkcija ne moze promijenit vise varijabli istovremeno

		cout << "i: " << i << endl;

		promijeni_preko_pokazivaca(&i) // adresin imperator koji dohvaca adresu varijable koja mu se preda
			// &i -- pretovri se u adresu varijable 'i' i to se pretvori gore funkciji
	}



	// Procjena kvalitete funkcije rand() - generator slučajnih brojeva

	/*
	Definiramo funkciju slucajni_broj_izmedu_0_i koja uzima jedan argument max i vraća slučajan broj
	između 0 i max-1 koristeći operator modulo %.
	*/
	int slucajni_broj_izmedu_0_i(int max) {
		return rand() % max;
	}

	// Početak funkcije 'main'
	int main() {
		// Definiramo dvije konstante:
		const int BROJ_IZVLACENJA = 1'000'000;  // Broj izvlačenja koja predstavlja broj izvlačenja i postavljamo je na 1'000'000
		const int BROJ_ELEMENATA = 50;         // te broj elementat koja predstavlja broj elemenata i postavljamo je na 50.

		// Deklaracija i inicijalizacija niza broj_pojavljivanja na 0 
		int broj_pojavljivanja[BROJ_ELEMENATA] = { 0 };  //  Ovaj niz će se koristiti za brojanje koliko puta se svaki broj pojavio.

		/*
		Petlja koja se izvršava BROJ_IZVLACENJA puta. U svakoj iteraciji, generiramo slučajni broj
		između 0 i BROJ_ELEMENATA-1 pozivom funkcije `
		*/
		for (int i = 0; i < BROJ_IZVLACENJA; i++) {
			// Generiraj slučajni broj između 0 i (BROJ_ELEMENATA-1)
			int slucajni_broj = slucajni_broj_izmedu_0_i(BROJ_ELEMENATA);

			// Povećaj broj_pojavljivanja za generirani slučajni broj
			broj_pojavljivanja[slucajni_broj]++;
		}

		const int OCEKIVANI_BROJ_POJAVLJIVANJA = BROJ_IZVLACENJA / BROJ_ELEMENATA;

		for (int i = 0; i < 50; i++) {
			// Ispisujemo broj pojavljivanja za svaku vrijednost i uspoređujemo s očekivanim brojem
			cout << "Broj " << i << " se pojavio " << broj_pojavljivanja[i] << " puta"
				<< ", što je " << (broj_pojavljivanja[i] - OCEKIVANI_BROJ_POJAVLJIVANJA) << " od očekivanog" << endl;
		}
	}
