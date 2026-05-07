#include <iostream>
using namespace std;

class node {
public:
    node* next;
    node* prev;
    int data;

    node(int data) {
        this->data = data;
        this->next = this->prev = NULL;
    }
};

class circularlinklist {
private:
    node* tail;

public:
    circularlinklist() : tail(NULL) {}

    void insertatend(int data) {
        node* newNode = new node(data);

        if (tail == NULL) {
            tail = newNode;
            tail->next = tail;  // points to itself
        } else {
            newNode->next = tail->next;  // new node points to head
            tail->next = newNode;        // old tail points to new node
            tail = newNode;              // update tail
        }
    }

    void insertatfront(int data) {
        node* newNode = new node(data);

        if (tail == NULL) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;  // new node points to head
            tail->next = newNode;        // tail points to new head
            // head updated automatically (tail->next)
        }
    }

    void display() {
        if (tail == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        node* temp = tail->next;  // start from head
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail->next);

        cout << endl;
    }
};

int main() {
    circularlinklist l1;
    l1.insertatfront(10);
    l1.insertatend(20);
    l1.insertatend(30);
    l1.insertatfront(5);

    cout << "Circular linked list: ";
    l1.display();

    return 0;
}

