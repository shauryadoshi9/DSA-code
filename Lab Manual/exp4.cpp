/*
================================================================================
EXPERIMENT - 4
Aim: Implement the Polynomial representation using a Link -List.
Tools / Apparatus: O.S.: Microsoft Windows (any) / Linux / DOS
Packages: Turbo/Borland/GNU - C/C++

Procedure: 
1) Implement singly link list with two data members coefficient and exponent:
   struct ele { 
       struct ele *next; 
       int coef; 
       int power; 
   };
2) Follow the same process as per polynomial addition using an array:
   a. If (T1.exp == T2.exp) then add T1.coeff and T2.coeff and store in T3.coeff.
      And advance both T1 and T2 pointers.
   b. If (T1.exp > T2.exp) then T3.exp = T1.exp & T3.coeff = T1.coeff.
      Advance T1 pointer.
   c. Else (T1.exp < T2.exp) then T3.exp = T2.exp & T3.coeff = T2.coeff.
      Advance T2 pointer.
3) Display result of Term T3.
================================================================================
*/

#include <iostream>
using namespace std;

// Node structure as specified in the manual
struct ele {
    int coef;
    int power;
    struct ele *next;
};

// Function to create a new polynomial node dynamically
ele* createNode(int c, int p) {
    ele *newNode = new ele;
    newNode->coef = c;
    newNode->power = p;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term into a polynomial in descending order of power
void insertTerm(ele **head, int c, int p) {
    if (c == 0) return; // Do not insert terms with 0 coefficient

    ele *newNode = createNode(c, p);

    if (*head == NULL || (*head)->power < p) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    if ((*head)->power == p) {
        (*head)->coef += c;
        delete newNode;
        return;
    }

    ele *curr = *head;
    while (curr->next != NULL && curr->next->power > p) {
        curr = curr->next;
    }

    if (curr->next != NULL && curr->next->power == p) {
        curr->next->coef += c;
        delete newNode;
    } else {
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

// Function to append a term to the end of a polynomial list
void appendTerm(ele **head, ele **tail, int c, int p) {
    if (c == 0) return;
    ele *newNode = createNode(c, p);
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

// Function to add two polynomials represented as linked lists
ele* addPolynomials(ele *T1, ele *T2) {
    ele *T3_head = NULL;
    ele *T3_tail = NULL;

    while (T1 != NULL && T2 != NULL) {
        // Case a: Exponents are equal
        if (T1->power == T2->power) {
            int sumCoef = T1->coef + T2->coef;
            if (sumCoef != 0) {
                appendTerm(&T3_head, &T3_tail, sumCoef, T1->power);
            }
            T1 = T1->next;
            T2 = T2->next;
        }
        // Case b: T1 power is greater
        else if (T1->power > T2->power) {
            appendTerm(&T3_head, &T3_tail, T1->coef, T1->power);
            T1 = T1->next;
        }
        // Case c: T2 power is greater
        else {
            appendTerm(&T3_head, &T3_tail, T2->coef, T2->power);
            T2 = T2->next;
        }
    }

    // Append remaining terms from T1
    while (T1 != NULL) {
        appendTerm(&T3_head, &T3_tail, T1->coef, T1->power);
        T1 = T1->next;
    }

    // Append remaining terms from T2
    while (T2 != NULL) {
        appendTerm(&T3_head, &T3_tail, T2->coef, T2->power);
        T2 = T2->next;
    }

    return T3_head;
}

// Function to display a polynomial
void displayPolynomial(ele *head) {
    if (head == NULL) {
        cout << "0\n";
        return;
    }

    ele *curr = head;
    bool first = true;

    while (curr != NULL) {
        if (!first) {
            if (curr->coef > 0) cout << " + ";
            else cout << " - ";
        } else {
            if (curr->coef < 0) cout << "-";
        }

        int absCoef = (curr->coef < 0) ? -curr->coef : curr->coef;

        if (curr->power == 0) {
            cout << absCoef;
        } else if (curr->power == 1) {
            if (absCoef == 1) cout << "x";
            else cout << absCoef << "x";
        } else {
            if (absCoef == 1) cout << "x^" << curr->power;
            else cout << absCoef << "x^" << curr->power;
        }

        first = false;
        curr = curr->next;
    }
    cout << "\n";
}

int main() {
    ele *poly1 = NULL;
    ele *poly2 = NULL;
    ele *poly3 = NULL;

    cout << "========================================\n";
    cout << " POLYNOMIAL ADDITION USING LINKED LIST\n";
    cout << "========================================\n";

    int n1, n2;
    cout << "Enter number of terms in First Polynomial: ";
    cin >> n1;

    cout << "Enter Coefficient and Power for First Polynomial (coef power):\n";
    for (int i = 0; i < n1; i++) {
        int c, p;
        cout << "  Term " << i + 1 << ": ";
        cin >> c >> p;
        insertTerm(&poly1, c, p);
    }

    cout << "\nEnter number of terms in Second Polynomial: ";
    cin >> n2;

    cout << "Enter Coefficient and Power for Second Polynomial (coef power):\n";
    for (int i = 0; i < n2; i++) {
        int c, p;
        cout << "  Term " << i + 1 << ": ";
        cin >> c >> p;
        insertTerm(&poly2, c, p);
    }

    cout << "\nFirst Polynomial  T1(x): ";
    displayPolynomial(poly1);

    cout << "Second Polynomial T2(x): ";
    displayPolynomial(poly2);

    poly3 = addPolynomials(poly1, poly2);

    cout << "\nResultant Polynomial T3(x) = T1(x) + T2(x):\n";
    cout << "Result: ";
    displayPolynomial(poly3);

    return 0;
}
