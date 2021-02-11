#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
#include <string.h>

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
}

void main() {
    int arr[] = {64, 25, 12, 22, 11}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    
    selectionSort(arr, n); 
    bubbleSort(arr, n); 
    quickSort(arr, 0, n); 
    mergeSort(arr, 0, n); 

    printf("Sorted array: \n"); 
    printArray(arr, n); 
    
}