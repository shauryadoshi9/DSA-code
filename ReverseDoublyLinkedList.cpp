/*
================================================================================
QUESTION: Reverse a doubly linked list
Platform: HackerRank (Data Structures -> Linked Lists)
Difficulty: Easy / Intermediate

Problem Statement:
Given the pointer to the head node of a doubly-linked list, reverse the order
of the nodes in place and return the head of the reversed list.
You must swap the next and prev pointers of every node.

Input Format:
- The first line contains an integer t, the number of test cases.
- For each testcase:
    - An integer n, the number of elements in the doubly linked list.
    - n lines follows, each containing an integer node data.

Output Format:
- For each testcase, print the reversed doubly linked list on a single line
  separated by spaces.
================================================================================
*/

#include <iostream>
using namespace std;

struct DoublyLinkedListNode {
    int data;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;

    DoublyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    if (head == nullptr) return nullptr;

    DoublyLinkedListNode* current = head;
    DoublyLinkedListNode* newHead = nullptr;

    while (current != nullptr) {
        DoublyLinkedListNode* temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        newHead = current;
        current = current->prev;
    }

    return newHead;
}

void insertNode(DoublyLinkedListNode*& head, DoublyLinkedListNode*& tail, int data) {
    DoublyLinkedListNode* node = new DoublyLinkedListNode(data);
    if (head == nullptr) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
}

void printList(DoublyLinkedListNode* head) {
    DoublyLinkedListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->data;
        if (curr->next != nullptr) cout << " ";
        curr = curr->next;
    }
    cout << "\n";
}

int main() {
    int tests;
    cout << "Enter number of test cases: ";
    if (!(cin >> tests) || tests <= 0) {
        return 0;
    }

    for (int t = 0; t < tests; t++) {
        DoublyLinkedListNode* head = nullptr;
        DoublyLinkedListNode* tail = nullptr;

        int n;
        cout << "\n[Test Case " << t + 1 << "]\nEnter number of elements in doubly linked list: ";
        cin >> n;

        cout << "Enter " << n << " elements:\n";
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            insertNode(head, tail, val);
        }

        cout << "Original List: ";
        printList(head);

        head = reverse(head);

        cout << "Reversed List: ";
        printList(head);
    }

    return 0;
}
