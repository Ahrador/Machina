#include <iostream>
#include <string>
#include < Windows.h >
using namespace std;

// Zadatak - Regulacija prometa na raskrižju

/*
U ovom zadatku je cilj napraviti program koji simulira jednostavno raskrižje.
- Dizajniraj i napiši objekt "TrafficLight", koji predstavlja semafor na raskrižju. 
Semafor treba moći biti u jednom od stanja za koja treba definirati i enum class 
"StanjaSemafora". U objekt dodaj i funkciju printCurrentState() koja ispisuje naziv 
stanja u kojem se semafor nalazi.
- Dizajniraj i napiši objekt "TrafficIntersection", koji predstavlja raskrižje. 

Raskrižje ima 4 semafora, po jedan u smjeru sjevera, juga, istoka, i zapada. Od njih se 
po 2 uvijek nalaze u jednakom stanju, i to semafori na pravcima sjever-jug i istok-zapad. Na primjer: kad sjeverni semafor prelazi u zeleno svjetlo, to isto radi i semafor na jugu. Slika u prilogu ovog zadatka predstavlja skicu takvog raskrižja.
- U njega dodaj i funkciju run() koja, koristeći sistemsku funkciju Sleep(), simulira 
protok vremena na raskrižju. Sleep() kao jedini argument prima trajanje pauze u 
milisekundama. Sleep() je deklarirana u #include <Windows.h>.
- Nakon nekog vremena se trebaju izmijeniti stanja na semaforima, tako da prolaz bude 
slobodan vozilima u drugom pravcu.
- Žuto svjetlo treba trajati najmanje 3 sekunde, a najviše 6. Ostala trajanja odredite 
po svojoj volji.
- Početno stanje svih semafora na raskrižju treba biti "invalid value", koje je u 
stvarnom svijetu predstavljeno treptavim žutim svjetlom, i treba trajati 10 sekundi. 
Iz njega svi semafori prelaze u crveno svjetlo na 5 sekundi, a zatim raskrižje prelazi 
u gore opisani regularni ciklus.
- U funkciji main instanciraj jedan TrafficIntersection objekt, te pozovi njegovu 
funkciju run().
- Program treba jednom u sekundi ispisati stanje svih semafora na raskrižju.

U prilogu ovog zadatka je poveznica na izvorni Zakon (bez izmjena i dopuna koje su 
kasnije izvršene) u kojem su navedena stanja u kojem semafor može biti i njihova 
značenja. Dio o regulaciji prometa je glava 8, "PROMET NA RASKRIŽJU", i to članci 48-62.
*/

// Definicija enumeracije StanjaSemafora
enum class StanjaSemafora {
	NEVAZECE, 
	CRVENO,
	ŽUTO,
	ZELENO 
};

// Definicija klase TrafficLight
class TrafficLight {
public:
	TrafficLight() {
		currentState = StanjaSemafora::NEVAZECE;
	}
	void setState(StanjaSemafora newState) {
		currentState = newState;
	}

	// Deklaracija funkcije koja ne prima argumente i ne vraca vrijednost 
	void printCurrentState() {
		switch (currentState) { // provjera da li je currentState jednak NEVAZECE, sto oznacava nevazece stanje semafora
		case StanjaSemafora::NEVAZECE:
			std::cout << "Invalid state (Flashing yellow)\n";
			break;
		case StanjaSemafora::CRVENO:
			std::cout << "Red light\n";
			break;
		case StanjaSemafora::ŽUTO:
			std::cout << "Yellow light\n";
			break;
		case StanjaSemafora::ZELENO:
			std::cout << "Green light\n";
			break;
		}
		/*
		Kada se pozove metoda printCurrentState, ona provjerava trenutno stanje semafora 
		(currentState) i ispisuje odgovarajuću poruku na temelju vrijednosti tog stanja.
		*/
	}
private:
	StanjaSemafora currentState;
};

// Definicija klase TrafficIntersection
class TrafficIntersection {
public:
	TrafficIntersection() {
		sjeverJug.setState(StanjaSemafora::ZELENO);
		istokZapad.setState(StanjaSemafora::CRVENO);
	}

	void run() {
		while (true) {
			sjeverJug.printCurrentState();
			istokZapad.printCurrentState();
			Sleep(1000);

			// Change states
			switch (sjeverJug.currentState) {
			case StanjaSemafora::ZELENO:
				sjeverJug.setState(StanjaSemafora::ŽUTO);
				istokZapad.setState(StanjaSemafora::ŽUTO);
				break;
			case StanjaSemafora::ŽUTO:
				sjeverJug.setState(StanjaSemafora::CRVENO);
				istokZapad.setState(StanjaSemafora::ZELENO);
				break;
			case StanjaSemafora::CRVENO:
				sjeverJug.setState(StanjaSemafora::ZELENO);
				istokZapad.setState(StanjaSemafora::CRVENO);
				break;
			case StanjaSemafora::NEVAZECE:
				sjeverJug.setState(StanjaSemafora::CRVENO);
				istokZapad.setState(StanjaSemafora::CRVENO);
				break;
			}
		}
	}

private:
	TrafficLight sjeverJug;
	TrafficLight istokZapad;
};

int main() {
	TrafficIntersection intersection;
	intersection.run();

	return 0;
}
