#include <iostream>
// svrha includea da su drugdje napravljene deklaracije pa ih zovemo (less clutter)
using namespace std;
#include "Semafor.h"
#include "Automobil.h"

// Predavanje 7 - Switch, Function overloading, headeri, STL string

// Semafor zadatak & Headeri (podjela klasa)

// Podjela klasa radi modularnosti na header (.h) za deklaracije i source file (.cpp) za definicije
// Deklaracija, objava da nesto postoji (.h) npr void funkcija();
// Definicija, dodajemo nesto tom necemu (.cpp), npr blok koda unutar te void funkcije
// Imamo main.cpp pa tipa semafor.cpp, auto.cpp...U svaki od njih se includa .h koji mu treba

// U main-u definirat kolko god funkcija, for simplicity
// inace svaki .cpp ima svoj .h tipa gameEngine.cpp / gameEngine.h
// exe code ide u .cpp a u .h samo deklarativni dio

int main() {

	// u mainu samo ostaje / preostaje koristenje objekta koji su includani iz .h
	Semafor onaj_na_zagrebackoj_cesti;

	Automobil mazda;
	mazda.upali_motor();
	mazda.vozi();
	mazda.skreni(45);
	mazda.koci();

	onaj_na_zagrebackoj_cesti.setState(Semafor::Stanje::Crveno);
	while (true) {
		onaj_na_zagrebackoj_cesti.printState();
		onaj_na_zagrebackoj_cesti.run();
		onaj_na_zagrebackoj_cesti.nextState();
	}
}