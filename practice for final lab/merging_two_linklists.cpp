#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        next = prev = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = tail = NULL;
    }

    // Insert at end
    void pushBack(int data) {
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Concatenate another list to this one
    void concatenate(DoublyLinkedList &other) {
        if (other.head == NULL) return; // other is empty
        if (head == NULL) { // this list empty
            head = other.head;
            tail = other.tail;
            return;
        }

        tail->next = other.head;
        other.head->prev = tail;
        tail = other.tail;
    }

    // Sort in descending order
    void sortDescending() {
        if (head == NULL) return;

        for (Node* i = head; i->next != NULL; i = i->next) {
            for (Node* j = i->next; j != NULL; j = j->next) {
                if (i->data < j->data) {
                    int temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
    }

    // Display list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    DoublyLinkedList L, M, N;

    // List L: even numbers 2–10
    for (int i = 2; i <= 10; i += 2)
        L.pushBack(i);

    // List M: odd numbers 1–9
    for (int i = 1; i <= 9; i += 2)
        M.pushBack(i);

    cout << "List L (Even): ";
    L.display();

    cout << "List M (Odd): ";
    M.display();

    // Create N by concatenating both lists
    N.concatenate(L);
    N.concatenate(M);

    cout << "List N (Concatenated): ";
    N.display();

    // Sort N in descending order
    N.sortDescending();

    cout << "List N After Sorting (Descending): ";
    N.display();

    return 0;
}
