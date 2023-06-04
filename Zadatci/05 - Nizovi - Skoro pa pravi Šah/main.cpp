#include <iostream>
using namespace std;

// (Skoro pa pravi) Šah

/*
Ne treba biti šah sa svim pravilima, još je prerano u tečaju za takav
pothvat, ali ono što možete napraviti je:
- Šahovsku ploču predstavlja array od 64 varijable.
- Prvi potez igra bijeli igrač, nakon toga se izmjenjuju bijeli i crni
  igrač svakim potezom.
- Igrač ne može "pojesti" svoju figuru.
- Kretanje figure je pravilno - pješaci ne smiju ići u nazad, kula smije
  samo vodoravno ili okomito, kralj samo po jedan potez, itd.
- Igrač igra potez tako da prvo unese polje odakle želi pomaknuti figuru,
  pa polje na koje ju želi pomaknuti. Npr: prvi potez bijelog igrača može
  biti "e2↵e4", zatim crni igra "e7↵e5", pa bijeli igra "g1↵f3", itd.
  Igranje poteza možete i drukčije riješiti ako vam je lakše od ovog načina.
- Ako je pojeden kralj, igra završava.

Bonus bodovi za sve dodatne detalje koje isprogramirate tako da igra bude
što bliža stvarnim pravilima šaha. (En passant, pinned pieces, ...)

P.S.
Za predstavljanje figura kod ispisa možete koristiti notaciju sličnu FEN-u:
K - kralj, Q - kraljica, R - kula, N - skakač, B - lovac, P - pješak
crne figure predstavljene malim, a bijele velikim slovom
Početno stanje ploče bi onda izgledalo:
rnbqkbnr
pppppppp
........
........
........
........
PPPPPPPP
RNBQKBNR
*/

int main() {

	// Reprezentacija šahovske ploče
	char ploča[64] = {
		'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
		'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
		'.', '.', '.', '.', '.', '.', '.', '.',
		'.', '.', '.', '.', '.', '.', '.', '.',
		'.', '.', '.', '.', '.', '.', '.', '.',
		'.', '.', '.', '.', '.', '.', '.', '.',
		'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
		'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R',
	};


	string player1 = "Bijeli";
	string player2 = "Crni";

	string trenutni_potez = player1;

	for (int i = 0; i < 64; i++) {
		array[i] = ' ';
		cout << "Dobrodošli u partiju šaha";
	}

	while (true) {






	}



	// Prvi potez na bijelom igraču



}
