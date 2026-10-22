#include<iostream>
using namespace std;

class Stack{
    int arr[100];
    int top;

    public:
    Stack()
    {
        top = -1;
    }
    void insert(int a)
    {
        cout<< "enter the array: ";
        for(int i=0; i<a;i++)
        {
            cin >> arr[i];
            top++;
        }
        
    }
    void pop()
    {
        top--;
    }
    void display(int a)
    {   cout << "Array is " << endl;
        for(int i=0; i<=top; i++)
        {
            cout << arr[i] << " ";
        }
    }
    

};

int main()
{   Stack s;
    int a;
    cout << "Enter the size of the array ";
    cin >> a;
    s.insert(a);
    s.pop();
    s.display(a);
}