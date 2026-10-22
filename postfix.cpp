#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to return precedence of operators
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to convert Infix to Postfix
string infixToPostfix(string s) {
    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // If operand, add to result
        if ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9')) {
            res += c;
        }

        // If opening bracket, push to stack
        else if (c == '(') {
            st.push(c);
        }

        // If closing bracket, pop until '('
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop(); // Remove '('
        }

        // Operator
        else {
            while (!st.empty() && prec(c) <= prec(st.top())) {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    return res;
}

int main() {
    string exp;

    cout << "Enter Infix Expression: ";
    cin >> exp;

    cout << "Postfix Expression: " << infixToPostfix(exp);

    return 0;
}