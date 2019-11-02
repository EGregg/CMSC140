#include <iostream>
#include <string>
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

	int counter;



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

		//if number
		while (numberOfFloors < 1 || numberOfFloors > 5)
		{
			cout << "Enter total number of floors of the hotel (number of floors should be between 1 and 5): ";
			cin >> numberOfFloors;
		}

		for (currentFloor = 1; currentFloor <= numberOfFloors; currentFloor++)
		{
			cout << endl;
			cout << "Enter total number of rooms on the " << currentFloor << " floor: "; //make a loop going through each floor < floors and set it to currentFloor
			cin >> numberOfRooms;

			while (numberOfRooms < 1 || numberOfRooms > 30)
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

		}

		{
			//Final output

			for (counter = 0; counter < 120; counter++)
			{
				cout << "=";
			}

			cout << endl;
			cout << "\t\t\t" << "BlueMont Hotel Located In " << location << endl;
			cout << "\t\t\t\t" << "TODAY'S ROOM RATES(US$/night)" << endl;
			cout << "\t" << "Single Room" << "\t\t" << "Double Room" << "\t\t" << "King Room" << "\t\t" << "Suite Room" << endl;
			cout << "\t\t " << singleRoom << "\t\t\t" << doubleRoom << "\t\t\t" << kingRoom << "\t\t\t" << suiteRoom << endl;

			cout << endl;

			for (counter = 0; counter < 120; counter++)
			{
				cout << "=";
			}
		}
	}
	system("pause");
}
