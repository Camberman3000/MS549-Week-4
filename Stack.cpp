
#include <iostream>
using namespace std;

// Node structure for the doubly-linked list
struct StackNode {
    int data;
    StackNode* prev;
    StackNode* next;

    StackNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Class for Stack implemented as a doubly-linked list
class Stack {
private:
    StackNode* top; // Pointer to the top of the stack

public:
    /********************************* Begin ChatGPT Code #1 **********************************************/
    // Constructor
    Stack() : top(nullptr) {}

    // Destructor to free allocated memory
    ~Stack() {
        while (top) {
            StackNode* temp = top;
            top = top->prev;
            delete temp;
        }
    }
    /********************************* end ChatGPT Code #1 **********************************************/
    // Push operation
    void push(int value) {
        StackNode* newNode = new StackNode(value);
        if (!top) { // Stack is empty
            top = newNode;
        }
        else {
            /********************************* Begin ChatGPT Code #2 **********************************************/
            newNode->prev = top;
            /********************************* end ChatGPT Code #2 **********************************************/
            top->next = newNode;
            top = newNode;
        }
        cout << "Pushed: " << value << '\n';
    }

    // Pop operation
    int pop() {
        if (!top) { // Stack is empty
            cout << "Stack is empty. Cannot pop." << '\n';
            return -1;
        }
        StackNode* temp = top;
        int value = temp->data;
        top = top->prev;
        if (top) {
            top->next = nullptr;
        }
        delete temp;
        cout << "Popped: " << value << '\n';
        return value;
    }

    // Display the contents of the stack
    void display() const {
        if (!top) {
            cout << "Stack is empty." << '\n';
            return;
        }
        StackNode* temp = top;
        cout << "Stack (top to bottom): ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << '\n';
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top == nullptr;
    }
};
 