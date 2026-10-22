#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preorder(Node* root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Preorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    return 0;
}

/*#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// ITERATIVE PREORDER
void preorder(Node* root)
{
    if (root == NULL)
        return;

    stack<Node*> s;
    s.push(root);

    while (!s.empty())
    {
        Node* temp = s.top();
        s.pop();

        cout << temp->data << " ";

        if (temp->right != NULL)
            s.push(temp->right);

        if (temp->left != NULL)
            s.push(temp->left);
    }
}

// ITERATIVE INORDER
void inorder(Node* root)
{
    stack<Node*> s;
    Node* temp = root;

    while (temp != NULL || !s.empty())
    {
        while (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }

        temp = s.top();
        s.pop();

        cout << temp->data << " ";

        temp = temp->right;
    }
}

// ITERATIVE POSTORDER
void postorder(Node* root)
{
    if (root == NULL)
        return;

    stack<Node*> s1, s2;

    s1.push(root);

    while (!s1.empty())
    {
        Node* temp = s1.top();
        s1.pop();

        s2.push(temp);

        if (temp->left != NULL)
            s1.push(temp->left);

        if (temp->right != NULL)
            s1.push(temp->right);
    }

    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int main()
{
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Preorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    return 0;
}*/