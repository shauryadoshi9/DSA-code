#include <iostream>
#include <vector>
using namespace std;

class Stack
{
    vector<int> arr;

public:
    void insert(int a)
    {
        int value;
        cout << "Enter the array: ";
        for (int i = 0; i < a; i++)
        {
            cin >> value;
            arr.push_back(value);
        }
    }

    void pop()
    {
        if (!arr.empty())
        {
            arr.pop_back();
        }
        else
        {
            cout << "Stack is empty!" << endl;
        }
    }

    void display()
    {
        cout << "Array is" << endl;
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    int a;

    cout << "Enter the size of the array: ";
    cin >> a;

    s.insert(a);
    s.pop();
    s.display();

    return 0;
}