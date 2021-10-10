#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include "../mergesort/mergesort.c"

int *removeDuplicates(int *arr, int size) {
    int index = 0;
    int j = 1;
    int len, n;
    int *subarray, *result;
    subarray = (int *) calloc(size, sizeof(int));
    subarray[0] = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] != subarray[j - 1]) {
            subarray[j++] = arr[i];
            index++;
        }
    }
    len = index + 2;
    n = index + 1;
    result = (int *) calloc(len, sizeof(int));
    result[0] = n;
    for (int i = 1; i < len; i++) {
        result[i] = subarray[i - 1];
    }
    free(subarray);
    return result;
}

int* array_merge(int num_arrays, int* sizes, int** values) {

    int i, j, y;
    int finalSize = 0;
    int *uniqueArray;

    //Iterate through the sizes[] to find the approximate final array size
    //(will not be exact because this does not account for unique integers)
    for (y  = 0; y < num_arrays; y++){
        finalSize += sizes[y];
        // printf("Current total size = %d\n", finalSize);
    }

    //Create our result array using the finalSize integer obtained above
    int *result = (int*) calloc(finalSize + 1, sizeof(int));

    //Handle empty lists
    if(num_arrays == 0) {
        int* emptyArrays = (int*) calloc(1, sizeof(int));
        //Since the first value in the returned array is always the size,
        //return an array with `0` in it denoting there is nothing in it
        emptyArrays[0] = 0;
        return emptyArrays;
    }

    //Use the num_arrays variable and the sizes[] to iterate through values[]
    //and add each integer in values to our result array
    int posInArray = 0;
    for (i  = 0; i < num_arrays; i++){
        int *current = values[i];
        for (j = 0; j < sizes[i]; j++) {
            result[posInArray] = current[j];
            posInArray++;
        }
    }

    mergesort(finalSize, result);
    //Get an array of just the unique values
    uniqueArray = removeDuplicates(result, finalSize);
    //Free the now unused result array
    free(result);

    return uniqueArray;
}