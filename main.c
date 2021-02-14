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
    double time_used;
   
    //void (*fun_ptr)(int*, int) = &fun; 
    //(*fun_ptr)(10); 
    int (*fun_ptr_arr[])(int*, int) = {
        &selectionSort,
        &bubbleSort,
        &quickSort_helper,
        &mergeSort_helper
    };

    int sizes[] = {100, 150, 200, 1000};
    //int sizes[] = {100000, 150000, 200000, 1000000};

    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            int n = sizes[j];
            int* arr = (int*) malloc(n * sizeof(int)); 
            
            for (int k=0; k<n; k++) {
                // RAND_MAX is aroudn 32767
                arr[k] = rand();
            }
            start = clock();
            
            int comparisions = (*fun_ptr_arr[i])(arr, n);

            end = clock();
            time_used = ((double) (end - start));
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

            printf("sort_fn[%d] (arr_size=%d) -> { time_used: %lf, cpu_time_used: %lf, comparisions: %d }\n", i, n, time_used, cpu_time_used, comparisions);
            //printf("Sorted array: \n"); 
            //printArray(arr, n); 
            //free(arr);
        }
    }
}
