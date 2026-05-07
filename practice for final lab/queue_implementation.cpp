#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;
    int front, rear, capacity;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int x) {
        if (rear == capacity - 1) {
            cout << "Queue is full\n";
            return;
        }
        if (front == -1) front = 0; // first element
        rear++;
        arr[rear] = x;
        cout << x << " added to queue\n";
    }

    void deque() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
            return;
        }
        cout << arr[front] << " removed from queue\n";
        front++;
    }

    int peak() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    bool isempty() {
        return (front == -1 || front > rear);
    }

    int size() {
        if (front == -1) return 0;
        return rear - front + 1;
    }
};

int main() {
    Queue q(5); // capacity = 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peak() << endl;

    q.deque();
    q.deque();

    cout << "Front element: " << q.peak() << endl;

    cout << "Queue size: " << q.size() << endl;

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70); // should show "Queue is full"

    return 0;
}
