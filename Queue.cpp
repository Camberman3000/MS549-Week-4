
#include <iostream>
using namespace std;
   

// Node structure for the doubly-linked list
struct QueueNode {
    int data;
    QueueNode* prev;
    QueueNode* next;

    QueueNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Class for Queue implemented as a doubly-linked list
class Queue {
private:
    QueueNode* front; // Pointer to the front of the queue
    QueueNode* rear;  // Pointer to the rear of the queue

public:
    // Constructor
    Queue() : front(nullptr), rear(nullptr) {}

    // Destructor to free allocated memory
    ~Queue() {
        while (front) {
            QueueNode* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Enqueue operation
    void enqueue(int value) {
        QueueNode* newNode = new QueueNode(value);
        if (!rear) { // Queue is empty
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        cout << "Enqueued: " << value << '\n';
    }

    // Dequeue operation
    int dequeue() {
        if (!front) { // Queue is empty
            cout << "Queue is empty. Cannot dequeue." << '\n';
            return -1;
        }
        QueueNode* temp = front;
        int value = temp->data;
        front = front->next;
        if (front) {
            front->prev = nullptr;
        }
        else {
            rear = nullptr; // Queue is now empty
        }
        delete temp;
        cout << "Dequeued: " << value << '\n';
        return value;
    }

    // Display the contents of the queue
    void display() const {
        if (!front) {
            cout << "Queue is empty." << '\n';
            return;
        }
        QueueNode* temp = front;
        cout << "Queue Size: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << '\n';
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return front == nullptr;
    }
};

 