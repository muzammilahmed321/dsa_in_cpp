#include<iostream>
#include<vector>
#include<queue>
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
Node* buildTreeHelper(vector<int> preorder, vector<int> inorder, int start, int end, int& preIndex){
if(start>end)
return NULL;
int val=preorder[preIndex++];
Node* root=new Node(val);
if(start==end)
return root;
int inIndex = -1;
for(int i=start; i<=end; i++) {
if(inorder[i]==val) {
inIndex= i;
break;
}
}
root->left = buildTreeHelper(preorder, inorder, start, inIndex - 1, preIndex);
root->right = buildTreeHelper(preorder, inorder, inIndex + 1, end, preIndex);
return root;
}

Node* buildTree(vector<int>& preorder, vector<int>& inorder){
int preIndex = 0;
return buildTreeHelper(preorder, inorder, 0, inorder.size()-1, preIndex);
}

void printLevelOrder(Node* root){
if(!root) {
cout<<"[]"<<endl;
return;
}
queue<Node*> q;
q.push(root);
vector<string> result;
while(!q.empty()){
Node* node=q.front();
q.pop();
if(node){
result.push_back(to_string(node->data));
q.push(node->left);
q.push(node->right);
}
else{
result.push_back("null");
}
}
while(!result.empty() && result.back() == "null") {
result.pop_back();
}
cout<< "[";
for(size_t i = 0; i < result.size(); i++){
cout<<result[i];
if(i!=result.size()-1)
cout<<",";
}
cout<<"]"<<endl;
}

int main(){
vector<int> preorder={3, 9, 20, 15, 7};
vector<int> inorder={9, 3, 15, 20, 7};
Node* root=buildTree(preorder,inorder);
printLevelOrder(root);
cout<<endl;
return 0;
}

