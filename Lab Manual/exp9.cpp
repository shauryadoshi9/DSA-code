/*
================================================================================
EXPERIMENT - 9
Aim: Implement the Sorting using Merge Sort method.
Tools / Apparatus: O.S.: Microsoft Windows (any) / Linux / DOS
Packages: Turbo/Borland/GNU - C/C++

Procedure: 
Conceptually, a merge sort works as follows:
If the list is of length 0 or 1, then it is already sorted. Otherwise:
1) Divide the unsorted list into two sublists of about half the size.
2) Sort each sublist recursively by re-applying merge sort.
3) Merge the two sublists back into one sorted list.

Merge sort incorporates two main ideas to improve its runtime:
1. A small list will take fewer steps to sort than a large list.
2. Fewer steps are required to construct a sorted list from two sorted lists than
   two unsorted lists.

Example: Using merge sort to sort a list of integers contained in an array:
Suppose we have an array A with n indices ranging from A0 to An-1. We apply merge
sort to A(A0..Ac-1) and A(Ac..An-1) where c is the integer part of n / 2. When
the two halves are returned they will have been sorted. They can now be merged
together to form a sorted array.

Pseudocode:
function merge_sort(m)
    if length(m) <= 1
        return m
    var list left, right, result
    var integer middle = length(m) / 2
    for each x in m up to middle
        add x to left
    for each x in m after middle
        add x to right
    left = merge_sort(left)
    right = merge_sort(right)
    result = merge(left, right)
    return result
================================================================================
*/

#include <iostream>
using namespace std;

// Function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// Function to merge two sorted sublists arr[l..mid] and arr[mid+1..h]
void merge(int arr[], int l, int mid, int h) {
    int i = l;
    int j = mid + 1;
    int k = 0;
    int size = h - l + 1;
    int *temp = new int[size];

    // Traverse and merge both halves in sorted order
    while (i <= mid && j <= h) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements of left sublist
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements of right sublist
    while (j <= h) {
        temp[k++] = arr[j++];
    }

    // Copy merged elements back to original array
    for (int p = 0; p < size; p++) {
        arr[l + p] = temp[p];
    }

    delete[] temp;
}

// Function to implement merge sort recursively
void mergeSort(int arr[], int l, int h) {
    if (l < h) {
        // 1) Divide the unsorted list into two sublists of about half the size
        int mid = l + (h - l) / 2;

        // 2) Sort each sublist recursively
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);

        // 3) Merge the two sublists back into one sorted list
        merge(arr, l, mid, h);
    }
}

int main() {
    int n;

    cout << "========================================\n";
    cout << "          MERGE SORT ALGORITHM\n";
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

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted Array (Ascending Order): \n";
    printArray(arr, n);

    delete[] arr;

    return 0;
}
