/*
* Class: CMSC140 CRN
* Instructor:
* Project1
* Description: Write a program to show a greeting script that the department's humanoid robot could use later
* Due Date: 09/30/2019
* I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here: Edward Gregg


* Pseudocode or Algorithm for the program:
(be sure to indent items with control structure)
(need to match flow chart submitted in documentation)
1.	initialize const string variable ROBOTNAME
2.	initialize const int variable ONE_DOG_YEAR
3.	initialize const int variable ONE_GOLDFISH_YEAR
4.	initialize const int variable DAYS_PER_MONTH
5.	declare int variable age
6.	declare string variable visitorName
7.	output greeting and ROBOTNAME, ask for name
8.	accept input visitorName
9.	output asking to give a number
10.	accept input age
11.	output age
12.	output age in years
13.	output age in months
14.	output age in days using DAYS_PER_MONTH
15.	output age in hours by multiplying days * 24
16.	output age in minutes by multiplying hours * 60
17.	output age in seconds by multiplying minutes * 60
18.	output age in dog years by multiplying age * ONE_DOG_YEAR
19.	output age in goldfish years by multiplying age * ONE_GOLDFISH_YEAR

20.	declare variables int wholeNumber1 and wholeNumber2
21.	output asking for wholeNumber1
22.	accept input for wholeNumber1
23.	output asking for wholeNumber2
24.	accept input for wholeNumber2
25.	output add wholeNumber1 + wholeNumber2
26.	output divide wholeNumber1 / wholeNumber2
27.	output fixed and setprecision for 1, typecast float wholeNumber1 divide by typecast float wholeNumber2

28.	initialize const string PROGRAMMER_NAME
29.	initialize const string ASSIGNMENT_NUMBER
30.	initialize const string DUE_DATE
31.	output PROGRAMMER_NAME
32.	output ASSIGNMENT_NUMBER
33.	output DUE_DATE

*/


/* First project: Write a program to show a greeting script that the department's humanoid robot could use later*/

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;


int main()
{
	

	//greeting and age game
	const string ROBOTNAME = "Nao";
	const int ONE_DOG_YEAR = 7;
	const int ONE_GOLDFISH_YEAR = 5;
	const int DAYS_PER_MONTH = 30;
	int age;
	string visitorName;

	cout << "**************** Robot Prototype Scripting ********************" << endl;
	cout << endl;
	cout << "Hello, welcome to Montgomery College! My name is " << ROBOTNAME << ". May I have your name?" << endl;
	getline (cin, visitorName);
	cout << "Nice to have you with us today, " << visitorName << "!" << endl;
	cout << "Let me impress you with a small game." << endl;
	cout << "Give me the age of an important person or a pet to you." << endl;
	cout << "Please give me only a number:" << endl;
	cin >> age;
	cout << endl;
	cout << "You have entered " << age << "." << endl;
	cout << "If this is for a person, the age can be expressed as:" << endl;
	cout << age << " years" << endl;
	cout << "or " << age * 12 << " months" << endl;
	cout << "or about " << age * 12 * DAYS_PER_MONTH << " days" << endl; //age in days
	cout << "or about " << age * 12 * DAYS_PER_MONTH * 24  << " hours" << endl; //age in hours
	cout << "or about " << age * 12 * DAYS_PER_MONTH * 24 * 60 << " minutes" << endl; //age in minutes
	cout << "or about " << age * 12 * DAYS_PER_MONTH * 24 * 60 * 60 << " seconds." << endl; //age in seconds
	cout << "If this is for a dog, it is " << age * ONE_DOG_YEAR << " years old in human age." << endl; //age of dog in human years
	cout << "If this is for a gold fish, it is " << age * ONE_GOLDFISH_YEAR << " years old in human age." << endl; //age of goldfish in human years
	cout << endl;

	//wholenumber addition and division
	int wholeNumber1, wholeNumber2;
	cout << "Let's play another game, " << visitorName << ". Give me a whole number." << endl;
	cin >> wholeNumber1;
	cout << "Very well. Give me another whole number." << endl;
	cin >> wholeNumber2;
	cout << "Using the operator '+' in C++, the result of " << wholeNumber1 << " + " << wholeNumber2 << " is " << wholeNumber1 + wholeNumber2 << "." << endl;
	cout << "Using the operator '/', the result of " << wholeNumber1 << " / " <<  wholeNumber2 << " is " << wholeNumber1 / wholeNumber2 << endl;
	cout << "however, the result of " << fixed << setprecision(1) << float(wholeNumber1) << " / " << float(wholeNumber2) << " is about " << float(wholeNumber1) / float(wholeNumber2) << "." << endl;
	cout << endl;
	cout << "Thank you for testing my program!!" << endl;
	
	//where credit is due
	const string PROGRAMMER_NAME = "Edward Gregg";
	const string ASSIGNMENT_NUMBER = "Common Project 1";
	const string DUE_DATE = "09/30/2019";
	cout << "PROGRAMMER: " << PROGRAMMER_NAME << endl;
	cout << "CMSC140 " << ASSIGNMENT_NUMBER << endl;
	cout << "Due Date : " << DUE_DATE << endl;
	cout << "\n";
	
	
	
	
	
	system("pause");
}
