#include<iostream>
using namespace std;

// Global constants 
const int ROWS = 3;  // The number of rows in the array
const int COLS = 3;  // The number of columns in the array
const int MIN = 1;  // The value of the smallest number
const int MAX = 9;  // The value of the largest number

					// Function prototypes
//bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
//bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max);
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
//bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
//bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
//bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
//void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
//void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);

int main()
{
	int array1[] = { 1, 2, 3 };
	int array2[] = { 4, 5, 6 };
	int array3[] = { 7, 8, 1 };


	/* Define a Lo Shu Magic Square using 3 parallel arrays corresponding to each row of the grid */
	//int magicArrayRow1[COLS], magicArrayRow2[COLS], magicArrayRow3[COLS];

	cout << checkUnique(array1, array2, array3, 3);

	// Your code goes here
	system("pause");
	return 0;
}
// Function definitions go here
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
	bool unique = true;

	for (int j = 0; j < size; j++)
	{
		for (int k = 0; k < size; k++)
		{
			if (arrayRow1[j] == arrayRow2[k])
			{
				cout << arrayRow1[j] << " " << arrayRow2[k] << endl;
				cout << "non unique value found" << endl;
				return false;

			}
		}

		for (int k = 0; k < size; k++)
		{
			if (arrayRow1[j] == arrayRow3[k])
			{
				cout << arrayRow1[j] << " " << arrayRow3[k] << endl;
				cout << "non unique value found" << endl;
				return false;

			}
		}
	}
	return unique;
}
