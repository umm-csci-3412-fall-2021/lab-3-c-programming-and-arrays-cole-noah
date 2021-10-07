#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include "../mergesort/mergesort.c"

int* array_merge(int num_arrays, int* sizes, int** values) {

    int i, j, y;
    int finalSize = 0;

    //Iterate through the sizes[] to find the approximate final array size
    //(will not be exact because this does not account for unique integers)
    for (y  = 0; y < num_arrays; y++){
        finalSize += sizes[y];
        // printf("Current total size = %d\n", finalSize);
    }

    //Create our result array using the finalSize integer obtained above
    int *result = (int*) calloc(finalSize, sizeof(int));

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

    uniqueArray = removeDuplicates(result, finalSize);
    free(result);
    mergesort(uniqueArray);
    return result;
}

int *removeDuplicates(int *arr, int size) {
    int i, j, k;
    for (i = 0; i < size; i++){
        for (j = i + 1; j < size; j++){
            if (arr[i] == arr[j]) {
                for (k = j; k < size - 1; k++){
                    arr[k] = arr[k+1];
                }
                size--;
                j--;
            }
        }
    }
    return arr;
}

int main() {
  int num_arrays = 3;
  int sizes[] = { 4, 2, 5 };
  int a0[] = { 3, 2, 0, 5 };
  int a1[] = { 8, 9 };
  int a2[] = { 6, 3, 2, 0, 5 };
  int* values[] = { a0, a1, a2 };
  int* resultArray;

  resultArray = array_merge(num_arrays, sizes, values);
  printArray(resultArray, 11);

  return 0;
}
