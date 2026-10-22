
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    int height;
};

// Get height of a node
int height(Node* node)
{
    if (node == NULL)
        return 0;

    return node->height;
}

// Get balance factor
int getBalance(Node* node)
{
    if (node == NULL)
        return 0;

    return height(node->left) - height(node->right);
}

// Create a new node
Node* createNode(int value)
{
    Node* newNode = new Node();

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;

    return newNode;
}

// Right Rotation (LL Case)
Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

// Left Rotation (RR Case)
Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

// Insert a node into AVL Tree
Node* insert(Node* node, int value)
{
    // 1. Normal BST insertion
    if (node == NULL)
        return createNode(value);

    if (value < node->data)
        node->left = insert(node->left, value);

    else if (value > node->data)
        node->right = insert(node->right, value);

    else
        return node;  // Duplicate values not allowed

    // 2. Update height
    node->height = 1 + max(height(node->left),
                           height(node->right));

    // 3. Calculate balance factor
    int balance = getBalance(node);

    // 4. Check four cases

    // LL Case
    if (balance > 1 && value < node->left->data)
        return rightRotate(node);

    // RR Case
    if (balance < -1 && value > node->right->data)
        return leftRotate(node);

    // LR Case
    if (balance > 1 && value > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL Case
    if (balance < -1 && value < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Inorder Traversal
void inorder(Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Main function
int main()
{
    Node* root = NULL;

    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 28);
    root = insert(root, 40);

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}
