#include <iostream>
using namespace std;
void insertionSort(int* arr, int n){
int i, prev, curr;
for (i = 1; i < n; i++){
curr = arr[i];
prev = i - 1;
while (prev >= 0 && arr[prev] > curr){
arr[prev + 1] = arr[prev];
prev = prev - 1;
}
arr[prev + 1] = curr;
}
}
void printArray(int* arr, int n){
int i;
cout<<"sorted colors are:";
for (i = 0; i < n; i++)
cout << arr[i] << " ";
cout << endl;
}
//0 represent red 1 represent white and 2 represent blue
//colors are sorted using insertion sort method
int main(){
int arr[] = { 0, 1, 0, 2,1,0 ,1 };
int N = sizeof(arr) / sizeof(arr[0]);
insertionSort(arr, N);
printArray(arr, N);
return 0;
}
