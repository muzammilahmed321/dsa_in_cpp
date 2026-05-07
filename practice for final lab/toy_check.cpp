#include<iostream>
#include<algorithm>
using namespace std;
void buble_sort(int* arr,int n){
int i,j;
bool check;
for(i=0;i<n-1;i++){
check=false;
for(j=0;j<n-i-1;j++){
    if(arr[j]>arr[j+1]){
        swap(arr[j],arr[j+1]);
        check=true;
    }

}

if(check==false){
    cout<<"array is already sorted after "<<i+1<<"ilteration(s)";
    break;
}
}
}
void max(int *arr,int N,int k){
buble_sort(arr,N);
int count=0;
int total=0;
for(int i=0;i<N-1;i++){
    if(total+arr[i]<k){
        total+=arr[i];
        count++;
    }
    else{
        break;
    }
}
for(int i=0;i<count;i++){
        cout<<arr[i]<<",";

}
cout<<"\nThe maximum number of toys you can buy is " <<count;
}
void print(int* arr,int n){
for(int i=0;i<n;i++){
    cout<<arr[i]<<",";
}
}
int main(){
int arr[]={15,35,10,30,4};
int N=sizeof(arr)/sizeof(arr[0]);
int k=70;
max(arr,N,k);

}
