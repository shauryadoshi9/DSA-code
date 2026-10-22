/*
================================================================================
EXPERIMENT - 3
Aim: Make the basic operations of circular Queue.
Tools / Apparatus: O.S.: Microsoft Windows (any) / Linux / DOS
Packages: Turbo/Borland/GNU - C/C++

Procedure:
CQINSERT(CQ, F, R, MAX, NAME) : Given F and R, pointers to the front and rear 
elements of a circular queue CQ consisting of MAX elements and an element NAME. 
This procedure inserts X at the rear end of the queue. Prior to the first 
invocation of the procedure, F and R have been set to 0. 
Here 'temp' is a temporary variable within this procedure.

STEP 1 : [Incrementing rear pointer]
         Temp <-- R
         R <-- (R+1) % MAX
STEP 2 : [Check for overflow condition]
         If (R == F)
         then R <-- Temp
         write('Overflow')
         Return
STEP 3 : [Insert element]
         Q[R] <-- NAME
         Return

CQDELETE(CQ, F, R) : Given F and R, pointer to the front and the queue CQ 
to which they correspond. This procedure deletes and returns the element at the 
front-end of the queue.

STEP 1 : [Check for underflow condition]
         If (R == F)
         then Write('Underflow')
         Return
STEP 2 : [Increment the front pointer]
         F <-- (F+1) % MAX
STEP 3 : [Delete element]
         Write(Q[F])
         Return
================================================================================
*/

#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *Q;
    int F;
    int R;
    int MAX;

public:
    CircularQueue(int size) {
        MAX = size;
        Q = new int[MAX];
        F = 0;
        R = 0;
    }

    ~CircularQueue() {
        delete[] Q;
    }

    // CQINSERT procedure from manual
    void CQINSERT(int NAME) {
        // STEP 1 : [Incrementing rear pointer]
        int temp = R;
        R = (R + 1) % MAX;

        // STEP 2 : [Check for overflow condition]
        if (R == F) {
            R = temp;
            cout << "Queue Overflow! Cannot insert " << NAME << ".\n";
            return;
        }

        // STEP 3 : [Insert element]
        Q[R] = NAME;
        cout << "Element " << NAME << " inserted at rear position " << R << ".\n";
    }

    // CQDELETE procedure from manual
    void CQDELETE() {
        // STEP 1 : [Check for underflow condition]
        if (R == F) {
            cout << "Queue Underflow! Queue is empty.\n";
            return;
        }

        // STEP 2 : [Increment the front pointer]
        F = (F + 1) % MAX;

        // STEP 3 : [Delete element]
        cout << "Deleted element: " << Q[F] << " from front position " << F << ".\n";
    }

    // Display circular queue elements from F to R
    void display() {
        if (R == F) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Circular Queue elements: ";
        int i = (F + 1) % MAX;
        while (true) {
            cout << Q[i] << " ";
            if (i == R) break;
            i = (i + 1) % MAX;
        }
        cout << "\n(Front F = " << F << ", Rear R = " << R << ")\n";
    }
};

int main() {
    int size;
    cout << "========================================\n";
    cout << "       CIRCULAR QUEUE OPERATIONS\n";
    cout << "========================================\n";

    cout << "Enter maximum capacity of Circular Queue: ";
    cin >> size;

    if (size <= 1) size = 5;

    CircularQueue cq(size);
    int choice, val;

    while (true) {
        cout << "\n---------------- MENU ----------------\n";
        cout << "1. Insert (CQINSERT)\n";
        cout << "2. Delete (CQDELETE)\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        if (!(cin >> choice)) break;

        switch (choice) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> val;
                cq.CQINSERT(val);
                break;
            case 2:
                cq.CQDELETE();
                break;
            case 3:
                cq.display();
                break;
            case 4:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please choose 1-4.\n";
        }
    }

    return 0;
}
