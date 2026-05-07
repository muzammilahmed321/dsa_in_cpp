#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
int data;
Node* Next;
Node(int data) {
this->data = data;
this->Next = NULL;
    }
};

class linklist {
private:
    Node* head;

public:
    linklist() {
        head = NULL;
    }
void insert(int data) {
Node* newNode = new Node(data);
if (head == NULL) {
head = newNode;
} else {
Node* temp = head;
while (temp->Next != NULL) {
temp = temp->Next;
}
temp->Next = newNode;
}
}

void deleteDuplicate() {
Node* current = head;
while (current != NULL && current->Next != NULL) {
if (current->data == current->Next->data) {
Node* duplicate = current->Next;
current->Next = duplicate->Next;
delete duplicate;
} else {
current = current->Next;
}
    }
    }

void display() {
Node* temp = head;
while (temp != NULL) {
cout << temp->data << "->";
temp = temp->Next;
        }
cout << "NULL" << endl;
    }
};

int main() {
linklist list;
vector<int> values = {1, 1, 2, 3, 3, 4, 4};

for (int val : values) {
list.insert(val);
    }

cout << "Original list with duplicates:\n";
list.display();

list.deleteDuplicate();

cout << "List after removing duplicates:\n";
list.display();

return 0;
}
