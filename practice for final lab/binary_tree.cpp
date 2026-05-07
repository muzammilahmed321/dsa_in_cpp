#include <iostream>
#include<algorithm>
#include <queue>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

// Binary tree class
class Binary {
private:
    Node* root;

public:
    Binary() {
        root = nullptr;
    }

    // Level-order insert to maintain complete binary tree
    void insert(int data) {
        Node* newNode = new Node(data);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr->left == nullptr) {
                curr->left = newNode;
                return;
            } else {
                q.push(curr->left);
            }

            if (curr->right == nullptr) {
                curr->right = newNode;
                return;
            } else {
                q.push(curr->right);
            }
        }
    }

    // In-order traversal
    void inOrder(Node* node) {
        if (node == nullptr) return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    // Pre-order traversal
    void preOrder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    // Post-order traversal
    void postOrder(Node* node) {
        if (node == nullptr) return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }

    // Helper functions to call traversals without passing root
    void inOrder() { inOrder(root); }
    void preOrder() { preOrder(root); }
    void postOrder() { postOrder(root); }
    bool search(int key){
        if(root==NULL){ return false;}
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){

            Node* curr=q.front();
            q.pop();
            if(curr->data==key){ return true;}
            if(curr->left!=NULL){
                q.push(curr->left);
            }
             if(curr->right!=NULL){
                q.push(curr->right);
            }

    }
    return false;
        }
        bool ismiror(Node *t1, Node *t2){
        if(!t1&&!t2) return true;
        if(!t1||!t2) return false;
        if(t1->data==t2->data){
           if( ismiror(t1->left,t2->right)&& ismiror(t1->right,t2->left) ){return true;}

        }
        return false;
        }
        bool issymetric(Node *root){
        if(!root){
            return true;
        }
        return ismiror(root->left,root->right);
        }
        bool issymetric(){
        issymetric(root);
        }
        int check_hight(Node* root){
        if(root==NULL) return 0;
        int left_hight=check_hight(root->left);
        if(left_hight==-1) return -1;
        int right_hight=check_hight(root->right);
            if(right_hight==-1) return -1;
                if(abs(left_hight-right_hight)>1) return -1;
            return max(left_hight,right_hight)+1;

        }
        bool isbalance(){
        return check_hight(root)!=-1;
        }

};

// Main function
int main() {
    Binary bt;

    // Insert nodes
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);
    bt.insert(6);
    bt.insert(7);

    // Traversals
    cout << "In-order traversal: ";
    bt.inOrder();
    cout << endl;

    cout << "Pre-order traversal: ";
    bt.preOrder();
    cout << endl;

    cout << "Post-order traversal: ";
    bt.postOrder();
    cout << endl;
cout << "binary search ";
    cout<<bt.search(5);
    cout << endl;
  cout<<bt.issymetric();
  cout<<bt.isbalance();


    return 0;
}


