#include <iostream>
using namespace std;
class BST{
private:
struct TreeNode {
int value;
TreeNode* leftChild;
TreeNode* rightChild;
TreeNode(int v){
value=v;
leftChild=NULL;
rightChild=NULL;
}};
TreeNode* root;
TreeNode* buildBalancedTree(int arr[],int startIndex, int endIndex){
if(startIndex>endIndex)
return NULL;
int middle=(startIndex+endIndex)/2;
TreeNode* newNode=new TreeNode(arr[middle]);
newNode->leftChild = buildBalancedTree(arr, startIndex, middle-1);
newNode->rightChild = buildBalancedTree(arr, middle+1, endIndex);
return newNode;
}
void printLevelOrder(TreeNode* node){
if(node==NULL)
return;
TreeNode* queue[100];
int front=0;
int back=0;
queue[back++]=node;
while(front<back){
TreeNode* current=queue[front++];
if (current!=NULL)
cout<<current->value<< " ";
else
{
cout <<"null ";
continue;
}
queue[back++]=current->leftChild;
queue[back++]=current->rightChild;
}
}
public:
BST(){
root=NULL;
}
void arrayToBST(int arr[], int size){
root=buildBalancedTree(arr, 0, size - 1);
}
void printTree(){
printLevelOrder(root);
cout << endl;
}
};
int main(){
int numbers[]={-10, -3, 0, 5, 9};
int size=5;
cout<<"Input: nums = [";
for(int i=0;i<size;i++) {
cout << numbers[i];
if(i<size-1)
cout <<", ";
}
cout<< "]"<<endl;
BST myTree;
myTree.arrayToBST(numbers,size);
cout << "Output: ";
myTree.printTree();
return 0;
}
