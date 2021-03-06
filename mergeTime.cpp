#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <cmath>
using namespace std;

void merge(int *array, int left, int right, int mid)
{
	//We need to use some iterators so we keep the left, right, and mid variables the same
	int i = left;
	int	j = mid + 1;
	int	k = 0;
	int	temp[144];
	

	
	while (i <= mid && j <= right)// Merge the two parts into temp[].
	{
		if (array[i] < array[j])
		{
			temp[k] = array[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = array[j];
			k++;
			j++;
		}
	}

	
	while (i <= mid)// Insert all the remaining values from i to mid into temp[].
	{
		temp[k] = array[i];
		k++;
		i++;
	}

	
	while (j <= right)// Insert all the remaining values from j to right into temp[].
	{
		temp[k] = array[j];
		k++;
		j++;
	}


	
	for (i = left; i <= right; i++)// Assign sorted data stored in temp[] to a[].
	{
		array[i] = temp[i - left];
	}
}
void mergeSort(int *array, int left, int right)//This function is to halve the array and call itself recursively until you get to 1 data point
{
	int mid = 0;//Keep track of the middle of each halving
	if (left < right)
	{
		mid = (left + right) / 2;
		// Split the data into two half.
		mergeSort(array, left, mid);
		mergeSort(array, mid + 1, right);

		// Merge them to get sorted output.
		merge(array, left, right, mid);
	}
}



int main()
{
	int n[10] = { 1000, 2500, 5000, 7500, 10000, 12500, 15000, 17500, 20000, 22500 };
	int arr[n[0]]; //This is the original array
	int arr1[n[0]]; //Here is the array that will be sorted by merge.  
	
	srand(time(NULL));
	clock_t curTime;
	clock_t mergeTime;
	
	for (int test = 0; test < 10; test++) {

		std::cout << "The array size is: " << n[test] << "\n";
		for (int i = 0; i < n[test]; i++)
		{
			arr[i] = rand() % 10001;
			//std::cout << arr[i] << "\n";
			arr1[i] = arr[i];

		}

		curTime = clock();//initialize current time
		//merge sort
		mergeSort(arr1, 0, n[test] - 1);//Calll the merge sort function on the arr1
		mergeTime = clock() - curTime;
		/*std::cout << "Merge sort sorted your array to: \n";
		for (int i = 0; i < n; i++)
		{
			cout << arr1[i] << "\n";
		}*/
		std::cout << "Your merge sort time was: " << (float)mergeTime << ".\n";

	}
	return 0;
}
