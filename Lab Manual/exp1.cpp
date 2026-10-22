/*
================================================================================
EXPERIMENT - 1
Aim: Implement the Polynomial representation using a Array.
Tools / Apparatus: O.S.: Microsoft Windows (any) / Linux / DOS
Packages: Turbo/Borland/GNU - C/C++

Procedure: 
The following steps are required to make the addition of two polynomial:
1) Design the structure of term using C/C++ structure:
   struct Term {
       int coeff;
       int exp;
   };
2) Insert term at the end of polynomial using insert function.
   Pass coefficient, exponent and array of terms as argument.
3) Implement polynomial addition function for addition of two polynomials and store
   in third polynomial as a result:
   a. If (T1.exp == T2.exp) then add T1.coeff and T2.coeff and store in T3.coeff.
      Advance both T1 and T2 pointers.
   b. If (T1.exp > T2.exp) then T3.exp = T1.exp & T3.coeff = T1.coeff.
      Advance T1 pointer.
   c. Else (T1.exp < T2.exp) then T3.exp = T2.exp & T3.coeff = T2.coeff.
      Advance T2 pointer.
4) Display the result of Term T3 polynomial.
================================================================================
*/

#include <iostream>
using namespace std;

// Structure to represent a single term of a polynomial
struct Term {
    int coeff;
    int exp;
};

// Function to sort terms of a polynomial in descending order of exponents
void sortPolynomial(Term poly[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (poly[j].exp < poly[j + 1].exp) {
                Term temp = poly[j];
                poly[j] = poly[j + 1];
                poly[j + 1] = temp;
            }
        }
    }
}

// Function to add two polynomials represented as arrays
int addPolynomials(Term p1[], int n1, Term p2[], int n2, Term p3[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        // Case a: Exponents are equal -> add coefficients
        if (p1[i].exp == p2[j].exp) {
            int sumCoeff = p1[i].coeff + p2[j].coeff;
            if (sumCoeff != 0) {
                p3[k].coeff = sumCoeff;
                p3[k].exp = p1[i].exp;
                k++;
            }
            i++;
            j++;
        }
        // Case b: Exponent of first is greater -> copy from first
        else if (p1[i].exp > p2[j].exp) {
            p3[k].coeff = p1[i].coeff;
            p3[k].exp = p1[i].exp;
            k++;
            i++;
        }
        // Case c: Exponent of second is greater -> copy from second
        else {
            p3[k].coeff = p2[j].coeff;
            p3[k].exp = p2[j].exp;
            k++;
            j++;
        }
    }

    // Append remaining terms of first polynomial
    while (i < n1) {
        p3[k++] = p1[i++];
    }

    // Append remaining terms of second polynomial
    while (j < n2) {
        p3[k++] = p2[j++];
    }

    return k; // Return number of terms in resultant polynomial
}

// Function to display a polynomial
void displayPolynomial(Term poly[], int n) {
    if (n == 0) {
        cout << "0\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (i > 0 && poly[i].coeff > 0) {
            cout << " + ";
        } else if (i > 0 && poly[i].coeff < 0) {
            cout << " - ";
        } else if (poly[i].coeff < 0) {
            cout << "-";
        }

        int absCoeff = (poly[i].coeff < 0) ? -poly[i].coeff : poly[i].coeff;

        if (poly[i].exp == 0) {
            cout << absCoeff;
        } else if (poly[i].exp == 1) {
            if (absCoeff == 1) cout << "x";
            else cout << absCoeff << "x";
        } else {
            if (absCoeff == 1) cout << "x^" << poly[i].exp;
            else cout << absCoeff << "x^" << poly[i].exp;
        }
    }
    cout << "\n";
}

int main() {
    int n1, n2;

    cout << "========================================\n";
    cout << " POLYNOMIAL ADDITION USING ARRAYS\n";
    cout << "========================================\n";

    cout << "Enter number of terms in First Polynomial: ";
    cin >> n1;

    Term *p1 = new Term[n1];
    cout << "Enter Coefficient and Exponent for First Polynomial (coeff exp):\n";
    for (int i = 0; i < n1; i++) {
        cout << "  Term " << i + 1 << ": ";
        cin >> p1[i].coeff >> p1[i].exp;
    }

    cout << "\nEnter number of terms in Second Polynomial: ";
    cin >> n2;

    Term *p2 = new Term[n2];
    cout << "Enter Coefficient and Exponent for Second Polynomial (coeff exp):\n";
    for (int i = 0; i < n2; i++) {
        cout << "  Term " << i + 1 << ": ";
        cin >> p2[i].coeff >> p2[i].exp;
    }

    // Sort terms in descending order of exponents
    sortPolynomial(p1, n1);
    sortPolynomial(p2, n2);

    cout << "\nFirst Polynomial P1(x)  : ";
    displayPolynomial(p1, n1);

    cout << "Second Polynomial P2(x) : ";
    displayPolynomial(p2, n2);

    Term *p3 = new Term[n1 + n2];
    int n3 = addPolynomials(p1, n1, p2, n2, p3);

    cout << "\nResultant Polynomial P3(x) = P1(x) + P2(x):\n";
    cout << "Result: ";
    displayPolynomial(p3, n3);

    delete[] p1;
    delete[] p2;
    delete[] p3;

    return 0;
}
