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
 cout<<"Null"<<endl;
 }
};
int main(){
list ll;
ll.push_front(1);
ll.push_front(2);
ll.push_front(3);
ll.push_front(5);
ll.printll();
return 0;
}
