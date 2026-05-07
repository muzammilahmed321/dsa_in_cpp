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
void print(int* arr,int n){
for(int i=0;i<n;i++){
    cout<<arr[i]<<",";
}
}
int main(){
int arr[]={2,5,1,3,4};
int n=sizeof(arr)/sizeof(arr[0]);
cout<<"before sorting"<<endl;
print(arr,n);
cout<<"\n";
buble_sort(arr,n);
cout<<"after sorting:\n";
print(arr,n);

}
