void swap(int *xp, int *yp);

__uint128_t selectionSort(int arr[], int n);

// A function to implement bubble sort 
__uint128_t bubbleSort(int arr[], int n);


/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
__uint128_t partition (int arr[], int low, int high);

/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
__uint128_t quickSort(int arr[], int low, int high);

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r);
 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
__uint128_t mergeSort(int arr[], int l, int r);

__uint128_t quickSort_helper(int arr[], int n); 
__uint128_t mergeSort_helper(int arr[], int n); 
