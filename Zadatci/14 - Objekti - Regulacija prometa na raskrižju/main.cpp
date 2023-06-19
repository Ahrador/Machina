#include <iostream>
#include <string>
#include < Windows.h >
using namespace std;

// Zadatak - Regulacija prometa na raskrižju

/*
U ovom zadatku je cilj napraviti program koji simulira jednostavno raskrižje.

- Dizajniraj i napiši objekt "TrafficLight", koji predstavlja semafor na raskrižju.
Semafor treba moći biti u jednom od stanja za koja treba definirati i enum class
"StanjaSemafora". 
U objekt dodaj i funkciju printCurrentState() koja ispisuje naziv
stanja u kojem se semafor nalazi.

- Dizajniraj i napiši objekt "TrafficIntersection", koji predstavlja raskrižje.

Raskrižje ima 4 semafora, po jedan u smjeru sjevera, juga, istoka, i zapada. 
Od njih se po 2 uvijek nalaze u jednakom stanju, i to semafori na pravcima sjever-jug i istok-zapad. 
Na primjer: kad sjeverni semafor prelazi u zeleno svjetlo, to isto radi i semafor na jugu. 
Slika u prilogu ovog zadatka predstavlja skicu takvog raskrižja.

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

// 1. Definiranje enum class "StanjaSemafora":
enum class StanjaSemafora {
	NEVAZECE,
	CRVENO,
	ŽUTO,
	ZELENO
};

// Ova klasa predstavlja semafor na raskrižju
class TrafficLight {
private:
	StanjaSemafora currentState; // "currentState" pamti trenutno stanje semafora 

public:
	TrafficLight() {
		currentState = StanjaSemafora::NEVAZECE; 
	}

	void setState(StanjaSemafora state) {
		currentState = state;
	}

	StanjaSemafora getState() {
		return currentState;
	}

	void printCurrentState() {
		string stateStr;
		switch (currentState) {
		case StanjaSemafora::NEVAZECE:
				stateStr = "NEVAZECE";
				break;
		case StanjaSemafora::CRVENO:
			stateStr = "CRVENO";
			break;
		case StanjaSemafora::ŽUTO:
			stateStr = "ŽUTO";
			break;
		case StanjaSemafora::ZELENO:
			stateStr = "ZELENO";
			break;
		}
		cout << "Current state: " << stateStr << endl;
	}
};

class TrafficIntersection {
private:
	TrafficLight northSouthLights;
	TrafficLight eastWestLights;

public:
	TrafficIntersection() {
		// Inicijalizacija svih semafora na INVALID stanje
		northSouthLights.setState(StanjaSemafora::NEVAZECE); 
		eastWestLights.setState(StanjaSemafora::NEVAZECE); 
	}

	void changeLights() {
		StanjaSemafora northSouthState = northSouthLights.getState(); 
		StanjaSemafora eastWestState = eastWestLights.getState(); 

		// Promjena stanja semafora ovisno o trenutnom stanju
		if (northSouthState == StanjaSemafora::NEVAZECE && eastWestState == StanjaSemafora::NEVAZECE) {
			// Početno stanje - invalid value
			northSouthLights.setState(StanjaSemafora::NEVAZECE);
			eastWestLights.setState(StanjaSemafora::NEVAZECE);
			Sleep(10000); // Trajanje invalid value stanja - 10 sekundi
		}
		else if (northSouthState == StanjaSemafora::NEVAZECE && eastWestState == StanjaSemafora::CRVENO) {
			// Prelazak u crveno stanje
			northSouthLights.setState(StanjaSemafora::CRVENO);
			eastWestLights.setState(StanjaSemafora::CRVENO);
			Sleep(5000); // Trajanje crvenog svjetla - 5 sekundi
		}
		else {
			// Regularni ciklus
			northSouthLights.setState(StanjaSemafora::ZELENO);
			eastWestLights.setState(StanjaSemafora::ZELENO);
			Sleep(5000); // Trajanje zelenog svjetla - 5 sekundi

			northSouthLights.setState(StanjaSemafora::ŽUTO);
			eastWestLights.setState(StanjaSemafora::ŽUTO); 
			Sleep(3000); // Trajanje zutog svjetla - 3 sekunde

			northSouthLights.setState(StanjaSemafora::CRVENO);
			eastWestLights.setState(StanjaSemafora::CRVENO);
			Sleep(5000); // Trajanje crvenog svjetla - 5 sekundi
		}
	}

	void run() {
		while (true) {
			northSouthLights.printCurrentState();
			eastWestLights.printCurrentState();

			changeLights();

			Sleep(1000); // Pauza od 1 sekunde
		}
	}
};

int main() {
	TrafficIntersection intersection;
	intersection.run();

	return 0;
}