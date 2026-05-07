#include<iostream>
using namespace std;
class sort{
int comparision,swaps;
int number_of_comperissions(){
return comparision;
}
int number_of_swaps(){
return swaps;
}
int number_of_comperissions(){
return comparission;
}


void bubbleSort(int* arr, int n){
int i, j;
bool swaped;

for (i = 0; i < n - 1; i++){
swaped=false;
comparision++;
for (j = 0; j < n - i - 1; j++){
if (arr[j] > arr[j + 1]){
swap(arr[j], arr[j + 1]);
swaped=true;
swaps++;
}
}
//checking  elements are sorted or not
if (!swaped){
    break;
}
}
}

void selectionSort(int* arr, int n){
int i, j, min_idx;
for (i = 0; i < n-1; i++){
comparision++;
min_idx = i;
for (j = i+1; j < n; j++)
if (arr[j] < arr[min_idx])
min_idx = j;
if(min_idx!=i)
swap(arr[min_idx], arr[i]);
swaps++;
}
}


void insertionSort(int* arr, int n){
int i, key, j;
for (i = 1; i < n; i++){
comparision++;
key = arr[i];
j = i - 1;
while (j >= 0 && arr[j] > key){
arr[j + 1] = arr[j];
swaps++;
j = j - 1;
}
arr[j + 1] = key;
}
}
int sortarray(string choise){

if(choise=="bubble sort"){
cout<<"\nbubble sort is";
bubbleSort();
cout<<"\n number of comparision";
number_of_comperissions();
cout<<"\n number of swaps";
number_of_swaps();

}
else if(choise=="insertion sort"){
cout<<"\n insertion sort";
insertionSort();
cout<<"\n number of comparision";
number_of_comperissions();
cout<<"\n number of swaps";
number_of_swaps();

}
else if(choise=="selection"){
cout<<"\n selection sort";
selectionSort();
cout<<"\n number of comparision";
number_of_comperissions();
cout<<"\n number of swaps";
number_of_swaps();

}
else if(choise=="all"){
cout<<"\nbubble sort is";
bubbleSort();
cout<<"\n number of comparision";
number_of_comperissions();
cout<<"\n number of swaps";
number_of_swaps();
cout<<"\n insertion sort";
insertionSort();
cout<<"\n number of comparision";
number_of_comperissions();
cout<<"\n number of swaps";
number_of_swaps();
cout<<"\n selection sort";
selectionSort();
cout<<"\n number of comparision";
number_of_comperissions();
cout<<"\n number of swaps";
number_of_swaps();

}

}
};
int main(){
int arr[] = { 0, 1, 0, 2,1,0 ,1 };
int N = sizeof(arr) / sizeof(arr[0]);



}
