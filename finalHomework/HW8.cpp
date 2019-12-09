#include <iostream>
using namespace std;

//function prototypes
void displayArray(int array[], int size); //Displays the content of the array
void selectionSort(int array[], int size); //sorts the array using the selection sort algorithm in descending order
int findMax(int array[], int size); //finds and returns the highest element of the array
int findMin(int array[], int size); //finds and returns the lowest element of the array
double findAvg(int array[], int size); //finds and returns the average of the elements of the array
void swap(int &a, int &b);

int main() {

	int userSize,
		score;
	

	cout << "How many test scores do you have? ";
	cin >> userSize;
	
	//vector declaration, array without predetermined bounds because we don't know how many test scores there will be
	int *testArr = new int[userSize];
	for (int i = 0; i < userSize; i++)
	{
		cout << "Test score #" << i + 1 << ":";
		cin >> score;
		testArr[i] = score;
	}

	//call the functions and store them in their variable
	int findMaxV = findMax(testArr, userSize);
	int findMinV = findMin(testArr, userSize);
	double findAvgV = findAvg(testArr, userSize);


	cout << "Original ordered scores are: "; displayArray(testArr, userSize);
	selectionSort(testArr, userSize);
	cout << "Scores ordered high to low: "; displayArray(testArr, userSize);
	cout << "Highest score: " << findMaxV << endl; //findMax(testArr, userSize);
	cout << "Lowest score: " << findMinV << endl; //findMin(testArr, userSize);
	cout << "Average score: " << findAvgV << endl; //findAvg(testArr, userSize);

  system("pause");
  return 0;
}

/////////////////////////////////////////////////
//function to display array
/////////////////////////////////////////////////
void displayArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//function that combined with the swap function performs an insertion sort algorithm
///////////////////////////////////////////////////////////////////////////////////////////////
void selectionSort(int array[], int size)
{
	int maxIndex, maxValue;
	  
	for (int start = 0; start < (size - 1); start++)
	{
		maxIndex = start;
		maxValue = array[start];
		for (int index = start + 1; index < size; index++)
		{
			if (array[index] > maxValue)
			{
				maxValue = array[index];
				maxIndex = index;
			}
		}
		swap(array[maxIndex], array[start]);
	}
}

void swap(int &a, int &b)
{
	// Define variables and store temporary value in temp.
	int temp = a;
	a = b;
	b = temp;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//finds the largest element in an array
///////////////////////////////////////////////////////////////////////////////////////////////
int findMax(int array[], int size)
{
	int maxValue = array[0];

	for (int i = 0; i < size; i++)
	{
		
		if (array[i] > maxValue)
		{
			maxValue = array[i];
		}
	}

	return maxValue;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//finds the smallest element in an array
///////////////////////////////////////////////////////////////////////////////////////////////
int findMin(int array[], int size)
{
	int minValue = array[0];

	for (int i = 0; i < size; i++)
	{
		if (array[i] < minValue)
		{
			minValue = array[i];
		}
	}

	return minValue;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//finds the average of an array
///////////////////////////////////////////////////////////////////////////////////////////////
double findAvg(int array[], int size)
{
	double avg = 0, total = 0;

	for (int i = 0; i < size; i++)
	{
		total += array[i];
	}
	avg = total / size;

	return avg;
}