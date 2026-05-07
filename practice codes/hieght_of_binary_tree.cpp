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
root->left=buildTree(preorder);//LEFT TREE
root->right=buildTree(preorder);//RIGHT TREE
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
int hight(Node* root){
if(root==NULL){
return 0;
}
int leftHit=hight(root->left);
int rightHit=hight(root->right);
return max(leftHit,rightHit)+1;
}
//count nodes
int count(Node* root){
    if(root==NULL){
        return 0;
    }
int leftcount=count(root->left);
int rightcount=count(root->right);
return leftcount+rightcount+1;
}
//sum of nodes
int sumofNode(Node* root){
if(root==NULL){
    return 0;
}
int leftsum=sumofNode(root->left);
int rightsum=sumofNode(root->right);
return leftsum+rightsum+root->data;
}

int main(){
vector<int> preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
Node* root=buildTree(preorder);
preOrder(root);
cout<<endl;
cout<<"hieght:"<<hight(root)<<endl;
cout<<"total number of nodes:"<<count(root)<<endl;
cout<<"sum of nodes:"<<sum(root)<<endl;
return 0;
}
