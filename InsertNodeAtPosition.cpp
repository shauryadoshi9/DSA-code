/*
================================================================================
QUESTION: Insert a node at a specific position in a linked list
Platform: HackerRank (Data Structures -> Linked Lists)
Difficulty: Easy / Intermediate

Problem Statement:
Given the pointer to the head node of a linked list and an integer to insert at
a certain position, create a new node with the given integer as its attribute and
insert this node at the desired position. (0-based indexing).

Input Format:
- The first line contains an integer n, the number of elements in the linked list.
- Each of the next n lines contains an integer SinglyLinkedListNode[i].data.
- The next line contains an integer data, the data of the node that is to be inserted.
- The last line contains an integer position, the position at which the node is to be inserted.

Output Format:
- Print the updated linked list with the new node inserted at the specified position.
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

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);

    if (position == 0) {
        newNode->next = head;
        return newNode;
    }

    SinglyLinkedListNode* current = head;
    for (int i = 0; i < position - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current != nullptr) {
        newNode->next = current->next;
        current->next = newNode;
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
    SinglyLinkedListNode* head = nullptr;
    SinglyLinkedListNode* tail = nullptr;

    int n;
    cout << "Enter the number of elements in the linked list: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertNode(head, tail, val);
    }

    int data, position;
    cout << "Enter the data of the new node to insert: ";
    cin >> data;
    cout << "Enter the position at which to insert (0-indexed): ";
    cin >> position;

    head = insertNodeAtPosition(head, data, position);

    cout << "\nUpdated Linked List:\n";
    printList(head);

    return 0;
}
