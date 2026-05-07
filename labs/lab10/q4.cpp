#include <iostream>
#include <algorithm>
using namespace std;
struct TreeNode{
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Sol{
private:
int calculateHeightAndPath(TreeNode* node, int& longest_path) {
if(node ==nullptr){
return 0;
}
int left_height=calculateHeightAndPath(node->left,longest_path);
int right_height=calculateHeightAndPath(node->right,longest_path);
int path_through_current= left_height+right_height;
longest_path =max(longest_path, path_through_current);
return 1 + max(left_height, right_height);
}
public:
int diameter(TreeNode* root){
int longest_path =0;
calculateHeightAndPath(root, longest_path);
return longest_path;
}
};
int main(){
TreeNode* root=new TreeNode(12);
root->left = new TreeNode(7);
root->right = new TreeNode(17);
root->left->left = new TreeNode(3);
root->left->right = new TreeNode(8);
root->left->left->left = new TreeNode(2);
root->left->right->right = new TreeNode(9);
Sol a;
cout<<"Diameter of BST="<< a.diameter(root)<<endl;
return 0;
}
