/*Write a C++ function to find an inorder successor of any node in a Binary Tree.*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* previous = NULL;
Node* successor = NULL;

void findSuccessor(Node* root, Node* target)
{
    if (root == NULL || successor != NULL)
        return;

    // LEFT
    findSuccessor(root->left, target);

    // ROOT
    if (previous == target)
    {
        successor = root;
        return;
    }

    previous = root;

    // RIGHT
    findSuccessor(root->right, target);
}

Node* getInorderSuccessor(Node* root, Node* target)
{
    previous = NULL;
    successor = NULL;

    findSuccessor(root, target);

    return successor;
}

int main()
{
    /*
             20
            /  \
          10    30
         /  \
        5   15
    */

    Node* root = new Node{20, NULL, NULL};

    root->left = new Node{10, NULL, NULL};
    root->right = new Node{30, NULL, NULL};

    root->left->left = new Node{5, NULL, NULL};
    root->left->right = new Node{15, NULL, NULL};

    Node* target = root->left;   // Node 10

    Node* ans = getInorderSuccessor(root, target);

    if (ans != NULL)
        cout << "Inorder Successor = "
             << ans->data << endl;
    else
        cout << "No inorder successor" << endl;

    return 0;
}