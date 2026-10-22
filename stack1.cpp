/*
Question:
Implement a stack with all the following operations in O(1) time:
push(x), top(), pop() and getMin() which returns the minimum element
currently in the stack. You are allowed to use extra space, such as an
auxiliary stack, to implement this functionality.
*/

#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
    stack<int> s;
    stack<int> minStack;

public:

    void push(int x)
    {
        s.push(x);

        if(minStack.empty() || x <= minStack.top())
            minStack.push(x);
    }

    void pop()
    {
        if(s.empty())
        {
            cout << "Stack Underflow\n";
            return;
        }

        if(s.top() == minStack.top())
            minStack.pop();

        s.pop();
    }

    int top()
    {
        if(s.empty())
            return -1;

        return s.top();
    }

    int getMin()
    {
        if(minStack.empty())
            return -1;

        return minStack.top();
    }
};

int main()
{
    MinStack st;

    st.push(10);
    st.push(20);
    st.push(5);
    st.push(8);

    cout << "Top Element : " << st.top() << endl;
    cout << "Minimum Element : " << st.getMin() << endl;

    st.pop();

    cout << "After Pop\n";
    cout << "Top Element : " << st.top() << endl;
    cout << "Minimum Element : " << st.getMin() << endl;

    return 0;
}