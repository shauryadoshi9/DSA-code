/*
================================================================================
QUESTION: Implement stack using Queues 6
Platform: HackerRank
Difficulty: Medium

Problem Statement:
Implement a Last-In-First-Out (LIFO) stack using queues.
You must support the following standard stack operations:
1 x: Push element x onto the stack.
2:   Pop (removes) the element on top of the stack.
3:   Print the element on top of the stack.
4:   Check if the stack is empty (print 1 for true, 0 for false).

Algorithm (Using a Single Queue):
- To achieve LIFO using a FIFO queue:
  When pushing an element x:
  1. Note the current size of the queue (s).
  2. Enqueue the new element x.
  3. Dequeue and re-enqueue all previous s elements one by one.
  This places the newly inserted element at the front of the queue,
  making pop() and top() O(1) operations.

Input Format:
- The first line contains an integer q, the number of operations/queries.
- The next q lines contain operations:
    1 x : push x
    2   : pop
    3   : print top element
    4   : check if empty

Output Format:
- Output result for each query of type 3 and 4 on a new line.
================================================================================
*/

#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    MyStack() {}

    void push(int x) {
        int s = q.size();
        q.push(x);

        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (!q.empty()) {
            q.pop();
        }
    }

    int top() {
        if (!q.empty()) {
            return q.front();
        }
        return -1;
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack st;
    int queries;

    cout << "========================================\n";
    cout << "    IMPLEMENT STACK USING QUEUES 6\n";
    cout << "========================================\n";

    cout << "Enter number of queries: ";
    if (!(cin >> queries) || queries <= 0) {
        return 0;
    }

    cout << "Enter " << queries << " operations:\n";
    cout << "  Format: 1 x (Push), 2 (Pop), 3 (Top), 4 (Empty?)\n";

    for (int i = 0; i < queries; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            st.push(x);
        } else if (type == 2) {
            st.pop();
        } else if (type == 3) {
            cout << st.top() << "\n";
        } else if (type == 4) {
            cout << (st.empty() ? 1 : 0) << "\n";
        }
    }

    return 0;
}
