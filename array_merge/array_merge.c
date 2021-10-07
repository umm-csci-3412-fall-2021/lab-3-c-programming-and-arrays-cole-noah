#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include "../mergesort/mergesort.c"

int *removeDuplicates(int *arr, int size) {
    int i, j, k;
    //For each element in the array...
    for (i = 0; i < size; i++){
        //Compare it to every other element in the array...
        for (j = i + 1; j < size; j++){
            //And if its the same, delete it and move every element in the array back one
            //(to the element before it), alse decrease the size, and since the array is shorter
            //don't increment j
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
    

    return result;
}

int main() {
    int num_arrays = 3;
    int sizes[] = { 4, 2, 5 };
    int a0[] = { 3, 2, 0, 5 };
    int a1[] = { 8, 9 };
    int a2[] = { 6, 3, 2, 0, 5 };
    int* values[] = { a0, a1, a2 };
    int* resultArray;

    int removeDuplicatesTest[] = { 1, 1, 2, 2, 3, 3, 4, 4};
    int removeDuplicatesTest1[] = { 2, 1, 2, 4, 3, 3, 3, 4};
    int size = 8;

    //   resultArray = array_merge(num_arrays, sizes, values);
    //   printArray(resultArray, 11);

    resultArray = removeDuplicates(removeDuplicatesTest, size);
    printArray(resultArray, 8);

    return 0;
}
