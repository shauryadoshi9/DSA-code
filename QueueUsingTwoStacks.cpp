/*
================================================================================
QUESTION: Queue using Two Stacks
Platform: HackerRank (Data Structures -> Queues)
Difficulty: Medium

Problem Statement:
A queue is a First-In-First-Out (FIFO) data structure.
In this challenge, you must implement a queue using two stacks.
Then process q queries, where each query is one of the following 3 types:
1 x: Enqueue element x into the end of the queue.
2:   Dequeue the element at the front of the queue.
3:   Print the element at the front of the queue.

Algorithm (Two Stacks for Amortized O(1) Operations):
- Stack 'inbox': stores newly enqueued elements.
- Stack 'outbox': stores elements in FIFO order ready for dequeue/peek.
- When 'outbox' is empty and a dequeue/peek is needed, pop all elements from
  'inbox' and push them into 'outbox' (reversing the order to achieve FIFO).

Input Format:
- The first line contains a single integer q, the number of queries.
- Each of the next q lines contains a single query of the 3 types described above.

Output Format:
- For each query of type 3, print the value of the element at the front of the
  queue on a new line.
================================================================================
*/

#include <iostream>
#include <stack>
using namespace std;

class QueueUsingTwoStacks {
private:
    stack<int> inbox;
    stack<int> outbox;

    void shiftStacks() {
        if (outbox.empty()) {
            while (!inbox.empty()) {
                outbox.push(inbox.top());
                inbox.pop();
            }
        }
    }

public:
    void enqueue(int x) {
        inbox.push(x);
    }

    void dequeue() {
        shiftStacks();
        if (!outbox.empty()) {
            outbox.pop();
        }
    }

    int front() {
        shiftStacks();
        if (!outbox.empty()) {
            return outbox.top();
        }
        return -1;
    }

    bool empty() {
        return inbox.empty() && outbox.empty();
    }
};

int main() {
    QueueUsingTwoStacks q;
    int queries;

    cout << "========================================\n";
    cout << "        QUEUE USING TWO STACKS\n";
    cout << "========================================\n";

    cout << "Enter number of queries: ";
    if (!(cin >> queries) || queries <= 0) {
        return 0;
    }

    cout << "Enter " << queries << " queries:\n";
    cout << "  Format: 1 x (Enqueue), 2 (Dequeue), 3 (Print Front)\n";

    for (int i = 0; i < queries; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            q.enqueue(x);
        } else if (type == 2) {
            q.dequeue();
        } else if (type == 3) {
            cout << q.front() << "\n";
        }
    }

    return 0;
}
