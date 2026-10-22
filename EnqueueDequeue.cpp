#include <iostream>
using namespace std;

const int MAX = 5;

int queueArr[MAX];
int front = -1;
int rear = -1;


// ---------- ENQUEUE FUNCTION ----------
void enqueue(int value) {
    if (rear == MAX - 1) {
        cout << "Queue is full\n";
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear++;
    queueArr[rear] = value;

    cout << value << " inserted into queue\n";
}


// ---------- DEQUEUE FUNCTION ----------
void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty\n";
        return;
    }

    cout << queueArr[front] << " deleted from queue\n";
    front++;

    // Reset when the final element is removed
    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

//-------------DISPLAY FUNCTION----------
void display() {
    if (front == -1) {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Queue elements: \n";
    for (int i = front; i <= rear; i++) {
        cout << queueArr[i] << " ";
    }
    cout << endl;
}


// ---------- MAIN PART ----------
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    dequeue();
    display();

    enqueue(40);
    display();

    return 0;
}