#include <iostream>
#include <queue>
using namespace std;
class Node {
public:
int data;
Node* left;
Node* right;
Node(int value) {
data = value;
left = nullptr;
right = nullptr;
}
};
class BinaryTree {
private:
Node* root;
public:
BinaryTree() {
root = nullptr;
}
void insert(int data) {
Node* newNode = new Node(data);
if (root == nullptr) {
root = newNode;
return;
}
queue<Node*> q;
q.push(root);
while (!q.empty()) {
Node* current = q.front();
q.pop();
if (current->left == nullptr) {
current->left = newNode;
return;
} else {
q.push(current->left);
}
if (current->right == nullptr) {
current->right = newNode;
return;
} else {q.push(current->right);
}
}
}
void preOrder(Node* root){
if(root==NULL){
return;
}
cout<<root->data<<"->";
preOrder(root->left);
preOrder(root->right);
}
void preOrderTraversel(){
preOrder(root);
cout<<endl;
}
void postOrder(Node* root){
if(root==NULL){
return;
}
postOrder(root->left);
postOrder(root->right);
cout<<root->data<<"->";
}
void postOrderTraversel(){
postOrder(root);
cout<<endl;
}
bool search(int value){
if (root == nullptr) return false;
queue<Node*> q;
q.push(root);
while(!q.empty()) {
Node* current = q.front();
q.pop();
if(current->data == value){
return true;
}
if(current->left != nullptr)
q.push(current->left);
if (current->right != nullptr) q.push(current->right);
}
return false;
}};
int main(){
BinaryTree tree;
// Insert values into the binary tree in level-order
tree.insert(1);
tree.insert(2);
tree.insert(3);
tree.insert(4);
tree.insert(5);
tree.insert(6);
tree.insert(7);
cout << "pre order Traversal: ";
tree.preOrderTraversel();
cout<<endl;
cout << "post order Traversal: ";
tree.postOrderTraversel();
cout<<endl;
int key=6;
if (tree.search(key))
cout<<key<<" is present in this binary tree."<<endl;
else
cout<<key<<" is not present in this binary tree."<<endl;
return 0;
}
