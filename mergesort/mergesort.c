#include "mergesort.h"
#include <stdio.h>
#include <stdlib.h>

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void mergeRanges(int arr[], int startIndex, int midPoint, int endIndex)
{
	int i, j, k;
	int n1 = midPoint - startIndex + 1;
	int n2 = endIndex - midPoint;

	/* create temp arrays */
	int *start = (int*) calloc(n1, sizeof(int));
	int *end = (int*) calloc(n2, sizeof(int));

	/* Copy data to temp arrays L[] and R[] */
	
	for (i = 0; i < n1; i++)
		start[i] = arr[startIndex + i];
	for (j = 0; j < n2; j++)
		end[j] = arr[midPoint + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = startIndex; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (start[i] <= end[j]) {
			arr[k] = start[i];
			i++;
		}
		else {
			arr[k] = end[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1) {
		arr[k] = start[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2) {
		arr[k] = end[j];
		j++;
		k++;
	}

	free(start);
	free(end);

}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int givenArray[], int startIndex, int endIndex)
{
	if (startIndex < endIndex) {
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int midPoint = startIndex + (endIndex - startIndex) / 2;

		// Sort first and second halves
		mergeSort(givenArray, startIndex, midPoint);
		mergeSort(givenArray, midPoint + 1, endIndex);

		mergeRanges(givenArray, startIndex, midPoint, endIndex);
	}
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

/* Driver code */
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("Given array is \n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	return 0;
}
