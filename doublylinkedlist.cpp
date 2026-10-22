/*
Question:
Choose proper data structure to solve the following problem.

Soldier is running to current node having value "Start".

If the event is "hit":
Delete the previous node and the next node of the current node (if they exist).

If the event is "miss":
Insert a new node with value "Enemy" before and after the current node.
*/

#include<iostream>
#include<string>
using namespace std;

struct Node
{
    string data;
    Node *prev;
    Node *next;
};

Node* createNode(string value)
{
    Node *temp = new Node;
    temp->data = value;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

// Insert after current node
void insertAfter(Node *current, string value)
{
    Node *newNode = createNode(value);

    newNode->next = current->next;
    newNode->prev = current;

    if(current->next != NULL)
        current->next->prev = newNode;

    current->next = newNode;
}

// Insert before current node
Node* insertBefore(Node *head, Node *current, string value)
{
    Node *newNode = createNode(value);

    newNode->next = current;
    newNode->prev = current->prev;

    if(current->prev != NULL)
        current->prev->next = newNode;
    else
        head = newNode;

    current->prev = newNode;

    return head;
}

// Delete previous node
Node* deletePrevious(Node *head, Node *current)
{
    if(current->prev == NULL)
        return head;

    Node *temp = current->prev;

    if(temp->prev != NULL)
        temp->prev->next = current;
    else
        head = current;

    current->prev = temp->prev;

    delete temp;

    return head;
}

// Delete next node
void deleteNext(Node *current)
{
    if(current->next == NULL)
        return;

    Node *temp = current->next;

    current->next = temp->next;

    if(temp->next != NULL)
        temp->next->prev = current;

    delete temp;
}

void display(Node *head)
{
    while(head != NULL)
    {
        cout << head->data << " <-> ";
        head = head->next;
    }

    cout << "NULL";
}

int main()
{
    Node *head = createNode("A");

    Node *start = createNode("Start");
    Node *b = createNode("B");

    head->next = start;
    start->prev = head;

    start->next = b;
    b->prev = start;

    cout<<"Original List:\n";
    display(head);

    string event;

    cout<<"\n\nEnter event(hit/miss): ";
    cin>>event;

    if(event=="hit")
    {
        head = deletePrevious(head,start);
        deleteNext(start);
    }
    else if(event=="miss")
    {
        head = insertBefore(head,start,"Enemy");
        insertAfter(start,"Enemy");
    }

    cout<<"\nUpdated List:\n";
    display(head);

    return 0;
}