#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;

    // constructor
    node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class doubly_list {
    node* head;
    node* tail;
public:
    // constructor
    doubly_list() {
        head = tail = NULL;
    }

    void push_front(int val) {
        node* newNode = new node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;   // update head!
        }
    }
    void push_back(int val) {
        node* newNode = new node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;   // update head!
        }
    }




    void print() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    doubly_list dll;
    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);
    dll.print();
}
