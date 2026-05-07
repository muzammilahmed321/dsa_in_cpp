#include <iostream>
#include <climits>
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
class BST {
public:
TreeNode* root;
BST(){
root=NULL;
}
TreeNode* insert(TreeNode* node, int key) {
if(node ==NULL)
return new TreeNode(key);
if (key < node->val)
node->left = insert(node->left, key);
else if (key > node->val)
node->right = insert(node->right, key);
return node;
}
void insert(int key){
root =insert(root, key);
}
void inorder(TreeNode* node, int &prev, int &minDiff){
if(node ==NULL)
return;
inorder(node->left, prev, minDiff);
if(prev!=-1)
minDiff=min(minDiff,node->val-prev);
prev=node->val;
inorder(node->right, prev, minDiff);
}
int getMinDiff(){
int prev =-1;
int minDiff =INT_MAX;
inorder(root, prev, minDiff);
return minDiff;
}
};

int main() {
BST bst;
bst.insert(50);
bst.insert(30);
bst.insert(20);
bst.insert(40);
bst.insert(70);
bst.insert(60);
bst.insert(80);
int result =bst.getMinDiff();
cout<<"Minimum difference between any two nodes: " << result << endl;
return 0;
}

