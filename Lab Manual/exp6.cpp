/*
================================================================================
EXPERIMENT - 6
Aim: Implement the Binary Tree Traversal.
Tools / Apparatus: O.S.: Microsoft Windows (any) / Linux / DOS
Packages: Turbo/Borland/GNU - C/C++

Procedure: 
1) Make the structure of Binary Tree Traversal for integer numbers:
   struct node {
       int data;
       struct node* left;
       struct node* right;
   };

2) Implement inorder(), preorder() and postorder() traversal for it:
   Preorder:
   1) Visit the root.
   2) Traverse the left subtree.
   3) Traverse the right subtree.

   Inorder:
   1) Traverse the left subtree.
   2) Visit the root.
   3) Traverse the right subtree.

   Postorder:
   1) Traverse the left subtree.
   2) Traverse the right subtree.
   3) Visit the root.
================================================================================
*/

#include <iostream>
using namespace std;

// Binary tree node structure as specified in the manual
struct node {
    int data;
    struct node* left;
    struct node* right;

    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Preorder Traversal: Root -> Left -> Right
void preorder(struct node* root) {
    if (root == NULL) return;

    // 1) Visit the root
    cout << root->data << " ";

    // 2) Traverse the left subtree
    preorder(root->left);

    // 3) Traverse the right subtree
    preorder(root->right);
}

// Inorder Traversal: Left -> Root -> Right
void inorder(struct node* root) {
    if (root == NULL) return;

    // 1) Traverse the left subtree
    inorder(root->left);

    // 2) Visit the root
    cout << root->data << " ";

    // 3) Traverse the right subtree
    inorder(root->right);
}

// Postorder Traversal: Left -> Right -> Root
void postorder(struct node* root) {
    if (root == NULL) return;

    // 1) Traverse the left subtree
    postorder(root->left);

    // 2) Traverse the right subtree
    postorder(root->right);

    // 3) Visit the root
    cout << root->data << " ";
}

// Function to insert nodes in a Binary Search Tree manner dynamically
struct node* insertBST(struct node* root, int val) {
    if (root == NULL) {
        return new node(val);
    }
    if (val < root->data) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }
    return root;
}

int main() {
    cout << "========================================\n";
    cout << "      BINARY TREE TRAVERSALS\n";
    cout << "========================================\n";

    struct node* root = NULL;
    int n;

    cout << "Enter the number of nodes in the binary tree: ";
    cin >> n;

    cout << "Enter " << n << " node values:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cout << "  Node " << i + 1 << ": ";
        cin >> val;
        root = insertBST(root, val);
    }

    cout << "\n---------------- TRAVERSAL RESULTS ----------------\n";
    cout << "1. Preorder Traversal  (Root -> Left -> Right): ";
    preorder(root);
    cout << "\n";

    cout << "2. Inorder Traversal   (Left -> Root -> Right): ";
    inorder(root);
    cout << "\n";

    cout << "3. Postorder Traversal (Left -> Right -> Root): ";
    postorder(root);
    cout << "\n";

    return 0;
}
