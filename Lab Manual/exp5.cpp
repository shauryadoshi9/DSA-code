/*
================================================================================
EXPERIMENT - 5
Aim: Implement the Doubly Link-List.
Tools / Apparatus: O.S.: Microsoft Windows (any) / Linux / DOS
Packages: Turbo/Borland/GNU - C/C++

Procedure: 
1) Data type declaration as per given below:
   record Node {
       data // The data being stored in the node
       next // A reference to the next node; null for last node
       prev // A reference to the previous node; null for first node
   }
   record List {
       Node firstNode // points to first node of list; null for empty list
       Node lastNode  // points to last node of list; null for empty list
   }

2) Implement Insert before and Insert after function as per given below:
   Function insertAfter(List list, Node node, Node newNode)
       newNode.prev := node
       newNode.next := node.next
       if node.next == null
           list.lastNode := newNode
       else
           node.next.prev := newNode
       node.next := newNode

   Function insertBefore(List list, Node node, Node newNode)
       newNode.prev := node.prev
       newNode.next := node
       if node.prev is null
           list.firstNode := newNode
       else
           node.prev.next := newNode
       node.prev := newNode

3) Implement the remove function as per given below:
   Function remove(List list, Node node)
       if node.prev == null
           list.firstNode := node.next
       else
           node.prev.next := node.next
       if node.next == null
           list.lastNode := node.prev
       else
           node.next.prev := node.prev
       destroy node
================================================================================
*/

#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
struct Node {
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

// List structure tracking both first and last nodes
struct List {
    Node *firstNode;
    Node *lastNode;

    List() {
        firstNode = NULL;
        lastNode = NULL;
    }
};

// Function insertAfter as specified in procedure
void insertAfter(List &list, Node *node, Node *newNode) {
    if (node == NULL || newNode == NULL) return;

    newNode->prev = node;
    newNode->next = node->next;

    if (node->next == NULL) {
        list.lastNode = newNode;
    } else {
        node->next->prev = newNode;
    }
    node->next = newNode;
    cout << "Node " << newNode->data << " inserted after " << node->data << ".\n";
}

// Function insertBefore as specified in procedure
void insertBefore(List &list, Node *node, Node *newNode) {
    if (node == NULL || newNode == NULL) return;

    newNode->prev = node->prev;
    newNode->next = node;

    if (node->prev == NULL) {
        list.firstNode = newNode;
    } else {
        node->prev->next = newNode;
    }
    node->prev = newNode;
    cout << "Node " << newNode->data << " inserted before " << node->data << ".\n";
}

// Function remove as specified in procedure
void remove(List &list, Node *node) {
    if (node == NULL) return;

    if (node->prev == NULL) {
        list.firstNode = node->next;
    } else {
        node->prev->next = node->next;
    }

    if (node->next == NULL) {
        list.lastNode = node->prev;
    } else {
        node->next->prev = node->prev;
    }

    cout << "Node with value " << node->data << " removed.\n";
    delete node; // destroy node
}

// Helper function to append to the end of list
void append(List &list, int val) {
    Node *newNode = new Node(val);
    if (list.firstNode == NULL) {
        list.firstNode = newNode;
        list.lastNode = newNode;
        cout << "Node " << val << " inserted as first node.\n";
    } else {
        insertAfter(list, list.lastNode, newNode);
    }
}

// Helper function to search for a node by value
Node* findNode(const List &list, int val) {
    Node *curr = list.firstNode;
    while (curr != NULL) {
        if (curr->data == val) return curr;
        curr = curr->next;
    }
    return NULL;
}

// Function to display list forward
void displayForward(const List &list) {
    if (list.firstNode == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node *curr = list.firstNode;
    cout << "Forward:  NULL <-> ";
    while (curr != NULL) {
        cout << "[" << curr->data << "] <-> ";
        curr = curr->next;
    }
    cout << "NULL\n";
}

// Function to display list backward
void displayBackward(const List &list) {
    if (list.lastNode == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node *curr = list.lastNode;
    cout << "Backward: NULL <-> ";
    while (curr != NULL) {
        cout << "[" << curr->data << "] <-> ";
        curr = curr->prev;
    }
    cout << "NULL\n";
}

int main() {
    List myList;
    int choice, val, target;

    cout << "========================================\n";
    cout << "     DOUBLY LINKED LIST OPERATIONS\n";
    cout << "========================================\n";

    while (true) {
        cout << "\n---------------- MENU ----------------\n";
        cout << "1. Append Node at End\n";
        cout << "2. Insert After a Value\n";
        cout << "3. Insert Before a Value\n";
        cout << "4. Remove a Node\n";
        cout << "5. Display Forward\n";
        cout << "6. Display Backward\n";
        cout << "7. Exit\n";
        cout << "Enter your choice (1-7): ";
        if (!(cin >> choice)) break;

        switch (choice) {
            case 1:
                cout << "Enter value to append: ";
                cin >> val;
                append(myList, val);
                break;
            case 2:
                cout << "Enter existing target value: ";
                cin >> target;
                {
                    Node *node = findNode(myList, target);
                    if (node == NULL) {
                        cout << "Target node with value " << target << " not found.\n";
                    } else {
                        cout << "Enter new value to insert after " << target << ": ";
                        cin >> val;
                        insertAfter(myList, node, new Node(val));
                    }
                }
                break;
            case 3:
                cout << "Enter existing target value: ";
                cin >> target;
                {
                    Node *node = findNode(myList, target);
                    if (node == NULL) {
                        cout << "Target node with value " << target << " not found.\n";
                    } else {
                        cout << "Enter new value to insert before " << target << ": ";
                        cin >> val;
                        insertBefore(myList, node, new Node(val));
                    }
                }
                break;
            case 4:
                cout << "Enter value to remove: ";
                cin >> val;
                {
                    Node *node = findNode(myList, val);
                    if (node == NULL) {
                        cout << "Node with value " << val << " not found.\n";
                    } else {
                        remove(myList, node);
                    }
                }
                break;
            case 5:
                displayForward(myList);
                break;
            case 6:
                displayBackward(myList);
                break;
            case 7:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please choose 1-7.\n";
        }
    }

    return 0;
}
