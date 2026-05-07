#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v): data (v), next (NULL) {}
};

//----- Stack
struct Stack {
    Node* top = NULL;

    void push(int x) {
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
    }

    void pop() {
        if (!top) {
            cout << "Stack Empty\n";
            return;
        }
        Node* del = top;
        top = top->next;
        cout << "Popped: " << del->data << endl;
        delete del;
    }

    void peek() {
        if (!top) cout << "Stack Empty\n";
        else cout << "Top: " << top->data << endl;
    }
};

//----- Circular Queue
struct CQueue {
    Node* front = NULL;
    Node* rear = NULL;

    void enqueue (int x) {
        Node* temp = new Node(x);
        if (!front) {
            front = rear = temp;
            rear->next = front;
        } else {
            rear->next = temp;
            rear = temp;
            rear->next = front;
        }
    }

    void dequeue() {
        if (!front) {
            cout << "Queue Empty\n";
            return;
        }
        if (front == rear) {
            cout << "Dequeued: " << front->data << endl;
            delete front;
            front = rear = NULL;
        } else {
            Node* del = front;
            cout << "Dequeued: " << del->data << endl;
            front = front->next;
            rear->next = front;
            delete del;
        }
    }

    void display() {
        if (!front) {
            cout << "Queue Empty\n";
            return;
        }
        Node* temp = front;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.peek();
    s.pop(); s.pop(); s.pop(); s.pop();
    cout << "---\n";
    CQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    return 0;
}
