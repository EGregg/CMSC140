#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;


int main()
{
	

	//first half of program
	const string ROBOTNAME = "Nao";
	const int ONE_DOG_YEAR = 7;
	const int DAYS_PER_MONTH = 30;
	int numberEntered;
	string visitorName;

	cout << "**************** Robot Prototype Scripting ********************" << endl;
	cout << endl;
	cout << "Hello, welcome to Montgomery College! My name is " << ROBOTNAME << " . May I have your name ?" << endl;
	getline (cin, visitorName);
	cout << "Nice to have you with us today, " << visitorName << "!" << endl;
	cout << "Let me impress you with a small game." << endl;
	cout << "Give me the age of an important person or a pet to you." << endl;
	cout << "Please give me only a number :" << endl;
	cin >> numberEntered;
	cout << endl;
	cout << "You have entered " << numberEntered << "." << endl;
	cout << "If this is for a person, the age can be expressed as :" << endl;
	cout << numberEntered << " years" << endl;
	cout << "or " << numberEntered * 12 << " months" << endl;
	cout << "or about " << numberEntered * 360 << " days" << endl;
	cout << "or about " << numberEntered * 360 * 24  << " hours" << endl; 
	cout << "or about " << numberEntered * 360 * 24 * 60 << " minutes" << endl;
	cout << "or about " << numberEntered * 360 * 24 * 60 * 60 << " seconds." << endl;
	cout << "If this is for a dog, it is " << numberEntered * 7 << " years old in human age." << endl;
	cout << "If this is for a gold fish, it is " << numberEntered * 5 << " years old in human age." << endl;
	cout << endl;

	//second half of the program
	int wholeNumber1, wholeNumber2;
	cout << "Let's play another game, " << visitorName << ". Give me a whole number." << endl;
	cin >> wholeNumber1;
	cout << "Very well.Give me another whole number." << endl;
	cin >> wholeNumber2;
	cout << "Using the operator '+' in C++, the result of " << wholeNumber1 << " + " << wholeNumber2 << " is " << wholeNumber1 + wholeNumber2 << "." << endl;
	cout << "Using the operator '/', the result of " << wholeNumber1 << " / " <<  wholeNumber2 << " is " << wholeNumber1 / wholeNumber2 << endl;
	cout << "however, the result of " << fixed << setprecision(1) << float(wholeNumber1) << " / " << float(wholeNumber2) << " is about " << float(wholeNumber1) / float(wholeNumber2) << "." << endl;
	cout << endl;
	cout << "Thank you for testing my program!!" << endl;
	
	//where credit is due
	const string PROGRAMMERNAME = "Edward Gregg";
	const string assignmentNumber = "Common Project 1";
	const string dueDate = "09 / 30 / 2019";
	cout << "PROGRAMMER: " << PROGRAMMERNAME << endl;
	cout << "CMSC140 " << assignmentNumber << endl;
	cout << "Due Date : " << dueDate << endl;
	cout << "\n";
	
	
	
	
	
	system("pause");
}
