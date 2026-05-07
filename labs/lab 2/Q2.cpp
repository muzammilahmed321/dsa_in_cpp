#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node (int val): data (val), next (NULL) {}
};

Node* mergeTwoLists (Node* list1, Node* list2) {
    Node dummy(0);
    Node* tail = &dummy;
    while (list1 && list2) {
        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    if (list1) tail->next = list1;
    else tail->next = list2;
    return dummy.next;
}

Node* getMiddle (Node* head) {
    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* sortList(Node* head) {
    if (!head || !head->next) return head;
    Node* mid = getMiddle (head);
    Node* rightHalf = mid->next;
    mid->next = NULL;
    Node* leftSorted = sortList(head);
    Node* rightSorted = sortList(rightHalf);
    return mergeTwoLists (leftSorted, rightSorted);
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = new Node (4);
    head->next = new Node (2);
    head->next->next = new Node(1);
    head->next->next->next = new Node (3);
    cout << "Original List: ";
    printList(head);
    head = sortList(head);
    cout << "Sorted List: ";
    printList(head);
    return 0;
}
