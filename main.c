#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
#include <string.h>
#include <time.h>
#include "helper.h"

/* Function to print an array */
void printArray(__uint128_t arr[], __uint128_t size) 
{ 
    __uint128_t i; 
    char buf[64];
    for (i=0; i < size; i++) { 
	itoa128(buf, arr[i], 10);
        printf("%s ", buf);
    }
    printf("\n"); 
}

void main() {
    clock_t start, end;
    double cpu_time_used;
    double time_used;
   
    //void (*fun_ptr)(__uint128_t*, __uint128_t) = &fun; 
    //(*fun_ptr)(10); 
    __uint128_t (*fun_ptr_arr[])(__uint128_t*, __uint128_t) = {
        &selectionSort,
        &bubbleSort,
        &quickSort_helper,
        &mergeSort_helper
    };

    //__uint128_t sizes[] = {100, 150, 200, 1000};
    int sizes[] = {100000, 150000, 200000, 1000000};

    char comps_str[64] = {'\0'};

    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            int n = sizes[j];
            __uint128_t* arr = (__uint128_t*) malloc(n * sizeof(__uint128_t)); 
            
            for (__uint128_t k=0; k<n; k++) {
                // RAND_MAX is aroudn 32767
                arr[k] = rand();
            }
            start = clock();
            
            __uint128_t comparisions = (*fun_ptr_arr[i])(arr, n);

	    itoa128(comps_str, comparisions, 10);

            end = clock();
            time_used = ((double) (end - start));
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

            printf("sort_fn[%d] (arr_size=%d) -> { time_used: %lf, cpu_time_used: %lf, comparisions: %s }\n", i, n, time_used, cpu_time_used, comps_str);
            //printf("Sorted array: \n"); 
            //printArray(arr, n); 
            //free(arr);
        }
    }
}
