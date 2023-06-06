#include "Semafor.h"

void Semafor::setState(Semafor::Stanje newState) {
	currentState = newState;
}

void Semafor::nextState() {
	switch (currentState)
	{
	case Semafor::Stanje::Crveno: // trenutno stanje
		setState(Stanje::CrvenoZuto); // sljedeće stanje
		break;
	case Semafor::Stanje::Zuto:
		setState(Stanje::Crveno);
		break;
	case Semafor::Stanje::CrvenoZuto:
		setState(Stanje::Zeleno);
		break;
	case Semafor::Stanje::Zeleno:
		setState(Stanje::Zuto);
		break;
	case Semafor::Stanje::Invalid:
		setState(Stanje::Crveno);
		break;
	default:
		break;
	}
}

void Semafor::printState() {
	switch (currentState)
	{
	case Semafor::Stanje::Crveno: // trenutno stanje
		cout << "Crveno" << endl;
		break;
	case Semafor::Stanje::Zuto:
		cout << "Zuto" << endl;
		break;
	case Semafor::Stanje::CrvenoZuto:
		cout << "CrvenoZuto" << endl;
		break;
	case Semafor::Stanje::Zeleno:
		cout << "Zeleno" << endl;
		break;
	case Semafor::Stanje::Invalid:
		cout << "Invalid" << endl;
		break;
	default:
		break;
	}
}

void Semafor::run() {
	switch (currentState)
	{
	case Semafor::Stanje::Crveno: // trenutno stanje
		Sleep(2000);
		break;
	case Semafor::Stanje::Zuto:
		Sleep(2000);
		break;
	case Semafor::Stanje::CrvenoZuto:
		Sleep(2000);
		break;
	case Semafor::Stanje::Zeleno:
		Sleep(2000);
		break;
	case Semafor::Stanje::Invalid:
		Sleep(2000);
		break;
	default:
		break;
	}
}
