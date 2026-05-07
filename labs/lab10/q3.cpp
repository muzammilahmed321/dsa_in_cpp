#include <iostream>
using namespace std;
class ListToBST{
private:
struct ListNode{
int val;
ListNode* next;
ListNode(int v){
val=v;
next=NULL;
}
};
struct TreeNode{
int val;
TreeNode* left;
TreeNode* right;
TreeNode(int v){
val=v;
left=NULL;
right=NULL;
}
};
ListNode* head;
TreeNode* root;
ListNode* getMid(ListNode* start, ListNode* end){
ListNode* slow = start;
ListNode* fast = start;
while (fast !=end && fast->next!=end){
slow=slow->next;
fast=fast->next->next;
}
return slow;
}
TreeNode* buildTree(ListNode* start, ListNode* end){
if(start==end)
return NULL;
ListNode* mid = getMid(start, end);
TreeNode* node=new TreeNode(mid->val);
node->left=buildTree(start, mid);
node->right=buildTree(mid->next, end);
return node;
}
void inorder(TreeNode* node){
if(node==NULL)
return;
inorder(node->left);
cout<<node->val << " ";
inorder(node->right);
}
public:
ListToBST(){
head=NULL;
root=NULL;
}
void insertList(int v){
if(head == NULL)
head=new ListNode(v);
else{
ListNode* temp=head;
while(temp->next !=NULL)
temp=temp->next;
temp->next=new ListNode(v);
}
}
void convert(){
root=buildTree(head, NULL);
}
void printInorder(){
inorder(root);
cout<<endl;
}
};
int main(){
ListToBST obj;
obj.insertList(60);
obj.insertList(70);
obj.insertList(80);
obj.insertList(90);
obj.insertList(100);
obj.convert();
cout << "Inorder Traversal of Height Balanced BST: ";
obj.printInorder();
return 0;
}
