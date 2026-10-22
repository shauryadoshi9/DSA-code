/*
================================================================================
EXPERIMENT - 2
Aim: Implement the Application of Stack Infix to Postfix.
Tools / Apparatus: O.S.: Microsoft Windows (any) / Linux / DOS
Packages: Turbo/Borland/GNU - C/C++

Procedure: 
POLISH(Q, P)
Suppose Q is an arithmetic expression written in infix notation. This algorithm
finds the equivalent postfix expression P.
1) Push "(" onto STACK, and add ")" to the end of Q
2) Scan Q from left to right and repeat steps 3 to 6 for each element of Q until
   the stack is empty:
3) If an operand is encountered, add it to P.
4) If a left parenthesis is encountered, push it onto the stack.
5) If an operator is encountered, then:
   (a) Repeatedly pop from STACK and add to P each operator (on top of the STACK)
       which has same precedence as or higher precedence than the operator encountered.
   (b) Add the encountered operator to the stack.
   [End of IF structure]
6) If a right parenthesis is encountered, then:
   (a) Repeatedly pop from the stack and add to P each operator (on top of the STACK)
       until a left parenthesis is encountered.
   (b) Remove the left parenthesis [do not add left parenthesis to P].
   [End of IF structure]
   [End of step 2 loop]
7) Exit.
================================================================================
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Stack implementation using dynamically allocated array
class Stack {
private:
    char *arr;
    int top;
    int capacity;

public:
    Stack(int cap = 100) {
        capacity = cap;
        arr = new char[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void push(char c) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = c;
    }

    char pop() {
        if (isEmpty()) {
            return '\0';
        }
        return arr[top--];
    }

    char peek() {
        if (isEmpty()) {
            return '\0';
        }
        return arr[top];
    }
};

// Function to return precedence of operators
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0; // For '(' or other characters
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%');
}

// Implementation of POLISH(Q, P) algorithm from the lab manual
string infixToPostfix(string Q) {
    Stack st(Q.length() + 50);
    string P = "";

    // Step 1: Push "(" onto STACK, and add ")" to the end of Q
    st.push('(');
    Q += ')';

    // Step 2: Scan Q from left to right until the stack is empty
    for (int i = 0; i < (int)Q.length(); i++) {
        char ch = Q[i];

        // Skip whitespace
        if (isspace(ch)) continue;

        // Step 3: If an operand is encountered, add it to P
        if (isalnum(ch)) {
            P += ch;
        }
        // Step 4: If a left parenthesis is encountered, push it onto stack
        else if (ch == '(') {
            st.push(ch);
        }
        // Step 5: If an operator is encountered
        else if (isOperator(ch)) {
            while (!st.isEmpty() && isOperator(st.peek())) {
                if (ch == '^' && precedence(st.peek()) < precedence(ch)) {
                    break;
                }
                if (precedence(st.peek()) >= precedence(ch)) {
                    P += st.pop();
                } else {
                    break;
                }
            }
            st.push(ch);
        }
        // Step 6: If a right parenthesis is encountered
        else if (ch == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                P += st.pop();
            }
            if (!st.isEmpty() && st.peek() == '(') {
                st.pop();
            }
        }
    }

    // Step 7: Exit and return result
    return P;
}

int main() {
    string infix;

    cout << "========================================\n";
    cout << "  INFIX TO POSTFIX CONVERSION (STACK)\n";
    cout << "========================================\n";

    cout << "Enter Infix Expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);

    cout << "\nGiven Infix Expression   : " << infix << "\n";
    cout << "Equivalent Postfix Form  : " << postfix << "\n";

    return 0;
}
