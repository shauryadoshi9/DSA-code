/*
================================================================================
EXPERIMENT - 11 (LABWORK BEYOND CURRICULA 1)
Aim: Arrange words in dictionary order using Binary Search Tree In order Traversal.
Implement binary search tree for word representation and make in order traversal
for sorting in dictionary order.
Tools / Apparatus: O.S.: Microsoft Windows (any) / Linux / DOS
Packages: Turbo/Borland/GNU - C/C++

Procedure: 
Follow the following steps to arrange words in dictionary order using Binary Search Tree:
1) Generate the binary search tree node.
2) Insert each node in following order:
   If word in temporary node is less than the root node word then insert in left
   side to root.
   Else insert to right side.
3) Make the Inorder traversal and display the words. You will get in dictionary order.
================================================================================
*/

#include <iostream>
#include <string>
using namespace std;

// Step 1: Binary Search Tree node structure for words (without templates)
struct BSTNode {
    string word;
    BSTNode *left;
    BSTNode *right;

    BSTNode(string w) {
        word = w;
        left = NULL;
        right = NULL;
    }
};

// Binary Search Tree class
class WordBST {
private:
    BSTNode *root;

    // Step 2: Recursive insertion
    BSTNode* insertNode(BSTNode *node, const string &w) {
        if (node == NULL) {
            return new BSTNode(w);
        }

        // If word is less than root node word, insert in left subtree
        if (w < node->word) {
            node->left = insertNode(node->left, w);
        }
        // Else insert in right subtree
        else if (w > node->word) {
            node->right = insertNode(node->right, w);
        }
        return node;
    }

    // Step 3: Inorder traversal (Left -> Root -> Right)
    void inorderTraversal(BSTNode *node, int &count) {
        if (node == NULL) return;

        inorderTraversal(node->left, count);

        cout << "  " << ++count << ". " << node->word << "\n";

        inorderTraversal(node->right, count);
    }

    void destroyTree(BSTNode *node) {
        if (node == NULL) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    WordBST() {
        root = NULL;
    }

    ~WordBST() {
        destroyTree(root);
    }

    void insert(const string &w) {
        root = insertNode(root, w);
    }

    void displayDictionaryOrder() {
        if (root == NULL) {
            cout << "The tree is empty.\n";
            return;
        }
        int count = 0;
        inorderTraversal(root, count);
    }
};

int main() {
    WordBST wordTree;
    int n;

    cout << "=========================================================\n";
    cout << "   DICTIONARY ORDER USING BINARY SEARCH TREE (BST)\n";
    cout << "=========================================================\n";

    cout << "Enter the number of words to arrange: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of words must be positive.\n";
        return 0;
    }

    cout << "Enter " << n << " words:\n";
    for (int i = 0; i < n; i++) {
        string word;
        cout << "  Word " << i + 1 << ": ";
        cin >> word;
        wordTree.insert(word);
    }

    cout << "\nWords in Dictionary / Alphabetical Order (Inorder Traversal):\n";
    wordTree.displayDictionaryOrder();

    return 0;
}
