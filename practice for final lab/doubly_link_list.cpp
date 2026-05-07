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

class doublelinklist {
private:
    node* tail;
    node* head;

public:
    doublelinklist() : tail(NULL) {}

    void pushback(int data) {
        node* newNode = new node(data);

        if (head == NULL) {
            head=tail = newNode;

        } else {
            newNode->prev =tail;  // new node points to head
            tail->next = newNode;        // old tail points to new node
            tail = newNode;              // update tail
        }
    }

    void pushfront(int data) {
        node* newNode = new node(data);

        if (head == NULL) {
            head=tail = newNode;

        } else {
            newNode->next = head;  // new node points to head
            head->prev = newNode;
            head=newNode;        // tail points to new head
            // head updated automatically (tail->next)
        }
    }
    void popback(int data){
    node *temp=tail;
    if(tail==NULL){
        return;
    }
    if(head==tail){
        delete head;
    }
    else{
        node* temp=tail;
        tail=tail->prev;
        if(tail!=NULL){
            tail->next=NULL;
            temp->prev=NULL;
            delete temp;
        }
    }

    }
  void popfront(int data){
    node *temp=tail;
    if(tail==NULL){
        return;
    }
    if(head==tail){
        delete head;
    }
    else{
        node* temp=head;
        head=head->prev;
        if(head!=NULL){
            head->next=NULL;
            head->prev=NULL;
            delete temp;
        }
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
    doublelinklist l1;

    l1.pushfront(1);
l1.pushfront(2);
l1.pushback(3);
l1.popback();

    cout << "doubly linked list: ";
    l1.display();

    return 0;
}



