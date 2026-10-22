/*(c) Imagine we have k computers connected in a circle.
Only one computer at a time can send a message.
To control this, they use a special object called a token that keeps moving from one computer to the next in the circle.

• If a computer has no message, it just passes the token to the next computer.

• If a computer has a message and it gets the token, it attaches the message to the token and sends it forward in the circle.

• The token keeps moving until it reaches the receiver computer. The receiver takes the message out.

• After that, the token becomes free again and continues to move in the circle for future use.

Select proper data structure from non-continuous memory allocation to solve the above problem.*/

 #include <iostream>
#include <string>
using namespace std;

struct Node
{
    int computer;
    string message;
    Node* next;
};

Node* head = NULL;

// Insert a computer
void insertComputer(int computer)
{
    Node* newNode = new Node;

    newNode->computer = computer;
    newNode->message = "";

    // First computer
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        Node* temp = head;

        // Find last node
        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }
}

// Display computers
void display()
{
    if (head == NULL)
        return;

    Node* temp = head;

    do
    {
        cout << "Computer " << temp->computer << endl;
        temp = temp->next;

    } while (temp != head);
}

// Send message
void sendMessage(Node*& token, int sender,
                 int receiver, string msg)
{
    Node* temp = token;

    // Find sender
    while (temp->computer != sender)
    {
        temp = temp->next;

        // Complete circle without finding sender
        if (temp == token)
        {
            cout << "Sender not found\n";
            return;
        }
    }

    // Move token until sender gets it
    token = temp;

    cout << "\nToken reached Computer "
         << sender << endl;

    // Attach message
    token->message = msg;

    cout << "Computer " << sender
         << " attaches message: "
         << msg << endl;

    // Move token until receiver
    while (token->computer != receiver)
    {
        cout << "Token moves from Computer "
             << token->computer << " to Computer "
             << token->next->computer << endl;

        token = token->next;
    }

    // Receiver removes message
    cout << "Computer " << receiver
         << " received message: "
         << token->message << endl;

    token->message = "";

    cout << "Message removed.\n";

    // Token becomes free
    token = token->next;

    cout << "Free token moves to Computer "
         << token->computer << endl;
}

int main()
{
    // Create computers
    insertComputer(1);
    insertComputer(2);
    insertComputer(3);
    insertComputer(4);
    insertComputer(5);

    cout << "Computers in Token Ring:\n";
    display();

    // Token initially at Computer 1
    Node* token = head;

    // Send message from C2 to C5
    sendMessage(token, 2, 5,
                "Hello Computer 5");

    return 0;
}