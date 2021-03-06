#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
#include <string.h>
#include <time.h>
#include "helper.h"

void main() {
    clock_t start, end;
    double cpu_time_used;
    double time_used;
    char comps_str[64];
  
    // A list of pointers to the sort functions
    __uint128_t (*fun_ptr_arr[])(int*, int) = {
        //&selectionSort,
	//&bubbleSort,
        &quickSort_helper,
        //&mergeSort_helper
    };

    int func_size = sizeof(fun_ptr_arr) / sizeof(fun_ptr_arr[0]);

    // Sorting sample sizes
    //int sizes[] = {100, 150, 200, 1000};
    //int sizes[] = {100000, 150000, 200000, 1000000};
    //int sizes[] = {100, 150, 200, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000};
    int sizes[] = {5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000};
    int sizes_size = sizeof(sizes) / sizeof(sizes[0]);
    int* arr = (int*) malloc(sizeof(int) * 1);
    for (int i=0; i<func_size; i++) {  		// i - iterates through the function pointers
        for (int j=0; j<sizes_size; j++) { 	// j - iterates through the sizes
            int n = sizes[j];
            arr = (int*) malloc(n * sizeof(int)); 
            //arr = realloc(arr, n*sizeof(int));
	    if (arr == NULL) {
	    	printf("Error\n");
		exit(1);
	    }
            for (int k=0; k<n; k++) { // Generate the set of random numbers
                // RAND_MAX is aroudn 32767
                arr[k] = rand();
            }

            start = clock();	// Start timing 
            
            __uint128_t comparisions = (*fun_ptr_arr[i])(arr, n);

	    end = clock();	// End timing

	    itoa128(comps_str, comparisions, 10);

            time_used = ((double) (end - start));
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	    
	    printf("%s\n", comps_str);
	    //printf("%f\n", cpu_time_used);

            //printf("sort_fn[%d] (arr_size=%d) -> { time_used: %lf, cpu_time_used: %lf, comparisions: %s }\n", i, n, time_used, cpu_time_used, comps_str);
            //printf("Sorted array: \n"); 
            //printArray(arr, n); 
            //free(arr);
        }
	printf("\n");
    }
    free(arr);
}
