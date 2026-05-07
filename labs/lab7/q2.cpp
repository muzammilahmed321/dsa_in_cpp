#include<iostream>
using namespace std;
void merge(int arr[],int left,int mid,int right){
int n1=mid-left+1;
int n2=right-mid;
int L[n1];
int R[n2];
for(int i=0;i<n1;i++){
L[i]=arr[left+i];
}
for(int j=0;j<n2;j++){
R[j]=arr[mid+ j+ 1];
}
int i=0;
int j=0;
int k=left;
while(i<n1 && j<n2){
if(L[i]<=R[j]){
arr[k]=L[i];
i++;
}
else{
arr[k]=R[j];
j++;
}
k++;
}
while(i<n1){
arr[k]=L[i];
i++;
k++;
}
while(j<n2){
arr[k]=R[j];
j++;
k++;}}
void mergesort(int arr[],int n){
for(int size=1; size<n; size*=2){
for(int left=0; left<n-1; left+=2*size){
int mid=min(left+size-1,n-1);
int right=min(left+2*size-1,n-1);
merge(arr,left,mid,right);
}}}
void printArray(int arr[], int size) {
for (int i = 0; i < size; i++)
cout << arr[i] << " ";
cout << endl;
}
int main(){
int arr[] = {15, 12, 10, 4, 9, 1};
int n=sizeof(arr)/sizeof(arr[0]);
cout << "Unsorted array: ";
printArray(arr, n);
mergesort(arr,n);
cout << "Sorted array: ";
printArray(arr,n);
}

