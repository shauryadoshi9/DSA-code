/*
Question:
Write a C++ function to add two polynomials where terms may be in random
order of powers. Use arrays of structures to represent each polynomial.
(Without using sort() function from <algorithm>)
*/

#include <iostream>
using namespace std;

struct Term
{
    int coeff;
    int exp;
};

int main()
{
    Term p1[20], p2[20], sum[40], temp;
    int n1, n2;

    cout << "Enter number of terms in First Polynomial: ";
    cin >> n1;

    cout << "Enter Coefficient and Exponent:\n";
    for(int i = 0; i < n1; i++)
        cin >> p1[i].coeff >> p1[i].exp;

    cout << "Enter number of terms in Second Polynomial: ";
    cin >> n2;

    cout << "Enter Coefficient and Exponent:\n";
    for(int i = 0; i < n2; i++)
        cin >> p2[i].coeff >> p2[i].exp;

    // Bubble Sort First Polynomial (Descending Exponent)
    for(int i = 0; i < n1 - 1; i++)
    {
        for(int j = 0; j < n1 - i - 1; j++)
        {
            if(p1[j].exp < p1[j + 1].exp)
            {
                temp = p1[j];
                p1[j] = p1[j + 1];
                p1[j + 1] = temp;
            }
        }
    }

    // Bubble Sort Second Polynomial (Descending Exponent)
    for(int i = 0; i < n2 - 1; i++)
    {
        for(int j = 0; j < n2 - i - 1; j++)
        {
            if(p2[j].exp < p2[j + 1].exp)
            {
                temp = p2[j];
                p2[j] = p2[j + 1];
                p2[j + 1] = temp;
            }
        }
    }

    int i = 0, j = 0, k = 0;

    while(i < n1 && j < n2)
    {
        if(p1[i].exp == p2[j].exp)
        {
            sum[k].coeff = p1[i].coeff + p2[j].coeff;
            sum[k].exp = p1[i].exp;
            i++;
            j++;
            k++;
        }
        else if(p1[i].exp > p2[j].exp)
        {
            sum[k++] = p1[i++];
        }
        else
        {
            sum[k++] = p2[j++];
        }
    }

    while(i < n1)
        sum[k++] = p1[i++];

    while(j < n2)
        sum[k++] = p2[j++];

    cout << "\nResult Polynomial:\n";

    for(i = 0; i < k; i++)
    {
        cout << sum[i].coeff << "x^" << sum[i].exp;

        if(i != k - 1)
            cout << " + ";
    }

    return 0;
}