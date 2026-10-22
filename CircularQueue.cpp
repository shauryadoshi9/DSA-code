#include <iostream>
using namespace std;

const int MAX = 5;

int queueArr[MAX];
int front = -1;
int rear = -1;


// ---------- ENQUEUE ----------
void enqueue(int value) {
    // Queue is full
    if ((rear + 1) % MAX == front) {
        cout << "Queue is full\n";
        return;
    }

    // First element
    if (front == -1) {
        front = 0;
        rear = 0;
    }
    else {
        rear = (rear + 1) % MAX;
    }

    queueArr[rear] = value;
    cout << value << " inserted\n";
}


// ---------- DEQUEUE ----------
void dequeue() {
    // Queue is empty
    if (front == -1) {
        cout << "Queue is empty\n";
        return;
    }

    cout << queueArr[front] << " deleted\n";

    // Only one element was present
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        front = (front + 1) % MAX;
    }
}


// ---------- DISPLAY ----------
void display() {
    if (front == -1) {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Queue: ";

    int i = front;

    while (true) {
        cout << queueArr[i] << " ";

        if (i == rear) {
            break;
        }

        i = (i + 1) % MAX;
    }

    cout << endl;
}


// ---------- MAIN PART ----------
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    dequeue();   // Removes 10
    dequeue();   // Removes 20

    enqueue(50);
    enqueue(60); // Goes back to index 0

    display();

    return 0;
}