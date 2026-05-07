#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear;
    int size;
    int *arr;

public:
    CircularQueue(int s) {
        size = s;
        arr = new int[size];
        front = rear = -1;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isempty() {
        return (front == -1);
    }

    bool isfull() {
        return ((rear + 1) % size == front);
    }

    void enqueue(int value) {
        if (isfull()) {
            cout << "Queue is FULL\n";
            return;
        }

        if (isempty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = value;
        cout << value << " is enqueued\n";
    }

    void dequeue() {
        if (isempty()) {
            cout << "Queue is EMPTY\n";
            return;
        }

        cout << arr[front] << " is dequeued\n";

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    int peek() {
        if (isempty()) {
            cout << "Queue is EMPTY\n";
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isempty()) {
            cout << "Queue is EMPTY\n";
            return;
        }

        cout << "Queue elements: ";
        int i = front;

        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {

    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    q.enqueue(60);
    q.enqueue(70);
    q.display();

    return 0;
}
