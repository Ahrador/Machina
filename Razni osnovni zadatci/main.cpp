#include <iostream>
#include <string>
using namespace std;

int main() {

	// RAZNI ZADATCI S INTERNETA ZA VJEŽBU:

	// ZADATAK 1
	/*
	Create a program that asks the user to input their name and age,
	and then displays the information on the screen using appropriate
	data types for each input.
	*/

	// Zatraži unos korisnikovog imena i pročitaj ga
	cout << "Please enter your name: ";
	string name;
	cin >> name;

	// Zatraži unos korisnikove dobi i pročitaj je
	cout << "Please tell us your age: ";
	int age;
	cin >> age;

	// Ispiši ime i dob na konzolu
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;

	// Vrati 0 kako bi se označilo uspješno izvršavanje programa
	//return 0;


	// ZADATAK 2
	/*
	Write a program that calculates the area and perimeter of a rectangle
	given its length and width. Use appropriate data types and display
	the results on the screen.
	*/

	// Deklaracija varijabli za širinu i dužinu
	double length, width;

	// Unos dužine i širine
	cout << "Enter the length of the rectangle ";
	cin >> length;
	cout << "Enter the width of the rectangle ";
	cin >> width;

	// Izračunaj area and perimeter of the rectangle
	double area = length * width;
	double perimeter = 2 * (length + width);

	// Ispis na konzolu
	cout << "The area of the rectangle is: " << area << endl;
	cout << "The perimeter of the rectangle is: " << perimeter << endl;


	// ZADATAK 3
	/*
	Create a program that asks the user to enter two numbers, and then swaps
	the values of those numbers using variables and appropriate data types.
	*/

	// Deklaracija dvije varijable te treće u koju se sprema jedan od brojeva nakratko
	int value1, value2, temp;

	// Unos brojeva i njihov ispis na konzolu
	cout << "Enter first number ";
	cin >> value1;
	cout << "Enter second number ";
	cin >> value2;

	temp = value1; // Dodijelite vrijednost prve varijable trećoj
	value1 = value2; // Dodijelite vrijednost druge varijable prvoj
	value2 = temp; 	// Dodijelite vrijednost treće varijable drugoj

	// Ispit zamijenjenih vrijednosti na konzoli / zaslonu
	cout << "After swapping, first number is " << value1 << " and second number is " << value2 << endl;


	// ZADATAK 4
	/*
	Write a program that converts Fahrenheit temperature to Celsius temperature.
	The program should ask the user to enter a temperature in Fahrenheit and then
	output the temperature in Celsius.
	*/

	// Deklaracija varijabli
	double temp_f, temp_c;

	// Unos i ispis temperature u Fahrenheitu
	cout << "Enter a temperature in Fahrenheit ";
	cin >> temp_f;

	// Formula za pretvorbu Fahrenheit u Celsius
	temp_c = (temp_f - 32) * 5 / 9;

	// Ispis rješenja na konzolu
	cout << "The temperature in Celsius is " << temp_c << endl;


	// ZADATAK 5
	/*
	Create a program that calculates the average of three numbers. The program
	should ask the user to enter three numbers, and then output their average.
	*/

	// Deklaracija varijabli
	int num1, num2, num3;

	// Unos i ispis svakog broja na konzolu
	cout << "Unesite prvi broj ";
	cin >> num1;

	cout << "Unesite drugi broj ";
	cin >> num2;

	cout << "Unesite treci broj ";
	cin >> num3;

	// Zbroji sva tri broja te zbroj podijeli s 3 da dobijes njihov average
	int rjesenje = (num1 + num2 + num3) / 3;

	// Ispis rješenja na konzolu
	cout << "The average od ova tri broja je " << rjesenje << endl;


	// ZADATAK 6
	/*
	Write a program to take input from the user for their name and age, and
	output a message that says "Hello [name], you are [age] years old."
	*/

	string ime;
	int dob;

	cout << "Your name is: ";
	cin >> ime;
	cout << "Your age is: ";
	cin >> dob;

	cout << "Hello " << ime << ", you are " << dob << " years old." << endl;


	// ZADATAK 7
	/*
	Write a program to calculate the sum, difference, product, and quotient of
	two numbers entered by the user.
	*/

	int number1, number2;  // Deklaracije varijabli za dva broja
	int sum, difference, product;  // Deklaracije za spremanje rezultata
	float quotient;

	cout << "Enter first number ";
	cin >> number1;

	cout << "Enter second number ";
	cin >> number2;

	sum = number1 + number2;
	difference = number1 - number2;
	product = number1 * number2;
	quotient = number1 / number2;

	cout << "Sum of these two numbers is " << sum;
	cout << "Difference of these two numbers is " << difference;
	cout << "Product of these two numbers is " << product;
	cout << "Quotient of these two numbers is " << quotient << endl;


	// ZADATAK 8
	/*
	Write a program to take input from the user for five integers and store them
	in an array. Output the sum of the integers.
	*/

	int niz[5];  // niz velicine 5 za spremanje 5 integera
	int iznos = 0;  // ovo ce bit koristeno za spremanje sume tih 5 integera

	for (int i = 0; i < 5; i++) {
		cout << "Enter integer " << i + 1 << ": ";
		cin >> niz[i];
		iznos += niz[i];  // add input to sum
	}
	cout << "The sum of the five integers is: " << iznos << endl; // Output sum


	// ZADATAK 9
	/*
	Write a program to take input from the user for ten integers and store them in
	an array. Output the largest and smallest integers in the array.
	*/

	int array[10];
	int max_val, min_val;

	// prompt user to input ten integers and store them in array
	for (int i = 0; i < 10; i++) {
		cout << "Enter integer " << i + 1 << ": ";
		cin >> array[i];
	}

	// prompt user to input ten integers and store them in array
	max_val = array[0];
	min_val = array[0];

	// iterate over array to find max and min values
	for (int i = 1; i < 10; i++) {
		if (array[i] > max_val) {
			max_val = array[i];
		}
		if (array[i] < min_val) {
			min_val = array[i];
		}
	}

	// output max and min values
	cout << "Maximum value: " << max_val << endl;
	cout << "Minimum value: " << min_val << endl;

}