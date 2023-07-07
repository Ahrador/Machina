#pragma once // include guard
#include <windows.h>
#include <iostream>

/**/
class Semafor
{
};


struct Semafor {
	enum class Stanje {
		Crveno, Zuto, CrvenoZuto, Zeleno, Invalid
	};

	Stanje currentState;

	void setState(Stanje newState);
	void nextState();
	void printState();
	void run();
};
