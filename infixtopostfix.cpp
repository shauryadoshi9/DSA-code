/*
Question:
Write a program to convert a valid infix expression into its postfix form
using a stack. The expression may contain multi-digit operands,
parentheses and unary minus (-) operator.
Additionally, evaluate the resulting postfix expression assuming
all operands are integers.
*/

#include<iostream>
#include<stack>
#include<string>
#include<sstream>
#include<cctype>

using namespace std;

int pres(char ch)
{
    if(ch=='^')
        return 3;
    else if(ch=='*' || ch=='/' || ch=='%')
        return 2;
    else if(ch=='+' || ch=='-') 
        return 1;
    else
        return 0;
}

bool rightAsso(char ch)
{
    return (ch=='^');
}

string convert(string s)
{
    stack<char> c;
    string postfix="";

    for(int i=0;i<s.size();i++)
    {
        char ch=s[i];

        if(isspace(ch))
            continue;

        // Multi-digit number
        if(isdigit(ch))
        {
            while(i<s.size() && isdigit(s[i]))
            {
                postfix+=s[i];
                i++;
            }

            postfix+=" ";
            i--;
        }

        else if(ch=='(')
        {
            c.push(ch);
        }

        else if(ch==')')
        {
            while(!c.empty() && c.top()!='(')
            {
                postfix+=c.top();
                postfix+=" ";
                c.pop();
            }

            if(!c.empty())
                c.pop();
        }

        else
        {
            while(!c.empty() && c.top()!='(' &&
                  (pres(c.top())>pres(ch) ||
                  (pres(c.top())==pres(ch) && !rightAsso(ch))))
            {
                postfix+=c.top();
                postfix+=" ";
                c.pop();
            }

            c.push(ch);
        }
    }

    while(!c.empty())
    {
        postfix+=c.top();
        postfix+=" ";
        c.pop();
    }

    return postfix;
}

int evaluate(string postfix)
{
    stack<int> st;
    stringstream ss(postfix);
    string token;

    while(ss>>token)
    {
        if(isdigit(token[0]))
        {
            st.push(stoi(token));
        }
        else
        {
            int b=st.top();
            st.pop();

            int a=st.top();
            st.pop();

            switch(token[0])
            {
                case '+':
                    st.push(a+b);
                    break;

                case '-':
                    st.push(a-b);
                    break;

                case '*':
                    st.push(a*b);
                    break;

                case '/':
                    st.push(a/b);
                    break;

                case '%':
                    st.push(a%b);
                    break;
            }
        }
    }

    return st.top();
}

int main()
{
    string s;

    cout<<"Enter an infix expression:"<<endl;

    getline(cin,s);

    string postfix=convert(s);

    cout<<"\nPostfix Expression : "<<postfix<<endl;

    cout<<"Result = "<<evaluate(postfix);

    return 0;
}