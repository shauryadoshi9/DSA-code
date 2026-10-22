/*
================================================================================
EXPERIMENT - 1 (Question 2)
Aim: Implement Polynomial Multiplication using Arrays.
Tools / Apparatus: O.S.: Microsoft Windows (any) / Linux / DOS
Packages: Turbo/Borland/GNU - C/C++

Procedure:
1) Represent polynomials using an array of structures:
   struct Term { int coeff; int exp; };
2) For each term of the first polynomial, multiply it by every term of the second:
   p3[k].coeff = p1[i].coeff * p2[j].coeff;
   p3[k].exp = p1[i].exp + p2[j].exp;
3) Combine like terms (terms with the same exponent).
4) Sort terms in descending order of exponents and display the result.
================================================================================
*/

#include <iostream>
using namespace std;

struct Term {
    int coeff;
    int exp;
};

// Function to multiply two polynomials
int multiplyPolynomials(Term p1[], int n1, Term p2[], int n2, Term p3[]) {
    int maxProductTerms = n1 * n2;
    Term *temp = new Term[maxProductTerms];
    int tempCount = 0;

    // Multiply every term of p1 with every term of p2
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            temp[tempCount].coeff = p1[i].coeff * p2[j].coeff;
            temp[tempCount].exp = p1[i].exp + p2[j].exp;
            tempCount++;
        }
    }

    // Combine like terms
    int k = 0;
    bool *visited = new bool[tempCount];
    for (int i = 0; i < tempCount; i++) visited[i] = false;

    for (int i = 0; i < tempCount; i++) {
        if (visited[i]) continue;

        int totalCoeff = temp[i].coeff;
        for (int j = i + 1; j < tempCount; j++) {
            if (temp[i].exp == temp[j].exp) {
                totalCoeff += temp[j].coeff;
                visited[j] = true;
            }
        }

        if (totalCoeff != 0) {
            p3[k].coeff = totalCoeff;
            p3[k].exp = temp[i].exp;
            k++;
        }
    }

    // Sort in descending order of exponents
    for (int i = 0; i < k - 1; i++) {
        for (int j = 0; j < k - i - 1; j++) {
            if (p3[j].exp < p3[j + 1].exp) {
                Term t = p3[j];
                p3[j] = p3[j + 1];
                p3[j + 1] = t;
            }
        }
    }

    delete[] temp;
    delete[] visited;
    return k;
}

// Function to display polynomial
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
    cout << " POLYNOMIAL MULTIPLICATION USING ARRAYS\n";
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

    cout << "\nFirst Polynomial P1(x)  : ";
    displayPolynomial(p1, n1);

    cout << "Second Polynomial P2(x) : ";
    displayPolynomial(p2, n2);

    Term *p3 = new Term[n1 * n2 + 1];
    int n3 = multiplyPolynomials(p1, n1, p2, n2, p3);

    cout << "\nResultant Polynomial P3(x) = P1(x) * P2(x):\n";
    cout << "Result: ";
    displayPolynomial(p3, n3);

    delete[] p1;
    delete[] p2;
    delete[] p3;

    return 0;
}
