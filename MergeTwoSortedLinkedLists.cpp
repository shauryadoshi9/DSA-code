/*
================================================================================
QUESTION: Merge two sorted linked lists
Platform: HackerRank (Data Structures -> Linked Lists)
Difficulty: Easy / Intermediate

Problem Statement:
Given pointers to the heads of two sorted linked lists, merge them into a single,
sorted linked list. Either list may be empty (i.e. head == nullptr).

Input Format:
- The first line contains an integer t, the number of test cases.
- For each testcase:
    - An integer n, the number of nodes in the first linked list.
    - n lines follows, each containing an integer node data.
    - An integer m, the number of nodes in the second linked list.
    - m lines follows, each containing an integer node data.

Output Format:
- For each testcase, print the merged sorted list on a single line separated by spaces.
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

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;

    SinglyLinkedListNode* mergedHead = nullptr;
    SinglyLinkedListNode* mergedTail = nullptr;

    if (head1->data <= head2->data) {
        mergedHead = head1;
        head1 = head1->next;
    } else {
        mergedHead = head2;
        head2 = head2->next;
    }
    mergedTail = mergedHead;

    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data <= head2->data) {
            mergedTail->next = head1;
            head1 = head1->next;
        } else {
            mergedTail->next = head2;
            head2 = head2->next;
        }
        mergedTail = mergedTail->next;
    }

    if (head1 != nullptr) {
        mergedTail->next = head1;
    } else {
        mergedTail->next = head2;
    }

    return mergedHead;
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
        SinglyLinkedListNode* head1 = nullptr;
        SinglyLinkedListNode* tail1 = nullptr;
        SinglyLinkedListNode* head2 = nullptr;
        SinglyLinkedListNode* tail2 = nullptr;

        int n;
        cout << "\n[Test Case " << t + 1 << "]\nEnter number of elements in first sorted list: ";
        cin >> n;
        cout << "Enter " << n << " sorted elements for first list:\n";
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            insertNode(head1, tail1, val);
        }

        int m;
        cout << "Enter number of elements in second sorted list: ";
        cin >> m;
        cout << "Enter " << m << " sorted elements for second list:\n";
        for (int i = 0; i < m; i++) {
            int val;
            cin >> val;
            insertNode(head2, tail2, val);
        }

        SinglyLinkedListNode* merged = mergeLists(head1, head2);
        cout << "Merged Sorted List:\n";
        printList(merged);
    }

    return 0;
}
