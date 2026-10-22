/*
Question:
Each coach has a unique integer ID. You are given a doubly linked list
representing the train.

Coach1 <-> Coach2 <-> ... <-> Current <-> ... <-> CoachN

If the current coach number is even, detach the next coach (if it exists).

If the current coach number is odd, insert a new coach with ID = 999
just before the current coach.
*/

#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

Node* createNode(int x)
{
    Node *temp = new Node;
    temp->data = x;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

void display(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

Node* operation(Node *head,int currentID)
{
    Node *current=head;

    while(current!=NULL && current->data!=currentID)
        current=current->next;

    if(current==NULL)
        return head;

    // Even -> Delete next node
    if(current->data%2==0)
    {
        if(current->next!=NULL)
        {
            Node *temp=current->next;

            current->next=temp->next;

            if(temp->next!=NULL)
                temp->next->prev=current;

            delete temp;
        }
    }

    // Odd -> Insert 999 before current
    else
    {
        Node *newNode=createNode(999);

        newNode->next=current;
        newNode->prev=current->prev;

        if(current->prev!=NULL)
            current->prev->next=newNode;
        else
            head=newNode;

        current->prev=newNode;
    }

    return head;
}

int main()
{
    Node *head=createNode(1);

    Node *n2=createNode(2);
    Node *n3=createNode(3);
    Node *n4=createNode(4);
    Node *n5=createNode(5);

    head->next=n2;
    n2->prev=head;

    n2->next=n3;
    n3->prev=n2;

    n3->next=n4;
    n4->prev=n3;

    n4->next=n5;
    n5->prev=n4;

    int currentID;

    cout<<"Enter Current Coach ID : ";
    cin>>currentID;

    head=operation(head,currentID);

    cout<<"Updated Train : ";
    display(head);

    return 0;
}