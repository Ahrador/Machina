#include <iostream>
using namespace std;

int main() {

	// -----------------------------------------------------------------------
	// Petlje - Zadatak 1
	// Write a program that prints out the first 10 natural numbers, using a for loop.

	for (int i = 1; i <= 10; i++) {
		cout << i << " ";
	}
		// 0 is not natural number so counter starts at 1
		// " " in cout means there is space bwtween each number for clarity


	// -----------------------------------------------------------------------
	// Petlje - Zadatak 2
	/*
	Write a program that calculates and prints the factorial of a number 
	entered by the user, using a for loop.
	*/ 

	int broj;
	cout << "Please enter a positive integer: ";
	cin >> broj;

	int factorial = 1;

	for (int i = 1; i <= broj; i++) {
		factorial *= i;
	}
	cout << "The factorial of " << broj << " is " << factorial << "\n";


	// -----------------------------------------------------------------------
	// Petlje - Zadatak 3
	/*
	Write a program that calculates and prints the sum of the first n odd 
	numbers, using a for loop.
	*/

	int n;
	cout << "Enter a positive integer: ";
	cin >> n;

	// Inicijalizacija varijable gdje će suma biti spremljena
	int sum = 0;

	// For petlja za iteriranje kroz prvih n neparnih brojeva i njihovo dodavanje u sumu
	for (int i = 1; i <= 2 * n; i += 2) {
		sum += i;
	}
	cout << "The sum of the first " << n << " odd numbers is: " << sum << endl;
	// -----------------------------------------------------------------------


	// -----------------------------------------------------------------------
	// Petlje - Zadatak 4
	/*
	Write a program that prints out a multiplication table for a number 
	entered by the user, using a for loop.
	*/

	int number;
	cout << "Upisite broj: ";
	cin >> number;

	for (int i = 1; i <= 10; ++i) { // the loop ce se izvest 10 puta
		cout << " x " << i << " = " << number * i << "\n";
	}
	// -----------------------------------------------------------------------


	// -----------------------------------------------------------------------
	// Petlje - Zadatak 5
	/*
	Write a program that calculates and prints the sum of the digits of 
	a number entered by the user, using a for loop.
	*/

	int brojario;
	cout << "Daj broj: ";
	cin >> brojario;

	int suma = 0; // ovo se koristi za spremanje zbroja znamenaka unesenog broja

	for (int i = brojario; i > 0; i /= 10) {
		suma += i % 10;
	}
	cout << "Sum of the digits of " << brojario << " is " << suma << "\n";

	/*
	Petlja for koja će se izvoditi sve dok je varijabla i veća od 0. 
	Početna vrijednost varijable i se postavlja na vrijednost unesenog 
	broja 'brojario', a nakon svakog prolaza petlje se varijabla i dijeli s 10 
	(koristeći operator /=) kako bi se uzela sljedeća znamenka za obradu.
	*/




}