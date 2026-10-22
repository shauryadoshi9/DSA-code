/*
================================================================================
QUESTION: Next Greater Element 70
Platform: HackerRank
Difficulty: Medium

Problem Statement:
Given an array of integers, find the Next Greater Element (NGE) for every
element in the array.
The Next Greater Element for an element x is the first greater element on the
right side of x in the array. If no greater element exists to the right of x,
consider the next greater element as -1.

Algorithm (Monotonic Stack - O(N) Time Complexity):
1. Initialize an array/vector nge of size n with -1.
2. Traverse the array from right to left (i = n - 1 down to 0).
3. While the stack is not empty and stack.top() <= arr[i], pop from stack.
4. If stack is not empty, nge[i] = stack.top().
5. Push arr[i] onto the stack.
6. Return the nge array.

Input Format:
- The first line contains an integer n, the number of elements in the array.
- The second line contains n space-separated integers.

Output Format:
- Print n space-separated integers representing the Next Greater Element for
  each element.
================================================================================
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(const vector<int>& arr) {
    int n = arr.size();
    vector<int> nge(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            nge[i] = st.top();
        }

        st.push(arr[i]);
    }

    return nge;
}

int main() {
    int n;
    cout << "========================================\n";
    cout << "        NEXT GREATER ELEMENT 70\n";
    cout << "========================================\n";

    cout << "Enter number of elements in array: ";
    if (!(cin >> n) || n <= 0) {
        return 0;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = nextGreaterElement(arr);

    cout << "\nElement -> Next Greater Element:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " -> " << result[i] << "\n";
    }

    cout << "\nOutput Array Format:\n";
    for (int i = 0; i < n; i++) {
        cout << result[i] << (i < n - 1 ? " " : "\n");
    }

    return 0;
}
