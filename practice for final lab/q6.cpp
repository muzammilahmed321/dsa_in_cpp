#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
node *next;
int data;
node(int data)
{

   this->data=data;
    this->next=NULL;
}
};
class linklist{
private:
    node *head;
public:
    linklist(){
    head=NULL;
    }
    void insert(int data){
node *newNode=new node(data);
    if(head==NULL){
            head=newNode;
    }
    else{
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;


    }

temp->next=newNode;

    }
}
void deleteduplicate(){
node *cur=head;
while(cur!=NULL &&cur->next!=NULL){

    if(cur->data==cur->next->data){
        node *duplicate=cur->next;
        cur->next=duplicate->next;
        delete duplicate;
    }
    else{
        cur=cur->next;
    }
}
}
void display(){
node *temp=head;
while(temp->next!=NULL){

   cout<<temp->data<<"->";
   temp=temp->next;

}
cout<<"NULL";

}
};

int main(){

linklist list;
vector<int> l1={1,1,3,3,4,4,5,6,6};

for(int i=0; i<l1.size();i++){
    list.insert (l1[i]);

}
cout<<"before deleting duplicates"<<endl;
list.display();
cout<<endl;
list.deleteduplicate();
cout<<"after removing duplicates"<<endl;
list.display();
}
