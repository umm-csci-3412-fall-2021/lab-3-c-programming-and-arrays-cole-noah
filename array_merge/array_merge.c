#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include "../mergesort/mergesort.c"

int* array_merge(int num_arrays, int* sizes, int** values) {

  int i, j, y;
  int finalSize = 0;

  //Iterate through the sizes[] to find the approximate final array size
  //(will not be exact because this does not account for unique integers)
  for (y  = 0; y < num_arrays; y++){
    finalSize =+ sizes[y];
  }

  //Create our result array using the finalSize integer obtained above
  int *result = (int*) calloc(finalSize, sizeof(int));

  //Use the num_arrays variable and the sizes[] to iterate through values[]
  //and add each integer in values to our result array
  for (i  = 0; i < num_arrays - 1; i++){
    for (j = 0; j < sizes[i] - 1; j++) {
      result[j] = values[i][j];
    }
  }
  


  return sizes;
}

int main() {
  int num_arrays = 3;
  int sizes[] = { 4, 2, 5 };
  int values[] = { { 3, 2, 0, 5 }, { 8, 9 }, { 6, 3, 2, 0, 5 } };

  array_merge(num_arrays, sizes, values);

  return 0;
}
