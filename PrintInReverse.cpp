/*
================================================================================
QUESTION: Print in Reverse
Platform: HackerRank (Data Structures -> Linked Lists)
Difficulty: Easy

Problem Statement:
Given a pointer to the head of a singly-linked list, print each data element
in reverse order from the tail to the head, each on a new line.
Do not reverse the list itself; only print in reverse order.

Input Format:
- The first line of input contains an integer t, the number of test cases.
- For each testcase:
    - An integer n, the number of elements in the linked list.
    - n lines follows, each containing an integer element to insert into the list.

Output Format:
- For each testcase, print the elements of the linked list in reverse order,
  each on a new line.
================================================================================
*/

#include <iostream>
using namespace std;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};

void reversePrint(SinglyLinkedListNode* head) {
    if (head == nullptr) {
        return;
    }
    reversePrint(head->next);
    cout << head->data << endl;
}

void insertNode(SinglyLinkedListNode*& head, SinglyLinkedListNode*& tail, int data) {
    SinglyLinkedListNode* node = new SinglyLinkedListNode(data);
    if (head == nullptr) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

void freeList(SinglyLinkedListNode* head) {
    while (head != nullptr) {
        SinglyLinkedListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int tests;
    cout << "Enter number of test cases: ";
    if (!(cin >> tests) || tests <= 0) {
        return 0;
    }

    for (int t = 0; t < tests; t++) {
        SinglyLinkedListNode* head = nullptr;
        SinglyLinkedListNode* tail = nullptr;

        int n;
        cout << "\n[Test Case " << t + 1 << "] Enter number of elements in linked list: ";
        cin >> n;

        cout << "Enter " << n << " elements:\n";
        for (int i = 0; i < n; i++) {
            int item;
            cin >> item;
            insertNode(head, tail, item);
        }

        cout << "Elements printed in reverse order:\n";
        reversePrint(head);

        freeList(head);
    }

    return 0;
}
