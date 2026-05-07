#include <iostream>
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
class BST{
public:
TreeNode* root;
BST(){
root=NULL;
}
TreeNode* insert(TreeNode* node, int key) {
if (node==NULL)
return new TreeNode(key);
if(key<node->val)
node->left = insert(node->left, key);
else if(key > node->val)
node->right = insert(node->right, key);
return node;
}
void insert(int key) {
root =insert(root, key);
}
TreeNode* findLCA(TreeNode* node, int t1, int t2) {
if(node == NULL)
return NULL;
if (t1 < node->val && t2 < node->val)
return findLCA(node->left, t1, t2);
if(t1 > node->val && t2>node->val)
return findLCA(node->right,t1,t2);
return node;
}
};
int main(){
BST bst;
bst.insert(90);
bst.insert(70);
bst.insert(40);
bst.insert(30);
bst.insert(80);
bst.insert(50);
bst.insert(40);
int t1=40, t2=30;
TreeNode* lca = bst.findLCA(bst.root, t1, t2);
if(lca != NULL)
cout<<"LCA of  "<< t1<<" and "<< t2 <<" is:"<< lca->val<< endl;
else
cout<<"Nodes not found in the tree."<<endl;
return 0;
}
