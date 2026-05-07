#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

class circularlist {
    node* head;
    node* tail;

public:
    circularlist() {
        head = tail = NULL;
    }

    // Insert at head
    void insert_at_head(int val) {
        node* newNode = new node(val);
        if (head == NULL) {
            head = tail = newNode;
            tail->next = head; // circular link
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head; // maintain circularity
        }
    }

    // Insert at tail
    void insert_at_tail(int val) {
        node* newNode = new node(val);
        if (head == NULL) {
            head = tail = newNode;
            tail->next = head; // circular link
        } else {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Display list
    void display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)" << endl;
    }
};

int main() {
    circularlist cll;

    // Insert at head
    cll.insert_at_head(1);
    cll.insert_at_head(2);
    cll.insert_at_head(3);

    cout << "List after insert_at_head: ";
    cll.display();

    // Insert at tail
    cll.insert_at_tail(10);
    cll.insert_at_tail(20);

    cout << "List after insert_at_tail: ";
    cll.display();

    return 0;
}
