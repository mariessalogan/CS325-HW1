/*Name: Mariessa Logan
Date: 1/13/19
Description: Insert sort time tracker.  Used https://www.programiz.com/cpp-programming/library-function/ctime/clock
to help with clocking the program.
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <cmath>
using namespace std;


void insertSort(int *array, int length) //This function will sort using insertion.
{
	int i;
	int current = 0; //This is going to be the value that we are sorting in the loop
	int j = 0;
	for (i = 0; i < length; i++)
	{
		current = array[i];
		j = i - 1; //We want j to equal the previous number so we can compare
		while (j >= 0 && current < array[j])//We want to only run this if current is not the first number in the array and it is less than the prev number
		{
			array[j + 1] = array[j]; //Make the number after j, the current j, so you can move the larger numbers to the right
			j--;
		}
		array[j + 1] = current; //put the current iteration in that spot
	}
}

int main()
{
	int n[10] = { 1000, 2500, 5000, 7500, 10000, 12500, 15000, 17500, 20000, 22500 };
	int arr[n[0]]; //This is the original array 
	
	srand(time(NULL));
	clock_t curTime;
	clock_t insertTime;

	for (int test = 0; test < 10; test++) {
		std::cout << "The array size is: " << n[test] << "\n";
		for (int i = 0; i < n[test]; i++)
		{
			
			arr[i] = rand() % 10001;
			//std::cout << arr[i] << "\n";
		}
		std::cout << "Values set \n";
		curTime = clock();//initialize current time
		std::cout << "Set Clock \n";
		insertSort(arr, n[test]);//Call the insert sort function on arr2
		std::cout << "ran insert sort \n";
		insertTime = clock() - curTime;
		std::cout << "Set Clock for insert \n";
		std::cout << "Your insert sort time was: " << (float)insertTime / CLOCKS_PER_SEC << ".\n";
	}
	return 0;
}
