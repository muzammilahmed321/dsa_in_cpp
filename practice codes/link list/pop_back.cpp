#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* Next;
    Node(int val) {
        data = val;
        Next = NULL;
    }
};

class list {
    Node* Head;
    Node* Tail;
public:
    list() {
        Head = Tail = NULL;
    }
 v
    void push_front(int val) {
        Node* newNode = new Node(val);
        if (Head == NULL) {
            Head = Tail = newNode;
        } else {
            newNode->Next = Head;
            Head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (Head == NULL) {
            Head = Tail = newNode;
        } else {
            Tail->Next = newNode;
            Tail = newNode;
        }
    }

    void pop_front() {   // fixed: no parameter
        if (Head == NULL) {
            cout << "Linked list is empty\n";
            return;
        }
        Node* temp = Head;
        Head = Head->Next;   // fixed: use Head not head
        if (Head == NULL) {
            Tail = NULL; // list became empty
        }
        delete temp;
    }
    void pop_back(){
    if(Head==NULL){
        cout<<"ll is empty";
        return;

    }
    Node *temp=Head;
    while(temp->Next!=Tail){
        temp=temp->Next=NULL;
    }
    temp->Next=NULL;
    delete Tail;
    Tail=temp;

    }

    void printll() {
        Node* temp = Head;
        while (temp->Next != NULL) {
            cout << temp->data << " -> ";
            temp = temp->Next;
        }
        cout << "NULL" << endl;
    }

};

int main() {
    list ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);

    ll.push_back(4);
    ll.pop_front();
    ll.printll();
     ll.pop_back();
      ll.printll();

    return 0;
}

