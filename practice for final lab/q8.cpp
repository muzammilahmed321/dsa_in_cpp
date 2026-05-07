#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
node *next;
int data;
node(int data){
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
int newNode=new Node(data);
if(head==NULL){
    head=newNode;


}
else{
    node *temp;
    while(temp->next!=NULL){
        temp=temp->next;

    }
    temp->next=newNode;
}
}
bool isPalindrom(){
vector<int> arr;
node *temp=head;
while(temp!=NULL){
    arr.push_back(temp->data);

int i=0;
int j=arr.size(temp->data)
while(i<j){
    if(arr[i]!=arr[j]) return false;
i++;
j--;
}
return true;
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
linklist l1;
l1.insert(1);
l1.insert(2);
l1.insert(2);
l1.insert(1);
if(l1.isPalindrom()){
    cout<<"list is palindrom";
}
else{
    cout<<"not a palindrom";

}
return 0;
}
