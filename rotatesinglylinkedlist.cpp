/*
Question:
Develop the following problem using singly linked list.

A company has a list of employees scheduled to work in a cyclic shift pattern.

Rotate the employee list by k positions to the right.

Example

A -> B -> C -> D -> E

k = 2

Output

D -> E -> A -> B -> C
*/

#include<iostream>
using namespace std;

struct Node
{
    char data;
    Node *next;
};

Node* createNode(char x)
{
    Node *temp=new Node;

    temp->data=x;
    temp->next=NULL;

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

Node* rotate(Node *head,int k)
{
    if(head==NULL || k==0)
        return head;

    int count=1;

    Node *last=head;

    while(last->next!=NULL)
    {
        count++;
        last=last->next;
    }

    k=k%count;

    if(k==0)
        return head;

    last->next=head;

    int steps = count-k;

    Node *temp=head;

    for(int i=1;i<steps;i++)
    {
        temp=temp->next;
    }


    head=temp->next;

    temp->next=NULL;

    return head;
}

int main()
{
    Node *head=createNode('A');

    head->next=createNode('B');
    head->next->next=createNode('C');
    head->next->next->next=createNode('D');
    head->next->next->next->next=createNode('E');

    int k;

    cout<<"Enter Rotation : ";
    cin>>k;

    head=rotate(head,k);

    cout<<"New Schedule : ";

    display(head);

    return 0;
}