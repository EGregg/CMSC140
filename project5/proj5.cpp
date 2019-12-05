#include<iostream>
using namespace std;

// Global constants 
const int ROWS = 3;  // The number of rows in the array
const int COLS = 3;  // The number of columns in the array
const int MIN = 1;  // The value of the smallest number
const int MAX = 9;  // The value of the largest number

					// Function prototypes
					//bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max);
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
void fillArray(int (&arrayRow1)[3], int (&arrayRow2)[3], int (&arrayRow3)[3], int size); //is there a different way to prototype a function using a reference array?
void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
//void test(int&);

int main()
{
	int array1[] = { 8, 1, 6 };
	int array2[] = { 3, 5, 7 };
	int array3[] = { 4, 9, 2 };

	/* Define a Lo Shu Magic Square using 3 parallel arrays corresponding to each row of the grid */
	//int magicArrayRow1[COLS], magicArrayRow2[COLS], magicArrayRow3[COLS];

	fillArray(array1, array2, array3, 3);
	cout << checkRange(array1, array2, array3, 3, MIN, MAX) << endl;
	cout << checkUnique(array1, array2, array3, 3) << endl;
	cout << checkRowSum(array1, array2, array3, 3) << endl;
	cout << checkColSum(array1, array2, array3, 3) << endl;
	cout << checkDiagSum(array1, array2, array3, 3) << endl;

	// Your code goes here
	system("pause");
	return 0;
}
// Function definitions go here
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
	bool unique = true;

	//check if each element in the individual array is unique
	//iterates over an array
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arrayRow1[i] == arrayRow1[j])
			{
				cout << arrayRow1[i] << " " << arrayRow1[j] << endl;
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
				cout << arrayRow2[i] << " " << arrayRow2[j] << endl;
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
				cout << arrayRow3[i] << " " << arrayRow3[j] << endl;
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
				//looking for more elegant way to compare each array to each other
				if (arrayRow1[j] == arrayRow2[k] || arrayRow1[j] == arrayRow3[l] || arrayRow2[k] == arrayRow3[l])
				{
					cout << arrayRow1[j] << " " << arrayRow2[k] << " " << arrayRow3[l] << endl;
					cout << "non unique value found" << endl;
					return false;

				}
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
		return false;
	}
}

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
		return false;
	}
}

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
		return false;
	}
}

void fillArray(int (&arrayRow1)[3], int (&arrayRow2)[3], int (&arrayRow3)[3], int size)
{
	int i = 0, j = 0, k = 0;
	while (i < size)
	{
		cout << "Enter the number for row 1 and column " << i << ":";
		cin >> arrayRow1[i];
		i++;
	}

	while (j < size)
	{
		cout << "Enter the number for row 2 and column " << j << ":";
		cin >> arrayRow2[j];
		j++;
	}

	while (k < size)
	{
		cout << "Enter the number for row 3 and column " << k << ":";
		cin >> arrayRow2[k];
		k++;
	}
}

bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max)
{

	//iterates over an array
	for (int i = 0; i < size; i++)
	{
		//checks if the element of the array is less than the min or greater than the max
		if (arrayRow1[i] < min || arrayRow1[i] > max || arrayRow2[i] < min || arrayRow2[i] > max || arrayRow3[i] < min || arrayRow3[i] > max)
		{
			return false;
		}
	}
	return true;
}

void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arrayrow1[i] << " ";
	}

	for (int i = 0; i < size; i++)
	{
		cout << arrayrow2[i] << " ";
	}

	for (int i = 0; i < size; i++)
	{
		cout << arrayrow3[i] << " ";
	}
}

//void test(int& foobar)
//{
//	cout << "This is the test\n" << "enter a number: ";
//	cin >> foobar;
//}
