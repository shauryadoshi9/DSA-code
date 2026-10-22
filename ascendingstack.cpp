/*
Question:
Write a C++ function to sort a stack in ascending order
using only recursion and standard stack operations
(push(), pop(), top(), empty()).
*/

#include<iostream>
#include<stack>

using namespace std;

// Insert element in sorted order
void sortedInsert(stack<int> &st,int x)
{
    if(st.empty() || st.top()<=x)
    {
        st.push(x);
        return;
    }

    int temp=st.top();
    st.pop();

    sortedInsert(st,x);

    st.push(temp);
}

// Sort Stack
void sortStack(stack<int> &st)
{
    if(st.empty())
        return;

    int temp=st.top();
    st.pop();

    sortStack(st);

    sortedInsert(st,temp);
}

int main()
{
    stack<int> st;

    st.push(30);
    st.push(10);
    st.push(50);
    st.push(20);
    st.push(40);

    sortStack(st);

    cout<<"Sorted Stack (Top to Bottom)\n";

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}