#include<iostream>
using namespace std;
void bubbleSort(int* arr, int N){
int i, j;
bool swaped;

for (i = 0; i < N-1; i++){
swaped=false;
for (j = 0; j < N - i - 1; j++){
if (arr[j] > arr[j + 1]){
swap(arr[j], arr[j + 1]);
swaped=true;
}
}
if (!swaped){
   break;
}
}
}
int maxtoycheck(int arr[], int N,int k){
bubbleSort(arr,N);
int total=0;
int count=0;
int i;
for(i=0;i<N-1;i++){
if(total+arr[i]<k){
total+=arr[i];
count++;
   }
else{
    break;
}
}
cout<<"\nThe  toys  that You can buy are ";
for(i=0;i<count;i++){
cout<<" "<<arr[i]<<",";
}
cout<<"\n maximum number of toys you can buy are:";
return count;
}
int main(){

int arr[]={12,10,7,100,212,5,312};
int N = sizeof(arr)/sizeof(arr[0]);
int k=60;
cout<<maxtoycheck(arr, N, k);
}
