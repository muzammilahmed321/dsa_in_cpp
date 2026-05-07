#include <iostream>
#include <stack>
using namespace std;
class TreeNode{
public:
int val;
TreeNode *left,*right;
TreeNode(int value){
val=value;
left=right=NULL;
}
};
class BinarySearchTree{
public:
TreeNode* root;
BinarySearchTree() : root(NULL) {}
void insert(int key){
root=insertRec(root,key);
}
void inorder(){
inorderRec(root);
cout<<endl;
}
void preorder(){
preorderIter(root);
cout << endl;
}
void postorder(){
postorderIter(root);
cout<<endl;
}
 private:
TreeNode* insertRec(TreeNode* node, int key){
if (node ==NULL)
return new TreeNode(key);
if(key<node->val)
node->left = insertRec(node->left, key);
else if(key > node->val)
node->right = insertRec(node->right, key);
return node;
}
void inorderRec(TreeNode* root){
if (root!=NULL){
inorderRec(root->left);
cout<<root->val<<" ";
inorderRec(root->right);
}
}
void preorderIter(TreeNode* root){
if(root == NULL)
return;
stack<TreeNode*> s;
s.push(root);
while(!s.empty()){
TreeNode* node = s.top();
s.pop();
cout << node->val << " ";
if (node->right) s.push(node->right);
if (node->left) s.push(node->left);
}
}
void postorderIter(TreeNode* root){
if(root == NULL)
return;
stack<pair<TreeNode*, bool>> s;
s.push(make_pair(root, false));
while(!s.empty()){
pair<TreeNode*, bool> top = s.top();
s.pop();
if (top.second){
cout<<top.first->val <<" ";
}
else{
s.push(make_pair(top.first, true));
if (top.first->right) s.push(make_pair(top.first->right, false));
if (top.first->left) s.push(make_pair(top.first->left, false));
}
}
}
};
 int main(){
BinarySearchTree bst;
bst.insert(50);
bst.insert(30);
bst.insert(20);
bst.insert(40);
bst.insert(70);
bst.insert(60);
bst.insert(80);
cout<<"Inorder: ";
bst.inorder();
cout<<"Preorder: ";
bst.preorder();
cout<<"Postorder: ";
bst.postorder();
return 0;
}
