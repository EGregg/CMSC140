/*
* Class: CMSC140 CRN
* Instructor: Dr. Azhandeh
* Project4
* Description: Write a program that outputs employee id numbers, their number of absences, and figures out the average amount of days absent per employee
* Due Date: 11/18/2019
* I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here: Edward Gregg

* Pseudocode or Algorithm for the program:
(be sure to indent items with control structure)
(need to match flow chart submitted in documentation)
1.	Start program
2.	Function NumOfEmployees
a.	Ask for number of employees
a.	Return the number of employees
3.	Function TotDaysAbsent
a.	Ask for the employee id
b.	Ask for the number of days absent
i.	Validate the number of days !< 0
c.	Write the employee ID and days missed to file
d.	Return total number of days missed by employees
4.	Function averageAbsent
a.	Get the average dividing total days absent / total number of employees
b.	Return the average number of days
*/


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//global variable declaration for output
ofstream output;

int NumOfEmployees();
int TotDaysAbsent(ofstream&, int);
double averageAbsent(int, int);
void credit();


int main() {
	{
		output.open("employeeAbsences.txt");

		int numberOfEmployees;
		int totalDaysAbsent;
		double averageDaysAbsent;

		output << "EMPLOYEE ABSENCE REPORT" << endl;
		output << "employee id   days absent" << endl;



		numberOfEmployees = NumOfEmployees();

		totalDaysAbsent = TotDaysAbsent(output, numberOfEmployees);

		averageDaysAbsent = averageAbsent(totalDaysAbsent, numberOfEmployees);

		output << "The average number of days absent is " << fixed << setprecision(2) << averageDaysAbsent << " days.";

		cout << "The average number of days absent is " << fixed << setprecision(2) << averageDaysAbsent << " days.";

		output.close();

		credit();
	}
	system("pause");
	return 0;

}

//asks the user for the number of employees
int NumOfEmployees()
{
	int totalEmployees = 0;

	cout << "How many employees are there? ";
	cin >> totalEmployees;

	return totalEmployees;
}

//argument is the number of employees, outputs the employee id and employee number of days
int TotDaysAbsent(ofstream& output, int num1)
{
	int employeeID = 0;
	int daysAbsent = 0;
	int daysAbsentTotal = 0;

	for (int counter = 0; counter < num1; counter++)
	{
		cout << "Employee ID number: ";
		cin >> employeeID;

		cout << "Number of days absent for the employee: ";
		cin >> daysAbsent;

		while (daysAbsent < 0)
		{
			cout << "Days absent must be greater than or equal to 0, please try again: ";
			cin >> daysAbsent;
		}

		cout << endl;

		output << setw(8) << employeeID << " " << setw(13) << daysAbsent << endl;
	
		daysAbsentTotal += daysAbsent;

	}

	output << "The " << num1 << " employees were absent a total of " << daysAbsentTotal << " days.\n";


	return daysAbsentTotal;
}


//function to get the average days absent per employee
//rule of no file output
double averageAbsent(int daysAbsentTotal, int numberOfEmployeesTotal)
{
	//get the average amount of days absent
	return double(daysAbsentTotal) / double(numberOfEmployeesTotal);
}

void credit()//where credit is due
{
	const string PROGRAMMER_NAME = "Edward Gregg";
	const string ASSIGNMENT_NUMBER = "Common Project 4";
	const string DUE_DATE = "11/18/2019";
	cout << endl << endl;
	cout << "PROGRAMMER: " << PROGRAMMER_NAME << endl;
	cout << "CMSC140 " << ASSIGNMENT_NUMBER << endl;
	cout << "Due Date : " << DUE_DATE << endl;
	cout << "\n";
}
