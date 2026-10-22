/*
================================================================================
EXPERIMENT - 12 (LABWORK BEYOND CURRICULA 2)
Aim: Implement generalized representation of Link List for polynomial, matrix ...etc
     type of application (without using templates).
Tools / Apparatus: O.S.: Microsoft Windows (any) / Linux / DOS
Packages: Turbo/Borland/GNU - C/C++

Procedure:
Follow the steps to generate the generalize list:
1) Implement List, List Iterator and List Node class as per given in text book:
   - List class is used for implementing the list as a general format.
   - Generate the list nodes which accept application data members.
   - Implement add, create, first, last ... etc functions in List Iterator class.
2) Use structures for representing matrix, polynomial ...etc.
3) Make the instance of list iterator class and use for making matrix or polynomial equation
   using generalize list class.
4) Use normal addition function for polynomial or matrix addition.
================================================================================
*/

#include <iostream>
using namespace std;

// ============================================================================
// PART 1: POLYNOMIAL REPRESENTATION & ADDITION (WITHOUT TEMPLATES)
// ============================================================================

struct Term {
    int coeff;
    int exp;
    Term(int c = 0, int e = 0) : coeff(c), exp(e) {}
};

class PolyListNode {
public:
    Term data;
    PolyListNode *link;

    PolyListNode(const Term &t) {
        data = t;
        link = NULL;
    }
};

class PolyList {
public:
    PolyListNode *first;
    PolyListNode *last;

    PolyList() {
        first = NULL;
        last = NULL;
    }

    ~PolyList() {
        PolyListNode *curr = first;
        while (curr != NULL) {
            PolyListNode *temp = curr;
            curr = curr->link;
            delete temp;
        }
    }

    void add(const Term &t) {
        PolyListNode *newNode = new PolyListNode(t);
        if (first == NULL) {
            first = newNode;
            last = newNode;
        } else {
            last->link = newNode;
            last = newNode;
        }
    }
};

// List Iterator class for Polynomial List
class PolyListIterator {
private:
    const PolyList &list;
    PolyListNode *current;

public:
    PolyListIterator(const PolyList &l) : list(l), current(l.first) {}

    Term* first() {
        current = list.first;
        if (current != NULL) return &(current->data);
        return NULL;
    }

    Term* next() {
        if (current != NULL) {
            current = current->link;
            if (current != NULL) return &(current->data);
        }
        return NULL;
    }

    bool isEnd() const {
        return current == NULL;
    }
};

// Function to add two polynomials using Iterator
PolyList addPolynomials(const PolyList &poly1, const PolyList &poly2) {
    PolyList result;
    PolyListIterator it1(poly1);
    PolyListIterator it2(poly2);

    Term *t1 = it1.first();
    Term *t2 = it2.first();

    while (t1 != NULL && t2 != NULL) {
        if (t1->exp == t2->exp) {
            int sumCoeff = t1->coeff + t2->coeff;
            if (sumCoeff != 0) {
                result.add(Term(sumCoeff, t1->exp));
            }
            t1 = it1.next();
            t2 = it2.next();
        } else if (t1->exp > t2->exp) {
            result.add(*t1);
            t1 = it1.next();
        } else {
            result.add(*t2);
            t2 = it2.next();
        }
    }

    while (t1 != NULL) {
        result.add(*t1);
        t1 = it1.next();
    }

    while (t2 != NULL) {
        result.add(*t2);
        t2 = it2.next();
    }

    return result;
}

void displayPolynomial(const PolyList &poly) {
    PolyListIterator it(poly);
    Term *t = it.first();
    if (t == NULL) {
        cout << "0\n";
        return;
    }

    bool first = true;
    while (t != NULL) {
        if (!first) {
            if (t->coeff > 0) cout << " + ";
            else cout << " - ";
        } else if (t->coeff < 0) {
            cout << "-";
        }

        int absC = (t->coeff < 0) ? -t->coeff : t->coeff;
        if (t->exp == 0) cout << absC;
        else if (t->exp == 1) cout << absC << "x";
        else cout << absC << "x^" << t->exp;

        first = false;
        t = it.next();
    }
    cout << "\n";
}

// ============================================================================
// PART 2: SPARSE MATRIX REPRESENTATION & ADDITION (WITHOUT TEMPLATES)
// ============================================================================

struct MatrixElement {
    int row;
    int col;
    int val;
    MatrixElement(int r = 0, int c = 0, int v = 0) : row(r), col(c), val(v) {}
};

class MatrixListNode {
public:
    MatrixElement data;
    MatrixListNode *link;

    MatrixListNode(const MatrixElement &e) {
        data = e;
        link = NULL;
    }
};

class MatrixList {
public:
    MatrixListNode *first;
    MatrixListNode *last;

    MatrixList() {
        first = NULL;
        last = NULL;
    }

    ~MatrixList() {
        MatrixListNode *curr = first;
        while (curr != NULL) {
            MatrixListNode *temp = curr;
            curr = curr->link;
            delete temp;
        }
    }

