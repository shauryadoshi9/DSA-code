/*
================================================================================
QUESTION: Compare two linked lists
Platform: HackerRank (Data Structures -> Linked Lists)
Difficulty: Easy

Problem Statement:
Compare two linked lists and return 1 (or true) if their lengths and corresponding
values are identical, or 0 (or false) otherwise.

Input Format:
- The first line contains an integer t, the number of test cases.
- For each test case:
    - An integer n, the number of nodes in the first linked list.
    - n lines follows, each containing an integer element.
    - An integer m, the number of nodes in the second linked list.
    - m lines follows, each containing an integer element.

Output Format:
- Print 1 if lists are identical, 0 otherwise.
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

bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data != head2->data) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return (head1 == nullptr && head2 == nullptr);
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
        SinglyLinkedListNode* head1 = nullptr;
        SinglyLinkedListNode* tail1 = nullptr;
        SinglyLinkedListNode* head2 = nullptr;
        SinglyLinkedListNode* tail2 = nullptr;

        int n;
        cout << "\n[Test Case " << t + 1 << "]\nEnter number of elements in first list: ";
        cin >> n;
        cout << "Enter " << n << " elements for first list:\n";
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            insertNode(head1, tail1, val);
        }

        int m;
        cout << "Enter number of elements in second list: ";
        cin >> m;
        cout << "Enter " << m << " elements for second list:\n";
        for (int i = 0; i < m; i++) {
            int val;
            cin >> val;
            insertNode(head2, tail2, val);
        }

        bool result = compare_lists(head1, head2);
        cout << "Comparison Result: " << (result ? 1 : 0) << " (" 
             << (result ? "Identical" : "Different") << ")\n";

        freeList(head1);
        freeList(head2);
    }

    return 0;
}
