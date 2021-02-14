void swap(int *xp, int *yp);

int selectionSort(int arr[], int n);

// A function to implement bubble sort 
int bubbleSort(int arr[], int n);


/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition (int arr[], int low, int high);

/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
int quickSort(int arr[], int low, int high);

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r);
 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
int mergeSort(int arr[], int l, int r);

int quickSort_helper(int arr[], int n); 
int mergeSort_helper(int arr[], int n); 