    void add(const MatrixElement &e) {
        MatrixListNode *newNode = new MatrixListNode(e);
        if (first == NULL) {
            first = newNode;
            last = newNode;
        } else {
            last->link = newNode;
            last = newNode;
        }
    }
};

// List Iterator class for Matrix List
class MatrixListIterator {
private:
    const MatrixList &list;
    MatrixListNode *current;

public:
    MatrixListIterator(const MatrixList &l) : list(l), current(l.first) {}

    MatrixElement* first() {
        current = list.first;
        if (current != NULL) return &(current->data);
        return NULL;
    }

    MatrixElement* next() {
        if (current != NULL) {
            current = current->link;
            if (current != NULL) return &(current->data);
        }
        return NULL;
    }

    bool isEnd() const {
        return current == NULL;
    }
};

// Function to add two sparse matrices using Iterator
MatrixList addMatrices(const MatrixList &m1, const MatrixList &m2) {
    MatrixList result;
    MatrixListIterator it1(m1);
    MatrixListIterator it2(m2);

    MatrixElement *e1 = it1.first();
    MatrixElement *e2 = it2.first();

    while (e1 != NULL && e2 != NULL) {
        if (e1->row == e2->row && e1->col == e2->col) {
            int sumVal = e1->val + e2->val;
            if (sumVal != 0) {
                result.add(MatrixElement(e1->row, e1->col, sumVal));
            }
            e1 = it1.next();
            e2 = it2.next();
        } else if (e1->row < e2->row || (e1->row == e2->row && e1->col < e2->col)) {
            result.add(*e1);
            e1 = it1.next();
        } else {
            result.add(*e2);
            e2 = it2.next();
        }
    }

    while (e1 != NULL) {
        result.add(*e1);
        e1 = it1.next();
    }

    while (e2 != NULL) {
        result.add(*e2);
        e2 = it2.next();
    }

    return result;
}

void displayMatrixList(const MatrixList &mat, const string &name) {
    cout << name << " [Non-zero Elements (Row, Col, Value)]:\n";
    MatrixListIterator it(mat);
    MatrixElement *e = it.first();
    if (e == NULL) {
        cout << "  (Empty / Zero matrix)\n";
        return;
    }
    while (e != NULL) {
        cout << "  Row " << e->row << ", Col " << e->col << " -> Value: " << e->val << "\n";
        e = it.next();
    }
}

int main() {
    int mainChoice;

    cout << "====================================================================\n";
    cout << " GENERALIZED LINKED LIST REPRESENTATION (POLYNOMIAL & MATRIX)\n";
    cout << "====================================================================\n";

    cout << "Choose Application to Run:\n";
    cout << "1. Polynomial Representation & Addition using List and Iterator\n";
    cout << "2. Sparse Matrix Representation & Addition using List and Iterator\n";
    cout << "Enter choice (1 or 2): ";
    cin >> mainChoice;

    if (mainChoice == 1) {
        PolyList polyA, polyB;
        int n1, n2;

        cout << "\nEnter number of terms for First Polynomial: ";
        cin >> n1;
        cout << "Enter Coefficient and Exponent for First Polynomial (coeff exp):\n";
        for (int i = 0; i < n1; i++) {
            int c, e;
            cout << "  Term " << i + 1 << ": ";
            cin >> c >> e;
            polyA.add(Term(c, e));
        }

        cout << "\nEnter number of terms for Second Polynomial: ";
        cin >> n2;
        cout << "Enter Coefficient and Exponent for Second Polynomial (coeff exp):\n";
        for (int i = 0; i < n2; i++) {
            int c, e;
            cout << "  Term " << i + 1 << ": ";
            cin >> c >> e;
            polyB.add(Term(c, e));
        }

        cout << "\nPolynomial A(x) : ";
        displayPolynomial(polyA);

        cout << "Polynomial B(x) : ";
        displayPolynomial(polyB);

        PolyList polySum = addPolynomials(polyA, polyB);
        cout << "Sum A(x) + B(x) : ";
        displayPolynomial(polySum);
    } else {
        MatrixList matA, matB;
        int n1, n2;

        cout << "\nEnter number of non-zero elements for First Matrix: ";
        cin >> n1;
        cout << "Enter (row col value) for First Matrix:\n";
        for (int i = 0; i < n1; i++) {
            int r, c, v;
            cout << "  Element " << i + 1 << ": ";
            cin >> r >> c >> v;
            matA.add(MatrixElement(r, c, v));
        }

        cout << "\nEnter number of non-zero elements for Second Matrix: ";
        cin >> n2;
        cout << "Enter (row col value) for Second Matrix:\n";
        for (int i = 0; i < n2; i++) {
            int r, c, v;
            cout << "  Element " << i + 1 << ": ";
            cin >> r >> c >> v;
            matB.add(MatrixElement(r, c, v));
        }

        cout << "\n";
        displayMatrixList(matA, "Matrix A");
        displayMatrixList(matB, "Matrix B");

        MatrixList matSum = addMatrices(matA, matB);
        displayMatrixList(matSum, "Resultant Matrix (A + B)");
    }

    return 0;
}
