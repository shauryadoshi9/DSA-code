/*
================================================================================
QUESTION: Find Merge Point of Two Lists
Platform: HackerRank (Data Structures -> Linked Lists)
Difficulty: Easy

Problem Statement:
Given pointers to the head nodes of 2 singly linked lists that merge at some node,
find the data of the node where the two lists merge.
It is guaranteed that the two head nodes will be different, and neither will be null.
The lists will merge at some node.

Algorithm:
Two-Pointer Traversal Technique:
- Initialize two pointers `ptr1` at head1 and `ptr2` at head2.
- Traverse both lists simultaneously.
- When `ptr1` reaches the end of list 1, redirect it to head2.
- When `ptr2` reaches the end of list 2, redirect it to head1.
- Both pointers travel an equal total distance: len(list1) + len(list2).
- They are guaranteed to meet exactly at the merge point node.
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

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* ptr1 = head1;
    SinglyLinkedListNode* ptr2 = head2;

    while (ptr1 != ptr2) {
        ptr1 = (ptr1 == nullptr) ? head2 : ptr1->next;
        ptr2 = (ptr2 == nullptr) ? head1 : ptr2->next;
    }

    return (ptr1 != nullptr) ? ptr1->data : -1;
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

int main() {
    cout << "========================================\n";
    cout << "    FIND MERGE POINT OF TWO LISTS\n";
    cout << "========================================\n";

    SinglyLinkedListNode* head1 = nullptr;
    SinglyLinkedListNode* tail1 = nullptr;
    SinglyLinkedListNode* head2 = nullptr;
    SinglyLinkedListNode* tail2 = nullptr;
    SinglyLinkedListNode* commonHead = nullptr;
    SinglyLinkedListNode* commonTail = nullptr;

    int n1, n2, nCommon;

    cout << "Enter number of nodes exclusive to List 1: ";
    cin >> n1;
    cout << "Enter " << n1 << " elements for List 1 before merge:\n";
    for (int i = 0; i < n1; i++) {
        int val;
        cin >> val;
        insertNode(head1, tail1, val);
    }

    cout << "\nEnter number of nodes exclusive to List 2: ";
    cin >> n2;
    cout << "Enter " << n2 << " elements for List 2 before merge:\n";
    for (int i = 0; i < n2; i++) {
        int val;
        cin >> val;
        insertNode(head2, tail2, val);
    }

    cout << "\nEnter number of shared common nodes starting from the merge point: ";
    cin >> nCommon;
    cout << "Enter " << nCommon << " elements for common merged segment:\n";
    for (int i = 0; i < nCommon; i++) {
        int val;
        cin >> val;
        insertNode(commonHead, commonTail, val);
    }

    if (tail1 != nullptr) {
        tail1->next = commonHead;
    } else {
        head1 = commonHead;
    }

    if (tail2 != nullptr) {
        tail2->next = commonHead;
    } else {
        head2 = commonHead;
    }

    int mergeVal = findMergeNode(head1, head2);

    cout << "\n---------------- RESULT ----------------\n";
    cout << "Merge Point Node Data: " << mergeVal << "\n";

    return 0;
}
