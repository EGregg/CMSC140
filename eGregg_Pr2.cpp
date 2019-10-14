/*
* Class: CMSC140 CRN
* Instructor:
* Project2
* Description: Write a program that shows the following menu options and lets the user to convert from Metric to Imperial system:
* Due Date:
* I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here: __________


* Pseudocode or Algorithm for the program:
(be sure to indent items with control structure)
(need to match flow chart submitted in documentation)
1.
2.
3.
4.
5.
(more as needed)
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int choice;
	float temperatureC;
	float temperatureF;
	float distanceK;
	float distanceM;
	float weightK;
	float weightP;
	
	cout << "Converter Toolkit" << endl;
	cout << "--------------------" << endl;
	cout << "\t1. Temperature Converter" << endl;
	cout << "\t2. Distance Converter" << endl;
	cout << "\t3. Weight Converter" << endl;
	cout << "\t4. Quit" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1: cout << "enter temperature in Celsius" << endl;// code to be executed if n = 1;
		cin >> temperatureC; 
		temperatureF = (1.8 * temperatureC) + 32; //convert using F = (9/5)*C + 32
		cout << temperatureF << endl; 
		break;

	case 2: cout << "enter distance in Kilometers" << endl;// code to be executed if n = 2;
		cin >> distanceK; 
		if (distanceK >= 0) //numbers cannot be negative
			{
			distanceM = 0.6 * distanceK; cout << distanceM << endl; // miles = 0.6*kilometers
			}
		else
		{
			cout << "Distance cannot be Negative" << endl;
		}
			break;

	case 3: cout << "enter weight in Kilogram: ";
		cin >> weightK;
		if (weightK >= 0) //numbers cannot be negative
			{
				weightP = 2.2 * weightK; cout << weightP << endl; //pounds = 2.2*kilograms 
			}
		else
		{
			cout << "Weight cannot be Negative" << endl;
		}
		
		break;

	case 4: break;// code to be executed if n doesn't match any cases
	}
}
