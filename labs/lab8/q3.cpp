#include <iostream>
#include <cmath>
using namespace std;
class Node{
public:
int data;
Node* left;
Node* right;
Node(int value) {
data=value;
left=right=nullptr;
}
};
// Function to check the height of the tree, or -1 if not balanced
int checkHeight(Node* root){
if(root == nullptr)
return 0;
int leftHeight =checkHeight(root->left);
if(leftHeight == -1)
return -1;  // Left subtree not balanced
int rightHeight = checkHeight(root->right);
if(rightHeight==-1)
return -1;// Right subtree not balanced
if(abs(leftHeight - rightHeight) > 1)
return -1; // Current node not balanced
return 1 + max(leftHeight, rightHeight); // Return height
}
bool isBalanced(Node* root){
return checkHeight(root) != -1;
}
// Example usage
int main() {
// Balanced tree: [3,9,20,null,null,15,7]
Node* root1 = new Node(3);
root1->left = new Node(9);
root1->right = new Node(20);
root1->right->left = new Node(15);
root1->right->right = new Node(7);
cout << "Tree 1 Balanced? " << (isBalanced(root1) ? "Yes" : "No") << endl;
// Unbalanced tree: [1,2,null,3,null,4,null,null]
Node* root2 = new Node(1);
root2->left = new Node(2);
root2->left->left = new Node(3);
root2->left->left->left = new Node(4);
cout <<"Tree 2 Balanced? "<<(isBalanced(root2) ? "Yes" : "No")<<endl;
return 0;
}

