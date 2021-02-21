#include "sorting.h"

__uint128_t comps = 0;

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

__uint128_t selectionSort(int arr[], int n) 
{
    comps = 0;
    int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++) {
	  comps++;
          if (arr[j] < arr[min_idx])  {
	     min_idx = j; 
	  }
	}
  
        // Swap the found minimum element with the first element 
        swap(&arr[min_idx], &arr[i]); 
    }

    return comps;
}  

// A function to implement bubble sort 
__uint128_t bubbleSort(int arr[], int n) 
{ 
   comps = 0;
   int i, j; 
   for (i = 0; i < n-1; i++) {
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++) {
	   comps++;
           if (arr[j] > arr[j+1]) {
              swap(&arr[j], &arr[j+1]); 
	   }
       }
   }

   return comps;
} 


/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
__uint128_t partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
__uint128_t quickSort(int arr[], int low, int high) 
{
    comps++;
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

__uint128_t quicksort(int number[25],int first,int last){
   int i, j, pivot, temp;
 
   comps++;
   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}


// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[],int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back __uint128_to arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
	comps++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
__uint128_t mergeSort(int arr[], int l, int r)
{
    //comps++;
    
    if (l < r) {
        // Same as (l+r)/2, but a__uint128_ts overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

__uint128_t quickSort_helper(int arr[], int n) {
    comps = 0;
    quicksort(arr, 0, n);
    //quickSort(arr, 0, n);
    return comps;
} 
__uint128_t mergeSort_helper(int arr[], int n) {
    comps = 0;
    mergeSort(arr, 0, n);
    return comps;
}
