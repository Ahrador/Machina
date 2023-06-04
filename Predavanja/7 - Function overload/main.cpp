#include <iostream>
using namespace std;

// Predavanje 7 - Switch, Function overloading, headeri, STL string

/*
Timestamps:
12:13 - if else / switch case
12:33 - function overloading
12:47 ---- setPosition putem struct
12:51 ---- SFML setPosition
12:53 ---- Razlika izmedu C++ i C# compilera za function overload ?
13:03 - Pauza 10 min (zadatak na satu: semafor sa if else i switch)
13:12 - Semafor zadatak
13:22 - Podjela klasa radi modularnosti (header za deklaracije), (.cpp za definicije)
14:16 - Overloading 2
14:21 - Pauza 15 min
14:37 - Stringovi
*/


// 12:47 ---- setPosition putem struct

// SFML primmjer za setPosition
struct Vector2f {
	float first
		float second;
};


struct Position {
	int x;
	int y;
};

struct ObjectOnScreen {
	Position position;

	void setPosition(int x, int y) {
		position.x = x;
		position.y = y;
	}

	void setPosition(Position newPosition) {
		position = newPosition;
	}
};




//------------------------------------------------------

// Function overload - moze bit koliko zelimo parametara
// poziva se ona s najvise argumenata
// __FUNCTION__ - printa ime funkcije
// __FUNCSIG__ - daje cijelu funkciju tj imena parametara na ispis

float zbroj(int x, int y) {
	cout << __FUNCSIG__ << endl;
	return x + y;
}

// overload - primjer s float kao lijevi parametar
float zbroj(float x, int y) {
	cout << __FUNCSIG__ << endl;
	return x + y;
}

// overload - primjer gdje je float kao oba parametra
float zbroj(float x, float y) {
	cout << "Treca" << endl;
	return x + y;
}

// overload - primjer gdje je float desni parametar
float zbroj(int x, float y) {
	cout << "Cetvrta" << endl;
	return x + y;
}

int main() {
	// ako tu upisem float ispred brojki u zagradi, poziva se direktno ta funkcija jer pase
	cout << zbroj((float)1, (float)31) << endl;
	//cout << zbroj(1, 3) << endl; 


	// za set position
	ObjectOnScreen slika;
	slika.setPosition(10, 15);

	//Position tocka;
	//slika.setPosition(tocka);






}