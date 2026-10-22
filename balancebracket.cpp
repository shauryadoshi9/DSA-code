#include <iostream>
#include <stack>
#include <string>
using namespace std;

string isBalanced(string s) {
    stack<char> st;

    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else {
            if (st.empty())
                return "NO";

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
    string s;
    cin >> s;           // Take only one input
    cout << isBalanced(s);

    return 0;           // Program terminates automatically
}