void swap(__uint128_t *xp, __uint128_t *yp);

__uint128_t selectionSort(__uint128_t arr[], __uint128_t n);

// A function to implement bubble sort 
__uint128_t bubbleSort(__uint128_t arr[], __uint128_t n);


/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
__uint128_t partition (__uint128_t arr[], __uint128_t low, __uint128_t high);

/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
__uint128_t quickSort(__uint128_t arr[], __uint128_t low, __uint128_t high);

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(__uint128_t arr[], __uint128_t l, __uint128_t m, __uint128_t r);
 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
__uint128_t mergeSort(__uint128_t arr[], __uint128_t l, __uint128_t r);

__uint128_t quickSort_helper(__uint128_t arr[], __uint128_t n); 
__uint128_t mergeSort_helper(__uint128_t arr[], __uint128_t n); 
