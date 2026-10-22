
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    bool leftThread;
    bool rightThread;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
        leftThread = true;
        rightThread = true;
    }
};

// Insert a value into the threaded BST
Node* insert(Node* root, int value)
{
    Node* newNode = new Node(value);

    // Case 1: Empty tree
    if (root == nullptr)
        return newNode;

    Node* current = root;

    while (true)
    {
        // Insert as left child
        if (value < current->data)
        {
            if (current->leftThread)
            {
                newNode->left = current->left;
                newNode->right = current;

                current->left = newNode;
                current->leftThread = false;

                break;
            }
            else
            {
                current = current->left;
            }
        }

        // Insert as right child
        else
        {
            if (current->rightThread)
            {
                newNode->left = current;
                newNode->right = current->right;

                current->right = newNode;
                current->rightThread = false;

                break;
            }
            else
            {
                current = current->right;
            }
        }
    }

    return root;
}

// Find the leftmost node
Node* leftMost(Node* node)
{
    if (node == nullptr)
        return nullptr;

    while (!node->leftThread)
        node = node->left;

    return node;
}

// Inorder traversal using threads
void inorder(Node* root)
{
    Node* current = leftMost(root);

    while (current != nullptr)
    {
        cout << current->data << " ";

        // If right pointer is a thread,
        // follow it to the inorder successor
        if (current->rightThread)
        {
            current = current->right;
        }
        else
        {
            // Otherwise, go to the leftmost node
            // in the right subtree
            current = leftMost(current->right);
        }
    }
}

int main()
{
    Node* root = nullptr;

    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}
