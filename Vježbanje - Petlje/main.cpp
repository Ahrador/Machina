#include <iostream>
#include <string>
using namespace std;


// Vježbanje petlji - for, while, do while i statements (if, else if, else)

int main() {
	// Write a program that prints out the first 10 natural numbers, using a for loop.
	for (int i = 1; i <= 10; i++) {
		cout << i << " ";
	}
		// 0 is not natural number so counter starts at 1

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


	// If statements

	/*
	Write a program that asks the user to enter a number and then prints 
	whether the number is positive or negative.
	*/
	int brojikus;
	cout << "Enter a number: ";
	cin >> brojikus;

	if (brojikus > 0) {
		cout << "The number is positive\n";
	} else if (brojikus < 0) {
		cout << "The number is negative\n";
	}
	else {
		cout << "THe number is zero\n";
	}

	/*
	Write a program that asks the user to enter two numbers and then prints
	the larger of the two numbers.
	*/
	int BROJ, BROJ2;
	cout << "Enter number 1: " << endl;
	cin >> BROJ;
	cout << "Enter number 2: " << endl;
	cin >> BROJ2;

	if (BROJ > BROJ2) {
		cout << BROJ;
	} if (BROJ2 > BROJ) {
		cout << BROJ2 << endl;
	}

	/*
	Write a program that asks the user to enter their age and then prints 
	whether they are a child (0-12), a teenager (13-19), an adult (20-59), 
	or a senior (60 and above).
	*/

	int age;
	cout << "Enter your age: ";
	cin >> age;

	if (age >= 0 && age < 13) {
		cout << "Your age is " << age << ". You are a child.\n";
	} 
	else if (age > 12 && age < 20) {
		cout << "Your age is " << age << ". You are a teenager.\n";
	}
	else if (age > 19 && age < 60) {
		cout << "Your age is " << age << ". You are an adult.\n";
	}
	else if (age >=60) {
		cout << "Your age is " << age << " You are a senior.";
	}


	/*
	Write a program that asks the user to enter a password. If the password 
	is correct (e.g. "password123"), print a message saying "Access granted". 
	If the password is incorrect, print a message saying "Access denied".
	*/

	string password;
	cout << "Enter a password: ";
	cin >> password;

	string correct = "password123";

	if (password == correct) {
		cout << "Access granted";
	}
	else {
		cout << "Access denied";
	}
	
	
	/*
	Write a program that asks the user to enter a number between 1 and 10. 
	If the number is less than 5, print "Too low". If the number is greater 
	than 5, print "Too high". If the number is equal to 5, print "Just right!".
	*/

	cout << "Enter a number between 1 and 10: ";
	int numbario;
	cin >> numbario;

	if (numbario < 5) {
		cout << "Too low";
	}
	else if (numbario > 5) {
		cout << "Too high";
	}
	else if (numbario == 5) {
		cout << "Just right!";
	}

	
	/*
	Write a program that asks the user to enter three numbers and then prints 
	the largest of the three numbers.
	*/
	
	int first_broj, second_broj, third_broj, largest;
	cout << "Enter three numbers: ";
	cin >> first_broj >> second_broj >> third_broj;

	if (first_broj >= second_broj && first_broj >= third_broj) {
		largest = first_broj;
	}
	else if (second_broj >= first_broj && second_broj >= third_broj) {
		largest = second_broj;
	}
	else {
		largest = third_broj;
	}

	cout << "The largest number is " << largest << endl;


	// While petlje

	/*
	Write a program that asks the user to enter a positive integer and then 
	displays the sum of all the integers from 1 to that number.
	*/

	cout << "Input a positive integer: ";
	int pozitivni_broj;
	cin >> pozitivni_broj;
	int sumaaa = 0;

	while (pozitivni_broj < 1) {
		cout << "Invalid input. Enter a positive integer: ";
		cin >> pozitivni_broj;
	}

	int i = 1;
	while (i <= pozitivni_broj) {
		sumaaa += i;
		i++;
	}
	cout << "The sum of all integers from 1 to " << pozitivni_broj << " is " << sumaaa << endl;
	return 0;
		








}
