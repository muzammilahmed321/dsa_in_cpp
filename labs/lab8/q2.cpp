#include<iostream>
#include<vector>
using namespace std;
class Node{
public:
int data;
Node* left;
Node* right;
Node(int val){
data=val;
left=right=NULL;
}
};
static int idx=-1;
Node* buildTree(vector<int> preorder){
idx++;
if(preorder[idx]==-1){
    return NULL;
}
Node* root=new Node(preorder[idx]);
root->left=buildTree(preorder);
root->right=buildTree(preorder);
return root;
}
void preOrder(Node* root){
if(root==NULL){
return;
}
cout<<root->data<<"->";
preOrder(root->left);
preOrder(root->right);
}
bool isMirror(Node* t1, Node* t2) {
if(!t1 && !t2){
return true;
}
if(!t1 || !t2){
return false;
}
if(t1->data == t2->data){
if(isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left)){
return true;
}
}
return false;
}
bool isSymmetric(Node* root){
if(!root)
return true;
return isMirror(root->left, root->right);
}

int main(){
vector<int> preorder = {1, 2, 3, -1, -1, 4, -1, -1, 2, 4, -1, -1, 3, -1, -1};
Node* root=buildTree(preorder);
cout<<"pre order:";
preOrder(root);
cout<<endl;
//checking symmetric of left and right sub tree
if(isSymmetric(root)==true){
cout<<"Symmetric condition:True"<<endl;
}
else{
cout<<"Symmetric condition: False"<<endl;
}
return 0;
}
