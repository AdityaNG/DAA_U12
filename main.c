#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
#include <string.h>
#include <time.h>

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
}

void main() {
    clock_t start, end;
    double cpu_time_used;

    
    //void (*fun_ptr)(int*, int) = &fun; 
    //(*fun_ptr)(10); 
    void (*fun_ptr_arr[])(int*, int) = {
        &selectionSort,
        &bubbleSort,
        &quickSort_helper,
        &mergeSort_helper
    };

    //int sizes[] = {100, 150, 200, 1000};
    int sizes[] = {100000, 150000, 200000, 1000000};

    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            int n = sizes[j];
            int* arr = (int*) malloc(n * sizeof(int)); 
            
            for (int k=0; k<n; k++) {
                // RAND_MAX is aroudn 32767
                arr[k] = rand();
            }
            start = clock();
            
            (*fun_ptr_arr[i])(arr, n);

            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

            printf("sort_fn[%d] (arr_size=%d) -> %lf\n", i, n, cpu_time_used);
            //printf("Sorted array: \n"); 
            //printArray(arr, n); 
            free(arr);
        }
    }
}