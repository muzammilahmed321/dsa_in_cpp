#include <iostream>
using namespace std;
void mergeArrays(int arr[], int left, int mid, int right){
int n1 = mid - left + 1, n2 = right - mid;
int leftArr[1000], rightArr[1000];
for(int i = 0; i < n1; i++) leftArr[i]=arr[left + i];
for(int j = 0; j < n2; j++)rightArr[j]=arr[mid + 1 + j];
int i = 0, j = 0, k = left;
while(i < n1 && j < n2){
if(leftArr[i] <= rightArr[j])arr[k++]=leftArr[i++];
else
arr[k++]=rightArr[j++];
}
while(i<n1)arr[k++]=leftArr[i++];
while(j<n2)arr[k++]=rightArr[j++];
}
void mergeSort(int arr[], int left, int right){
if(left < right){
int mid=(left + right)/2;
mergeSort(arr, left, mid);
mergeSort(arr, mid + 1, right);
mergeArrays(arr, left, mid, right);
}
}
int longestHarmoniousSubsequence(int arr[], int n){
mergeSort(arr, 0, n - 1);
int maxLength = 0;
int i=0;
while(i < n){
int currentValue=arr[i];
int countCurrent=0;
while(i < n && arr[i] == currentValue){
countCurrent++;
i++;
}
int j=i;
int nextValue=currentValue + 1;
int countNext = 0;
while(j < n && arr[j]==nextValue){
countNext++;
j++;
}
if(countNext > 0 && countCurrent + countNext > maxLength)
maxLength=countCurrent + countNext;
}
return maxLength;
}
int main(){
int arr[]={1,3 , 2, 2, 6, 2, 4, 8};
int n = sizeof(arr) / sizeof(arr[0]);
cout <<"Original Array:";
for(int i = 0; i < n; i++)
cout <<arr[i]<< " ";
cout<<endl;
int result = longestHarmoniousSubsequence(arr, n);
cout<<"Longest Harmonious Subsequence Length:"<<result<<endl;
cout<<"Sorted Array: ";
for(int i = 0; i < n; i++)
cout<<arr[i]<<" ";
cout<<endl;
return 0;
}
