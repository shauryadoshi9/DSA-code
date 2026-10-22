#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

// Insert at beginning
void insertBeginning(Node*& head, int value)
{
    Node* newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Insert at end
void insertEnd(Node*& head, int value)
{
    Node* newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

// Delete from beginning
void deleteBeginning(Node*& head)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    if (head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    Node* deleteNode = head;

    head = head->next;
    temp->next = head;

    delete deleteNode;
}

// Display
void display(Node* head)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    while (temp != head);

    cout << endl;
}

int main()
{
    Node* head = NULL;

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);

    cout << "Circular Linked List: ";
    display(head);

    insertBeginning(head, 5);

    cout << "After inserting 5 at beginning: ";
    display(head);

    insertEnd(head, 40);

    cout << "After inserting 40 at end: ";
    display(head);

    deleteBeginning(head);

    cout << "After deleting first node: ";
    display(head);

    return 0;
}