/*
================================================================================
EXPERIMENT - 8
Aim: Implement the Sorting using Quick Sort method.
Tools / Apparatus: O.S.: Microsoft Windows (any) / Linux / DOS
Packages: Turbo/Borland/GNU - C/C++

Procedure: 
The steps are:
1. Pick an element, called a pivot, from the list.
2. Reorder the list so that all elements with values less than the pivot come
   before the pivot, while all elements with values greater than the pivot come
   after it (equal values can go either way). After this partitioning, the pivot
   is in its final position. This is called the partition operation.
3. Recursively sort the sub-list of lesser elements and the sub-list of greater elements.

The base case of the recursion are lists of size zero or one, which never need to be sorted.
In simple pseudocode, the algorithm might be expressed as this:
function quicksort(array)
    var list less, greater
    if length(array) <= 1 
        return array 
    select and remove a pivot value pivot from array
    for each x in array
        if x <= pivot then append x to less
        else append x to greater
    return concatenate(quicksort(less), pivot, quicksort(greater))
================================================================================
*/

#include <iostream>
using namespace std;

// Helper function to swap two integers
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to print array elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

/*
Partition function:
Takes the last element as pivot, places the pivot element at its correct
sorted position in the array, and places all smaller elements to the left
of pivot and all greater elements to the right of pivot.
*/
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // 1. Pick pivot (last element)
    int i = (low - 1);     // Index of smaller element

    // 2. Reorder list around pivot
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1); // Pivot index
}

// QuickSort recursive function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // 3. Recursively sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;

    cout << "========================================\n";
    cout << "          QUICK SORT ALGORITHM\n";
    cout << "========================================\n";

    cout << "Enter number of elements to sort: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array size must be positive.\n";
        return 0;
    }

    // Dynamically allocate array based on runtime input
    int *arr = new int[n];

    cout << "Enter " << n << " integer elements:\n";
    for (int i = 0; i < n; i++) {
        cout << "  Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "\nOriginal Array: \n";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "\nSorted Array (Ascending Order): \n";
    printArray(arr, n);

    delete[] arr;

    return 0;
}
