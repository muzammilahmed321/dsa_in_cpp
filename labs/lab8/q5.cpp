#include <iostream>
#include <algorithm>
using namespace std;
class Node{
public:
int data;
Node* left;
Node* right;
Node(int value) : data(value), left(nullptr), right(nullptr) {}
};
pair<int, int> robHelper(Node* node){
if (node == nullptr){
return {0, 0};
}
auto left =robHelper(node->left);
auto right= robHelper(node->right);
int robThis = node->data + left.second + right.second;
int skipThis = max(left.first, left.second) + max(right.first, right.second);
return {robThis, skipThis};
}
int rob(Node* root){
if (!root)
return 0;
auto result = robHelper(root);
return max(result.first, result.second);
}
int main(){
// Example 1
Node* root1 = new Node(3);
root1->left = new Node(2);
root1->right = new Node(3);
root1->left->right = new Node(3);
root1->right->right = new Node(1);
cout<<"Max money: "<<rob(root1)<<endl;
// Example 2
Node* root2 = new Node(4);
root2->left = new Node(1);
root2->right = new Node(5);
root2->left->left = new Node(1);
root2->left->right = new Node(3);
root2->right->right = new Node(1);
cout << "Max money: " << rob(root2) << endl;
return 0;
}
