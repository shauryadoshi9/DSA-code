/*
================================================================================
QUESTION: Cycle Detection
Platform: HackerRank (Data Structures -> Linked Lists)
Difficulty: Medium

Problem Statement:
A linked list is said to contain a cycle if any node is visited more than once
while traversing the list. Given a pointer to the head of a linked list,
determine if it contains a cycle.
Return true (1) if there is a cycle, otherwise false (0).

Algorithm:
Floyd's Cycle-Finding Algorithm (Tortoise and Hare):
- Use two pointers: slow moving 1 step at a time, fast moving 2 steps.
- If fast reaches null, no cycle exists.
- If slow and fast meet, a cycle exists.
================================================================================
*/

#include <iostream>
using namespace std;

// Definition of singly linked list node
struct Node {
    int data;
    Node* next;

    Node(int value = 0) {
        data = value;
        next = nullptr;
    }
};

// HackerRank Solution Function: Floyd's Cycle Detection Algorithm
bool hasCycle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;          // Move 1 step
        fast = fast->next->next;    // Move 2 steps

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

// Helper to append a node
void insertNode(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    int n;
    cout << "========================================\n";
    cout << "            CYCLE DETECTION\n";
    cout << "========================================\n";

    cout << "Enter number of nodes in the linked list: ";
    cin >> n;

    if (n <= 0) {
        cout << "List is empty (No cycle).\n";
        return 0;
    }

    cout << "Enter " << n << " node values:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertNode(head, tail, val);
    }

    int cycleIndex;
    cout << "Enter index to link tail to for cycle (0 to " << n - 1 << ", or -1 for no cycle): ";
    cin >> cycleIndex;

    if (cycleIndex >= 0 && cycleIndex < n) {
        Node* target = head;
        for (int i = 0; i < cycleIndex; i++) {
            target = target->next;
        }
        tail->next = target;
        cout << "Cycle created from tail back to node at index " << cycleIndex 
             << " (Value: " << target->data << ").\n";
    } else {
        cout << "No cycle created.\n";
    }

    if (hasCycle(head)) {
        cout << "\nResult: 1 (Cycle detected)\n";
    } else {
        cout << "\nResult: 0 (No cycle)\n";
    }

    return 0;
}