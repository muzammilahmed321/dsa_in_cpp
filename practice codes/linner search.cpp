#include<iostream>
using namespace std;
int main(){
int size=5;
int target;
cout<<"enter required target";
cin>>target;
int arr[5]={12,17,20,56,100};
for(int i=0; i<=size; i++)
{
if(arr[i]==target){
return i;
}

}
return -1;

}
