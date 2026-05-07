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
            head = newNode;   // update head
        }
    }

    void push_back(int val) {
        node* newNode = new node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;   // update tail
        }
    }

    void pop_front() {
        if (head == NULL) {
            cout << "dll is empty\n";
            return;
        }
        node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            // list became empty
            tail = NULL;
        }
        delete temp;
    }
void pop_back(){
node* temp=tail;
tail=tail->prev;
if(tail!=NULL){
tail->prev=NULL;

}
temp->prev=NULL;
delete temp;
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
    dll.pop_back();   // popback
    dll.print();
}
