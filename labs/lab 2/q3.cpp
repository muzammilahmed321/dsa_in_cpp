#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v): data (v), next (NULL) {}
};

Node* reverseList (Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* nxt;
    while (curr) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

bool isPalindrome (Node* head) {
    if (!head || !head->next) return true;
    Node* slow = head;
    Node* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* second = reverseList(slow->next);
    Node* p1 = head;
    Node* p2 = second;
    bool ok = true;
    while (p2) {
        if (p1->data != p2->data) { ok = false; break; }
        p1 = p1->next;
        p2 = p2->next;
    }
    slow->next = reverseList(second);
    return ok;
}

int main() {
    Node* h = new Node (1);
    h->next = new Node (2);
    h->next->next = new Node (2);
    h->next->next->next = new Node (1);
    cout << (isPalindrome (h)? "true": "false") << endl;
    return 0;
}
