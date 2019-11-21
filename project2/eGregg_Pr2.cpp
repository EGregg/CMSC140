/*
* Class: CMSC140 CRN
* Instructor: Dr. Azhandeh
* Project2
* Description: Write a program that shows the following menu options and lets the user to convert from Metric to Imperial system
* Due Date: 10/14/2019
* I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here: Edward Gregg


* Pseudocode or Algorithm for the program:
(be sure to indent items with control structure)
(need to match flow chart submitted in documentation)
1. ask user for a country
2. ask user which toolkit to use
3. check if number is within range
	a. quit if out of range
4. case 1 is temperature converter
	a. ask for temp in celsius
	b. convert to fahrenheit
	c. display temperature in fahrenheit
5. case 2 is distance converter
	a. ask for distance in kilometers
	b. convert to miles
	c. display distance in miles
6. case 3 is weight converter
	a. ask for weight in kilograms
	b. convert to pounds
	c. display weight in pounds
7. case 4 is quit
8. display the original chosen country  + "is fun"
9. end the program
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	string country;
	int choice;
	float temperatureC;
	float temperatureF;
	float distanceK;
	float distanceM;
	float weightK;
	float weightP;

	cout << "Enter a country name: ";
	getline(cin, country);

	cout << "Converter Toolkit" << endl;
	cout << "--------------------" << endl;
	cout << "\t1. Temperature Converter" << endl;
	cout << "\t2. Distance Converter" << endl;
	cout << "\t3. Weight Converter" << endl;
	cout << "\t4. Quit" << endl;
	cout << endl;
	cout << "Enter your choice (1-4): ";
	cin >> choice;


	if (choice >= 1 && choice <= 4)
		switch (choice)
		{
		case 1: //temperature case
			cout << "Enter temperature in Celsius" << endl;// code to be executed if n = 1;
			cin >> temperatureC;
			temperatureF = (1.8 * temperatureC) + 32; //convert using F = (9/5)*C + 32
			cout << fixed << setprecision(2) << "The temperature in Fahrenheit is "<< temperatureF << endl;
			break;

		case 2: //distance case
			cout << "Enter distance in Kilometers" << endl;// code to be executed if n = 2;
			cin >> distanceK;
			if (distanceK >= 0) //numbers cannot be negative
			{
				distanceM = 0.6 * distanceK; cout << fixed << setprecision(1) << "The distance in miles is " << distanceM << endl; // miles = 0.6*kilometers
			}
			else
			{
				cout << "!! Program does not convert negative distance !!" << endl;
			}
			break;

		case 3: //weight case
			cout << "Enter weight in Kilogram: ";
			cin >> weightK;
			if (weightK >= 0) //numbers cannot be negative
			{
				weightP = 2.2 * weightK; 
				cout << "The weight in pounds is " << weightP << endl; //pounds = 2.2*kilograms 
			}
			else
			{
				cout << "!! Program does not convert negative weight !!" << endl;
			}

			break;

		case 4: //quit case 
			cout << "You've chosen to quit" << endl;
			break;
		}
	else
	{
		cout << "That is not a valid choice" << endl;
	}

	cout << country << " sounds fun!" << endl;

	//where credit is due
	const string PROGRAMMER_NAME = "Edward Gregg";
	const string ASSIGNMENT_NUMBER = "Common Project 2";
	const string DUE_DATE = "10/14/2019";
	cout << endl;
	cout << "PROGRAMMER: " << PROGRAMMER_NAME << endl;
	cout << "CMSC140 " << ASSIGNMENT_NUMBER << endl;
	cout << "Due Date : " << DUE_DATE << endl;
	cout << "\n";


	system("pause");
}
