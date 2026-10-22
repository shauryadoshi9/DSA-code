/*
================================================================================
QUESTION: Delete duplicate-value nodes from a sorted linked list
Platform: HackerRank (Data Structures -> Linked Lists)
Difficulty: Easy / Intermediate

Problem Statement:
You are given the pointer to the head node of a sorted linked list, where the
data in the nodes is in increasing order. Delete nodes and return a sorted list
with only one element of each value. The head of the list may not change.

Input Format:
- The first line contains an integer t, the number of test cases.
- For each testcase:
    - An integer n, the number of elements in the linked list.
    - n lines follows, each containing an integer node data.

Output Format:
- For each testcase, print the unique elements of the linked list on a single line.
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

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    if (head == nullptr) return nullptr;

    SinglyLinkedListNode* current = head;

    while (current != nullptr && current->next != nullptr) {
        if (current->data == current->next->data) {
            SinglyLinkedListNode* duplicate = current->next;
            current->next = current->next->next;
            delete duplicate;
        } else {
            current = current->next;
        }
    }

    return head;
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

void printList(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* curr = head;
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
        SinglyLinkedListNode* head = nullptr;
        SinglyLinkedListNode* tail = nullptr;

        int n;
        cout << "\n[Test Case " << t + 1 << "]\nEnter number of elements in sorted linked list: ";
        cin >> n;

        cout << "Enter " << n << " sorted elements (can contain duplicates):\n";
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            insertNode(head, tail, val);
        }

        head = removeDuplicates(head);

        cout << "List after removing duplicates:\n";
        printList(head);
    }

    return 0;
}
