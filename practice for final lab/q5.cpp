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
vector<int> l1={1,4,5};
vector<int> l2={6,7,9};
for(int i=0; i<l1.size();i++){
    list.insert (l1[i]);
    list.insert (l2[i]);
}
list.display();
}
