/*
================================================================================
Sample Experiment
Aim: To implement the operations (insert, insert after, insert before, 
     delete after, delete before and display the whole link list).
Tools/Apparatus: Turbo C/C++ / GNU C++

Standard Procedures:
1) Generate the class for Node of Link list
2) Create the constructor in this class to initialize the Node of Link list
3) Create the implementation class for implementing link list operations:
   - add_LinkListNode(int d): Insert at end
   - delete_LinkListNode(int delval): Delete node with specified value
   - delete_after(int val): Delete node after the specified value
   - delete_before(int val): Delete node before the specified value
   - insert_after(int val, int newval): Insert new node after specified value
   - insert_before(int val, int newval): Insert new node before specified value
   - display(): Display all node values
================================================================================
*/

#include <iostream>
using namespace std;

// Class representing a node in the singly linked list
class LinkListNode {
public:
    int data;
    LinkListNode *link;

    LinkListNode(int val) {
        data = val;
        link = NULL;
    }
};

// Implementation class for singly linked list operations
class ImpLinkListNode {
public:
    LinkListNode *first; // Head pointer of the linked list

    ImpLinkListNode() {
        first = NULL;
    }

    // Add node at the end of the linked list
    void add_LinkListNode(int d) {
        LinkListNode *l = new LinkListNode(d);
        if (first == NULL) {
            first = l;
        } else {
            LinkListNode *p = first;
            while (p->link != NULL) {
                p = p->link;
            }
            p->link = l;
        }
        cout << "Node with value " << d << " inserted at end.\n";
    }

    // Delete node whose value is specified
    void delete_LinkListNode(int delval) {
        if (first == NULL) {
            cout << "List is empty.\n";
            return;
        }

        if (first->data == delval) {
            LinkListNode *temp = first;
            first = first->link;
            delete temp;
            cout << "Node with value " << delval << " deleted.\n";
            return;
        }

        LinkListNode *p = first;
        LinkListNode *prev = NULL;
        while (p != NULL && p->data != delval) {
            prev = p;
            p = p->link;
        }

        if (p == NULL) {
            cout << "Node with value " << delval << " not found in the list.\n";
            return;
        }

        prev->link = p->link;
        delete p;
        cout << "Node with value " << delval << " deleted.\n";
    }

    // Delete node after a specified value
    void delete_after(int LinkListNodeval) {
        LinkListNode *p = first;
        while (p != NULL && p->data != LinkListNodeval) {
            p = p->link;
        }

        if (p == NULL) {
            cout << "Node with value " << LinkListNodeval << " not found.\n";
            return;
        }

        if (p->link == NULL) {
            cout << "No node exists after value " << LinkListNodeval << " to delete.\n";
            return;
        }

        LinkListNode *toDelete = p->link;
        p->link = toDelete->link;
        cout << "Node with value " << toDelete->data << " (after " << LinkListNodeval << ") deleted.\n";
        delete toDelete;
    }

    // Delete node before a specified value
    void delete_before(int LinkListNodeval) {
        if (first == NULL || first->link == NULL) {
            cout << "Cannot delete before: list has fewer than 2 elements.\n";
            return;
        }

        if (first->link->data == LinkListNodeval) {
            LinkListNode *temp = first;
            first = first->link;
            cout << "Node with value " << temp->data << " (before " << LinkListNodeval << ") deleted.\n";
            delete temp;
            return;
        }

        LinkListNode *prev = NULL;
        LinkListNode *curr = first;

        while (curr->link != NULL && curr->link->data != LinkListNodeval) {
            prev = curr;
            curr = curr->link;
        }

        if (curr->link == NULL) {
            cout << "Node with value " << LinkListNodeval << " not found or has no preceding node.\n";
            return;
        }

        prev->link = curr->link;
        cout << "Node with value " << curr->data << " (before " << LinkListNodeval << ") deleted.\n";
        delete curr;
    }

    // Insert new node after specified value
    void insert_after(int LinkListNodeval, int newval) {
        LinkListNode *p = first;
        while (p != NULL && p->data != LinkListNodeval) {
            p = p->link;
        }

        if (p == NULL) {
            cout << "Node with value " << LinkListNodeval << " not found.\n";
            return;
        }

        LinkListNode *newLinkListNode = new LinkListNode(newval);
        newLinkListNode->link = p->link;
        p->link = newLinkListNode;
        cout << "Node " << newval << " inserted after " << LinkListNodeval << ".\n";
    }

    // Insert new node before specified value
    void insert_before(int LinkListNodeval, int newval) {
        if (first == NULL) {
            cout << "List is empty.\n";
            return;
        }

        if (first->data == LinkListNodeval) {
            LinkListNode *newNode = new LinkListNode(newval);
            newNode->link = first;
            first = newNode;
            cout << "Node " << newval << " inserted before " << LinkListNodeval << ".\n";
            return;
        }

        LinkListNode *p = first;
        LinkListNode *prev = NULL;
        while (p != NULL && p->data != LinkListNodeval) {
            prev = p;
            p = p->link;
        }

        if (p == NULL) {
            cout << "Node with value " << LinkListNodeval << " not found.\n";
            return;
        }

        LinkListNode *newLinkListNode = new LinkListNode(newval);
        newLinkListNode->link = p;
        prev->link = newLinkListNode;
        cout << "Node " << newval << " inserted before " << LinkListNodeval << ".\n";
    }

    // Display all nodes in the linked list
    void display() {
        if (first == NULL) {
            cout << "List is empty.\n";
            return;
        }

        cout << "Linked List: ";
        LinkListNode *p = first;
        while (p != NULL) {
            cout << p->data;
            if (p->link != NULL) cout << " -> ";
            p = p->link;
        }
        cout << " -> NULL\n";
    }
};

int main() {
    ImpLinkListNode list;
    int choice, val, target;

    cout << "========================================\n";
    cout << "   SINGLY LINKED LIST (SAMPLE EXP)\n";
    cout << "========================================\n";

    while (true) {
        cout << "\n---------------- MENU ----------------\n";
        cout << "1. Insert at End\n";
        cout << "2. Insert After a Value\n";
        cout << "3. Insert Before a Value\n";
        cout << "4. Delete a Value\n";
        cout << "5. Delete After a Value\n";
        cout << "6. Delete Before a Value\n";
        cout << "7. Display List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice (1-8): ";
        if (!(cin >> choice)) break;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                list.add_LinkListNode(val);
                break;
            case 2:
                cout << "Enter existing target value: ";
                cin >> target;
                cout << "Enter new value to insert after " << target << ": ";
                cin >> val;
                list.insert_after(target, val);
                break;
            case 3:
                cout << "Enter existing target value: ";
                cin >> target;
                cout << "Enter new value to insert before " << target << ": ";
                cin >> val;
                list.insert_before(target, val);
                break;
            case 4:
                cout << "Enter value to delete: ";
                cin >> val;
                list.delete_LinkListNode(val);
                break;
            case 5:
                cout << "Enter target value: ";
                cin >> target;
                list.delete_after(target);
                break;
            case 6:
                cout << "Enter target value: ";
                cin >> target;
                list.delete_before(target);
                break;
            case 7:
                list.display();
                break;
            case 8:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please choose 1-8.\n";
        }
    }

    return 0;
}
