#include<iostream>
#include<string>
using namespace std;

// Global constants 
const int ROWS = 3;  // The number of rows in the array
const int COLS = 3;  // The number of columns in the array
const int MIN = 1;  // The value of the smallest number
const int MAX = 9;  // The value of the largest number

					// Function prototypes
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max);
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void fillArray(int (&arrayRow1)[3], int (&arrayRow2)[3], int (&arrayRow3)[3], int size); //is there a different way to prototype a function using a reference array?
void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
//void test(int&);

int main()
{
	/* Define a Lo Shu Magic Square using 3 parallel arrays corresponding to each row of the grid */
	int magicArrayRow1[COLS], magicArrayRow2[COLS], magicArrayRow3[COLS];

	fillArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, 3); //fillArray has to be called first!!!
	isMagicSquare(magicArrayRow1, magicArrayRow2, magicArrayRow3, 3);
	showArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, 3);

	////////////////////////////////////////////////////////////////////////////////
	// code for checking each individual function
	////////////////////////////////////////////////////////////////////////////////
	//cout << checkRange(magicArrayRow1, magicArrayRow2, magicArrayRow3, 3, MIN, MAX) << endl;
	//cout << checkUnique(magicArrayRow1, magicArrayRow2, magicArrayRow3, 3) << endl;
	//cout << checkRowSum(magicArrayRow1, magicArrayRow2, magicArrayRow3, 3) << endl;
	//cout << checkColSum(magicArrayRow1, magicArrayRow2, magicArrayRow3, 3) << endl;
	//cout << checkDiagSum(magicArrayRow1, magicArrayRow2, magicArrayRow3, 3) << endl;

	system("pause");
	return 0;
}

////////////////////////////////////////////////////////////////////////////////
// Magicsquare function that returns true if all the other functions return true
////////////////////////////////////////////////////////////////////////////////
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
	//set these variables for easy readability in the if conditional
	bool checkU = checkUnique(arrayRow1, arrayRow2, arrayRow3, size);
	bool checkR = checkRange(arrayRow1, arrayRow2, arrayRow3, size, MIN, MAX);
	bool checkRS = checkRowSum(arrayRow1, arrayRow2, arrayRow3, size);
	bool checkCS = checkColSum(arrayRow1, arrayRow2, arrayRow3, size);
	bool checkDS = checkDiagSum(arrayRow1, arrayRow2, arrayRow3, size);


	if (!checkU || !checkR || !checkRS || !checkCS || !checkDS)
	{
		cout << "This is not a magic square" << endl;
		return false;
	}

	cout << "We have a magic square!" << endl;
	return true;

}

////////////////////////////////////////////////////////////////////////////////
//checks if each number is unique in the magic square
////////////////////////////////////////////////////////////////////////////////
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{

	//check if each element in the individual array is unique
	//iterates over an array
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arrayRow1[i] == arrayRow1[j])
			{
				cout << "Non unique in ArrayRow1" << endl;
				return false;
			}
		}
	}

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arrayRow2[i] == arrayRow2[j])
			{
				cout << "Non unique in ArrayRow2" << endl;
				return false;
			}
		}
	}

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arrayRow3[i] == arrayRow3[j])
			{
				cout << "Non unique in ArrayRow3" << endl;
				return false;
			}
		}
	}


	//iterate through multiple arrays here
	for (int j = 0; j < size; j++)
	{
		for (int k = 0; k < size; k++)
		{
			for (int l = 0; l < size; l++)
			{
				//uncomment the next line to see what's being compared at that moment
				//cout << arrayRow1[j] << " " << arrayRow2[k] << " " << arrayRow3[l] << endl;

				//looking for more elegant way to compare each array to each other
				if (arrayRow1[j] == arrayRow2[k] || arrayRow1[j] == arrayRow3[l] || arrayRow2[k] == arrayRow3[l])
				{
					cout << "non unique value found" << endl;
					return false;
				}
			}
		}
	}
	return true;
}

////////////////////////////////////////////////////////////////////////////////
//function to make sure each row is equal to each other
////////////////////////////////////////////////////////////////////////////////
bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{

	int total1 = 0, total2 = 0, total3 = 0;

	for (int i = 0; i < size; i++)
	{
		total1 += arrayrow1[i];
	}

	for (int i = 0; i < size; i++)
	{
		total2 += arrayrow2[i];
	}

	for (int i = 0; i < size; i++)
	{
		total3 += arrayrow3[i];
	}

	if (total1 == total2 && total2 == total3)
	{
		return true;
	}
	else
	{
		cout << "Rows do not add up equally" << endl;	
		return false;
	}
}

////////////////////////////////////////////////////////////////////////////////
//function to make sure each column is equal to each other
////////////////////////////////////////////////////////////////////////////////
bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
	int total1 = 0, total2 = 0, total3 = 0;

	total1 = arrayrow1[0] + arrayrow2[0] + arrayrow3[0];
	total2 = arrayrow1[1] + arrayrow2[1] + arrayrow3[1];
	total3 = arrayrow1[2] + arrayrow2[2] + arrayrow3[2];

	if (total1 == total2 && total2 == total3)
	{
		return true;
	}
	else
	{
		cout << "Columns do not add up equally" << endl;
		return false;
	}
}

////////////////////////////////////////////////////////////////////////////////
//function to make sure each diagonal is equal to each other
////////////////////////////////////////////////////////////////////////////////
bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
	int total1 = 0, total2 = 0, total3 = 0;

	total1 = arrayrow1[0] + arrayrow2[1] + arrayrow3[2];
	total2 = arrayrow1[2] + arrayrow2[1] + arrayrow3[0];

	if (total1 == total2)
	{
		return true;
	}
	else
	{
		cout << "Diagonals do not add up equally" << endl;
		return false;
	}
}

////////////////////////////////////////////////////////////////////////////////
//function to fill up the magic square
////////////////////////////////////////////////////////////////////////////////
void fillArray(int (&arrayRow1)[3], int (&arrayRow2)[3], int (&arrayRow3)[3], int size)
{
	int i = 0, j = 0, k = 0;

	cout << "enter number 1: ";
	cin >> arrayRow1[0];
	cout << "enter number 2: ";
	cin >> arrayRow1[1];
	cout << "enter number 3: ";
	cin >> arrayRow1[2];
	cout << "enter number 4: ";
	cin >> arrayRow2[0];
	cout << "enter number 5: ";
	cin >> arrayRow2[1];
	cout << "enter number 6: ";
	cin >> arrayRow2[2];
	cout << "enter number 7: ";
	cin >> arrayRow3[0];
	cout << "enter number 8: ";
	cin >> arrayRow3[1];
	cout << "enter number 9: ";
	cin >> arrayRow3[2];
}

////////////////////////////////////////////////////////////////////////////////
//function to make sure the range of each number is 1-9
////////////////////////////////////////////////////////////////////////////////
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max)
{

	//iterates over an array
	for (int i = 0; i < size; i++)
	{
		//checks if the element of the array is less than the min or greater than the max
		if (arrayRow1[i] < min || arrayRow1[i] > max || arrayRow2[i] < min || arrayRow2[i] > max || arrayRow3[i] < min || arrayRow3[i] > max)
		{
			cout << "A number is out of range" << endl;
			return false;
		}
	}
	return true;
}

////////////////////////////////////////////////////////////////////////////////
//function to show the magic square
////////////////////////////////////////////////////////////////////////////////
void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arrayrow1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arrayrow2[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arrayrow3[i] << " ";
	}
	cout << endl;
}

//void test(int& foobar)
//{
//	cout << "This is the test\n" << "enter a number: ";
//	cin >> foobar;
//}
