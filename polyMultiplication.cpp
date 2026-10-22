#include <iostream>
using namespace std;

struct poly{
    int coeff;
    int exp;
};

int mul(poly p1[], poly p2[], poly p3[], int n1, int n2){
    int k = 0;
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            p3[k].coeff = p1[i].coeff * p2[j].coeff;
            p3[k].exp = p1[i].exp + p2[j].exp;
            k++;
        }
    }
    return k;
}
int main()
{
    poly p1[10], p2[10], p3[20];
    int n1, n2, i, j, k;
    cout << "Enter the number of terms in first polynomial: ";
    cin >> n1;
    cout << "Enter the coefficients and exponents of first polynomial: ";
    for(i = 0; i < n1; i++){
        cin >> p1[i].coeff >> p1[i].exp;
    }
    cout << "Enter the number of terms in second polynomial: ";
    cin >> n2;
    cout << "Enter the coefficients and exponents of second polynomial: ";
    for(i = 0; i < n2; i++){
        cin >> p2[i].coeff >> p2[i].exp;
    }
    
    k = mul(p1, p2, p3, n1, n2);
    
    cout << "Resultant polynomial after multiplication: ";
    for(i = 0; i < k; i++){
        cout << p3[i].coeff << "x^" << p3[i].exp;
        if(i != k - 1){
            cout << " + ";
        }
    }
    
    return 0;
}
