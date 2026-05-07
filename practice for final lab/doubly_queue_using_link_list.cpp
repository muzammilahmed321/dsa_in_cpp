#include <iostream>
using namespace std;

// Node class for doubly linked list
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = this->prev = NULL;
    }
};

class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() {
        front = rear = NULL;
    }

    void insertatfront(int data) {
        Node* newNode = new Node(data);
        if (front == NULL) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void insertatback(int data) {
        Node* newNode = new Node(data);
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    void popfront() {
        if (front == NULL) {
            cout << "Deque is empty.\n";
            return;
        }

        cout << "Deleted from front: " << front->data << endl;

        if (front == rear) {  // only one element
            delete front;
            front = rear = NULL;
        } else {
            Node* temp = front;
            front = front->next;
            front->prev = NULL;
            delete temp;
        }
    }

    void popback() {
        if (rear == NULL) {
            cout << "Deque is empty.\n";
            return;
        }

        cout << "Deleted from back: " << rear->data << endl;

        if (front == rear) {  // only one element
            delete rear;
            front = rear = NULL;
        } else {
            Node* temp = rear;
            rear = rear->prev;
            rear->next = NULL;
            delete temp;
        }
    }

    void display() {
        if (front == NULL) {
            cout << "Deque is empty.\n";
            return;
        }

        Node* temp = front;
        cout << "Deque elements (front → rear): ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    Deque dq;
    dq.insertatfront(1);
    dq.insertatback(2);
    dq.insertatfront(3);
    dq.display();

    dq.popfront();
    dq.popback();
    dq.display();

    dq.insertatback(4);
    dq.display();

    return 0;
}
