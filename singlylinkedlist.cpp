/*
Question:
Develop the program to solve the following situation using singly linked list.

Two employees, Alice and Bob, live in different towns and travel separately
to their common office. Their travel paths are different at the start but
merge at some point.

Write a program to find the node where the two singly linked lists merge.
*/

#include <iostream>
using namespace std;

struct Node
{
    string data;
    Node *next;
};

Node* createNode(string value)
{
    Node *temp = new Node;
    temp->data = value;
    temp->next = NULL;
    return temp;
}

// Count nodes in a linked list
int countNodes(Node *head)
{
    int count = 0;

    while(head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}

// Find merge point
Node* findMergePoint(Node *head1, Node *head2)
{
    int c1 = countNodes(head1);
    int c2 = countNodes(head2);

    int diff;

    if(c1 > c2)
    {
        diff = c1 - c2;

        while(diff--)
            head1 = head1->next;
    }
    else
    {
        diff = c2 - c1;

        while(diff--)
            head2 = head2->next;
    }

    while(head1 != NULL && head2 != NULL)
    {
        if(head1 == head2)
            return head1;

        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main()
{
    // Common Path
    Node *highway1 = createNode("Highway 1");
    Node *highway2 = createNode("Highway 2");
    Node *office = createNode("Office");

    highway1->next = highway2;
    highway2->next = office;

    // Alice Path
    Node *alice = createNode("Town A");
    alice->next = createNode("Road X");
    alice->next->next = createNode("Road Y");
    alice->next->next->next = highway1;

    // Bob Path
    Node *bob = createNode("Town B");
    bob->next = createNode("Street M");
    bob->next->next = highway1;

    Node *merge = findMergePoint(alice, bob);

    if(merge != NULL)
        cout << "Merge Point : " << merge->data;
    else
        cout << "No Merge Point";

    return 0;
}