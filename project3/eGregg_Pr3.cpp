/*
* Class: CMSC140 CRN
* Instructor: Dr. Azhandeh
* Project2
* Description: Write a program that figures out a hotels income for 1 night
* Due Date: 11/04/2019
* I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here: Edward Gregg


* Pseudocode or Algorithm for the program:
(be sure to indent items with control structure)
(need to match flow chart submitted in documentation)
1.	Ask user for name of hotel
2.	Ask user for number of floors
	a.	Is number of floors less than 1 or more than 5?
		i.	If true go back to 2, else proceed
3.	Ask how many rooms are on the floor
	a.	Is number of rooms less than 1 or more than 30?
		i.	If true go back to 3, else proceed
4.	Ask how many occupied single rooms
5.	Ask how many occupied double rooms
6.	Ask how many occupied king rooms
7.	Ask how many occupied suite rooms
	a.	Store total number of occupied rooms
		i.	Check is total number of occupied rooms more than the number of total rooms on the floor, if true go back to 4, else proceed
	b.	Increase total amount of single rooms, double rooms, king rooms, suite rooms
	c.	Store lowest current occupancy floor
	d.	Is current floor number greater than number of floors? If no, go to 3 and increase currentFloor++, else proceed
8.	Output location and current rates
9.	Calculate hotel income
	a.	Display hotel income
10.	Calculate total occupied
	a.	Display total occupied
11.	Calculate total unoccupied
	a.	Display total unoccupied
12.	Calculate occupancy rate
	a.	Display occupancy rate
13.	Check if occupancy rate is <60
	a.	If yes, display message with what floor has lowest occupancy rate, else proceed
14.	End

*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	const int	singleRoom = 60,
		doubleRoom = 75,
		kingRoom = 100,
		suiteRoom = 150;
	string location;
	int		numberOfFloors, //cannot exceed 5 
		numberOfRooms,  //cannot exceed 30
		occupied, //cannot exceed rooms
		currentFloor,
		numberOfSingle,
		numberOfDouble,
		numberOfKing,
		numberOfSuite;

	int totalSingleRoom = 0,
		totalDoubleRoom = 0,
		totalKingRoom = 0,
		totalSuiteRoom = 0,
		totalNumberOfRooms = 0;

	int hotelIncome,
		totalRooms;

	double occupancyRate,
		totalOccupied,
		totalUnoccupied;

	int counter;

	double current = 0,
		temp;

	int improveOccupancyFloor = 1;




	//Welcome to BlueMount Hotel
	{

		for (counter = 0; counter < 80; counter++)
		{
			cout << "=";
		}

		cout << endl;
		cout << "\t\t\t" << "BlueMont Hotel";
		cout << endl;

		for (counter = 0; counter < 80; counter++)
		{
			cout << "=";
		}

		cout << endl << endl;
	}

	{
		cout << "Enter the location of this hotel chain: ";
		getline(cin, location);

		cout << "Enter total number of floors of the hotel: ";
		cin >> numberOfFloors;

		//input validation for number of floors
		while (numberOfFloors < 1 || numberOfFloors > 5)
		{
			cout << endl;
			cout << "Number of floors should be between 1 and 5 !! please try again." << endl;
			cout << "Enter total number of floors of the hotel (number of floors should be between 1 and 5): ";
			cin >> numberOfFloors;
		}

		for (currentFloor = 1; currentFloor <= numberOfFloors; currentFloor++)
		{
			cout << endl;
			cout << "Enter total number of rooms on the " << currentFloor << " floor: "; //make a loop going through each floor < floors and set it to currentFloor
			cin >> numberOfRooms;

			while (numberOfRooms < 1 || numberOfRooms > 30) //something learned was using the || comparison operator instead of the &&, I knew both but feel like I default to &&
			{
				cout << "Enter total number of rooms on the " << currentFloor << " floor (number of rooms should be between 1 and 30): "; //make a loop going through each floor < floors and set it to currentFloor
				cin >> numberOfRooms;
			}

			cout << "How many SINGLE rooms are occupied on the " << currentFloor << " floor: ";
			cin >> numberOfSingle;

			cout << "How many DOUBLE rooms are occupied on the " << currentFloor << " floor: ";
			cin >> numberOfDouble;

			cout << "How many KING rooms are occupied on the " << currentFloor << " floor: ";
			cin >> numberOfKing;

			cout << "How many SUITE rooms are occupied on the " << currentFloor << " floor: ";
			cin >> numberOfSuite;

			occupied = numberOfSingle + numberOfDouble + numberOfKing + numberOfSuite;

			//input validation for if the number of occupied rooms is greater than the number of rooms
			while (occupied > numberOfRooms)
			{
				cout << endl;
				cout << "Sorry, the number of occupied rooms exceeds number of rooms on " << currentFloor << ", Please enter the number of occupied rooms again" << endl;

				cout << "How many SINGLE rooms are occupied on the " << currentFloor << " floor: ";
				cin >> numberOfSingle;

				cout << "How many DOUBLE rooms are occupied on the " << currentFloor << " floor: ";
				cin >> numberOfDouble;

				cout << "How many KING rooms are occupied on the " << currentFloor << " floor: ";
				cin >> numberOfKing;

				cout << "How many SUITE rooms are occupied on the " << currentFloor << " floor: ";
				cin >> numberOfSuite;

				occupied = numberOfSingle + numberOfDouble + numberOfKing + numberOfSuite;

			}

			//hold total number of rooms of each type, MUST BE AT THE END OF THE LOOP -- This part was tricky and will be in the lessons learned part
			totalNumberOfRooms += numberOfRooms;
			totalSingleRoom += numberOfSingle;
			totalDoubleRoom += numberOfDouble;
			totalKingRoom += numberOfKing;
			totalSuiteRoom += numberOfSuite;

			//holds the room with the current highest percentage occupancy
			temp = current;
			current = static_cast<double>(numberOfSingle + numberOfDouble + numberOfKing + numberOfSuite) / static_cast<double>(numberOfRooms);
			if (current <= temp)
			{
				improveOccupancyFloor = currentFloor;
			}


		}

		{
			//Final output

			for (counter = 0; counter < 120; counter++)
			{
				cout << "=";
			}

			cout << endl;
			cout << "\t\t\t" << "BlueMont Hotel Located In " << location << endl;
			cout << "\t\t\t" << "TODAY'S ROOM RATES(US$/night)" << endl;
			cout << "\t" << "Single Room" << "\t\t" << "Double Room" << "\t\t" << "King Room" << "\t\t" << "Suite Room" << endl;
			cout << "\t\t " << singleRoom << "\t\t\t" << doubleRoom << "\t\t\t" << kingRoom << "\t\t\t" << suiteRoom << endl;

			cout << endl;

			for (counter = 0; counter < 120; counter++)
			{
				cout << "=";
			}

			cout << endl;

			hotelIncome = (singleRoom * totalSingleRoom) + (doubleRoom * totalDoubleRoom) + (kingRoom * totalKingRoom) + (suiteRoom * totalSuiteRoom);
			cout << "Hotel Income: " << "\t\t\t\t$" << hotelIncome << endl;


			cout << "Total # of rooms: " << "\t\t\t" << totalNumberOfRooms << endl;

			totalOccupied = totalSingleRoom + totalDoubleRoom + totalKingRoom + totalSuiteRoom;
			cout << "Total # of Occupied Rooms: " << "\t\t" << totalOccupied << endl;

			totalUnoccupied = totalNumberOfRooms - totalOccupied;
			cout << "Total # of UnOccupied Rooms: " << "\t\t" << totalUnoccupied << endl;

			occupancyRate = (totalOccupied / totalNumberOfRooms) * 100;
			cout << fixed << setprecision(2) << "Occupancy rate: " << "\t\t\t" << occupancyRate << "%" << endl;

			if (occupancyRate < 60)
			{
				cout << "Floor " << improveOccupancyFloor << " has the lowest occupancy rate." << endl << "Need to improve hotel occupancy rate!!";

			}

			//where credit is due
			{
				const string PROGRAMMER_NAME = "Edward Gregg";
				const string ASSIGNMENT_NUMBER = "Common Project 3";
				const string DUE_DATE = "11/04/2019";
				cout << endl << endl;
				cout << "PROGRAMMER: " << PROGRAMMER_NAME << endl;
				cout << "CMSC140 " << ASSIGNMENT_NUMBER << endl;
				cout << "Due Date : " << DUE_DATE << endl;
				cout << "\n";
			}
		}
	}
	system("pause");
}
