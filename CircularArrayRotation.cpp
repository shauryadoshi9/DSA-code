/*
================================================================================
QUESTION: Circular Array Rotation
Platform: HackerRank (Algorithms -> Implementation)
Difficulty: Easy

Problem Statement:
John Watson performs a right circular rotation operation on an array of integers.
One rotation moves the last element to the first position and shifts all remaining
elements to the right.
Given an array 'a' of n integers, the number of rotations 'k', and an array of
query indices 'queries', return the value of the element at each query index
after k right circular rotations.

Formula:
After k rotations on an array of size n, the element at index q in the rotated
array was originally located at index:
    originalIndex = (q - (k % n) + n) % n

Input Format:
- The first line contains 3 space-separated integers:
    - n: the number of elements in the integer array
    - k: the rotation count
    - q: the number of queries
- The second line contains n space-separated integers, where each element is a[i].
- Each of the next q lines contains a single integer, queries[i], an index of an
  element to return.

Output Format:
- For each query, print the value of the element at that index on a new line.
================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {
    int n = a.size();
    k = k % n;

    vector<int> result;
    for (int i = 0; i < (int)queries.size(); i++) {
        int q = queries[i];
        int originalIndex = (q - k + n) % n;
        result.push_back(a[originalIndex]);
    }

    return result;
}

int main() {
    int n, k, q;
    cout << "========================================\n";
    cout << "        CIRCULAR ARRAY ROTATION\n";
    cout << "========================================\n";

    cout << "Enter array size (n), rotation count (k), and number of queries (q): ";
    if (!(cin >> n >> k >> q) || n <= 0) {
        return 0;
    }

    vector<int> a(n);
    cout << "Enter " << n << " array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> queries(q);
    cout << "Enter " << q << " query indices (0 to " << n - 1 << "):\n";
    for (int i = 0; i < q; i++) {
        cin >> queries[i];
    }

    vector<int> results = circularArrayRotation(a, k, queries);

    cout << "\n---------------- QUERY RESULTS ----------------\n";
    for (int i = 0; i < (int)results.size(); i++) {
        cout << "Query " << i + 1 << " (Index " << queries[i] << "): " << results[i] << "\n";
    }

    return 0;
}
