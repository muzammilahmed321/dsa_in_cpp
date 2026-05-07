#include<iostream>
using namespace std;
class Node{
public:
int data;
Node *Next;
Node(int val){
 data=val;
 Next=NULL;

}
};
class list{
 Node* Head;
 Node* Tail;
public:
    list(){
    Head=Tail=NULL;
    }
 void push_front(int val){
 Node*newNode=new Node(val);
 if(Head==NULL){
    Head=Tail=newNode;
    return;
 }
 else{
    newNode->Next=Head;
    Head=newNode;
 }
 }
 void printll(){
 Node* temp=Head;
 while(temp!=NULL)
 {
     cout<<temp->data<<"-> ";
     temp=temp->Next;
 }
 cout<<endl;
 }
 void insert(int val,int pos){
 if(pos<0){
    cout<<"invalid possition";
    return;
 }
 if(pos==0){
    push_front(val);
 }
 Node* temp=Head;
 for(int i=0; i<pos-1; i++){
    temp=temp->Next;

 }
 Node* newNode=new  Node(val);
 newNode->Next=temp->Next;
 temp->Next=newNode;
 }
};
int main(){
list ll;
ll.push_front(1);
ll.push_front(2);
ll.push_front(3);
ll.push_front(5);
ll.insert(4,1);
ll.printll();
return 0;
}
