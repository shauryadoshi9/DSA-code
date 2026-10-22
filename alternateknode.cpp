/*
Question:
Write a C program to reverse every alternate k nodes of a singly linked list.

Given a singly linked list and an integer k, reverse the first k nodes,
skip the next k nodes, and then again reverse the next k nodes,
and so on until the end of the list.

Example:
Input:
1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 → 9
k = 3

Output:
3 → 2 → 1 → 4 → 5 → 6 → 9 → 8 → 7
*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* reverseAlternateK(struct Node *head,int k)
{
    if(head==NULL)
        return NULL;

    struct Node *current=head;
    struct Node *prev=NULL;
    struct Node *next=NULL;

    int count=0;

    // Reverse first k nodes
    while(current!=NULL && count<k)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        count++;
    }

    // Connect reversed part with skipped part
    head->next=current;

    // Skip next k nodes
    count=0;

    while(current!=NULL && count<k-1)
    {
        current=current->next;
        count++;
    }

    // Recursive call
    if(current!=NULL)
        current->next=reverseAlternateK(current->next,k);

    return prev;
}

void insert(struct Node **head,int data)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));

    newNode->data=data;
    newNode->next=NULL;

    if(*head==NULL)
    {
        *head=newNode;
        return;
    }

    struct Node *temp=*head;

    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=newNode;
}

void display(struct Node *head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}

int main()
{
    struct Node *head=NULL;

    for(int i=1;i<=9;i++)
        insert(&head,i);

    head=reverseAlternateK(head,3);

    display(head);

    return 0;
}