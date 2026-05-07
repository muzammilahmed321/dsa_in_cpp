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

class circularqueue {
private:
    node* front;
    node* rear;

public:
    circularqueue(){
    front=rear=NULL;
    }

    void inqueue(int data) {
        node* newNode = new node(data);

        if (front == NULL) {
            front=rear=newNode;
            rear->next=front;  // points to itself
        } else {
            rear->next = newNode;
            rear=newNode;
            newNode->next=front;

        }
    }
    void deque(){
    if(front==NULL){
        return;
    }
    if(front==rear){
        delete front;
    }
    else{
    node *temp=front;
    front=front->next;
        rear->next=front;
        delete temp;
    }

    };

    void display() {
        if (front == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        node* temp =front;  // start from head
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp !=front);

        cout << endl;
    }
};

int main() {
   circularqueue q1;
   q1.inqueue(1);
   q1.inqueue(2);
   q1.inqueue(3);

    cout << "Circular Queue: ";

    q1.deque();
    q1.display();
    return 0;
}
