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
TreeNode* insert(TreeNode* node, int key){
if (node==NULL)
return new TreeNode(key);
if(key<node->val)
node->left = insert(node->left, key);
else if(key > node->val)
node->right = insert(node->right, key);
return node;
}
void insert(int key){
root =insert(root, key);
}
int sumNodes(TreeNode* node){
if(node == NULL)
return 0;
return node->val + sumNodes(node->left) + sumNodes(node->right);
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
int total =bst.sumNodes(bst.root);
cout<<"Sum of all nodes in the BST: "<<total<<endl;
return 0;

}
