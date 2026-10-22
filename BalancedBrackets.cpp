/*
================================================================================
QUESTION: Balanced Brackets
Platform: HackerRank (Data Structures -> Stacks)
Difficulty: Medium

Problem Statement:
A bracket is considered to be any one of the following characters: '(', ')',
'{', '}', '[', or ']'.
A sequence of brackets is considered to be balanced if:
1. It contains no unmatched brackets.
2. The subset of brackets enclosed within the confines of a matched pair of
   brackets is also a matched pair of brackets.

Given n strings of brackets, determine whether each sequence of brackets is
balanced. If a string is balanced, return "YES". Otherwise, return "NO".

Input Format:
- The first line contains a single integer n, the number of strings.
- Each of the next n lines contains a single string s, a sequence of brackets.

Output Format:
- For each string, print "YES" or "NO" on a new line.
================================================================================
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

string isBalanced(string s) {
    stack<char> st;

    for (int i = 0; i < (int)s.length(); i++) {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else {
            if (st.empty()) {
                return "NO";
            }

            char top = st.top();
            st.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return "NO";
            }
        }
    }

    return st.empty() ? "YES" : "NO";
}

int main() {
    int t;
    cout << "========================================\n";
    cout << "           BALANCED BRACKETS\n";
    cout << "========================================\n";

    cout << "Enter number of test strings: ";
    if (!(cin >> t) || t <= 0) {
        return 0;
    }

    for (int i = 0; i < t; i++) {
        string s;
        cout << "Enter bracket string " << i + 1 << ": ";
        cin >> s;
        cout << "Result: " << isBalanced(s) << "\n";
    }

    return 0;
}
