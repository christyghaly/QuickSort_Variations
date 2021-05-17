/* C++ implementation of QuickSort */
#include <iostream>
#include "QuickSort.h"
using namespace std;


void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
/* This function takes first element as pivot*/
int partition(int arr[], int low, int high)
{
	int pivot = arr[low]; // pivot
	int i = (low + 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low+1; j <= high ; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			
			swap(&arr[i], &arr[j]);
			i++; 
		}
	}
	swap(&arr[i - 1], &arr[low]);
	return (i - 1);
}


void quickSort(int arr[], int low, int high)
{
	if (high <= low)
		return;
	
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	
}
int medianof3(int arr[], int low, int med, int high) {
	if ((arr[low] <= arr[med] && arr[low] >= arr[high])|| (arr[low] >= arr[med] && arr[low] <= arr[high]))
		return low;
	else if ((arr[med] >= arr[low] && arr[med] <= arr[high])|| (arr[med] <= arr[low] && arr[med] >= arr[high]))
		return med;
	else if ((arr[high] <= arr[low] && arr[high] >= arr[med])|| (arr[high] >= arr[low] && arr[high] <= arr[med]))
		return high;
}
void quickSortMedian(int arr[], int low, int high) {
	if (high <= low)
		return;
	int m = medianof3(arr, low, low + (high - low) / 2, high);
	cout << "median is: " << arr[m] << endl;
	swap(&arr[m], &arr[low]);
	int pi = partition(arr, low, high);

	// Separately sort elements before
	// partition and after partition
	quickSortMedian(arr, low, pi - 1);
	quickSortMedian(arr, pi + 1, high);
}
/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver Code
int main()
{
	//Simple Case
	/*int arr[] = { 70,80,30,90,40,50,10};
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	*/

	//Median of Three
	int arr2[] = { 70,60,50,40,30,20,10 };// worst case
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	quickSortMedian(arr2, 0, n2 - 1);
	printArray(arr2, n2);



	//Insertion Sort
	int arr3[] = { 4,3,2,10,12,1,5,6 };
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	insertionSort(arr3, n3);
	cout << "Sorted array: \n";
	printArray(arr3, n3);
	return 0;
}



