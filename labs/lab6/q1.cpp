#include <iostream>
using namespace std;
// A function to implement bubble sort
void bubbleSort(int* arr, int n){
int i, j;
bool swaped;

for (i = 0; i < n - 1; i++){
swaped=false;
// Last i elements are already in place
for (j = 0; j < n - i - 1; j++){
if (arr[j] > arr[j + 1]){
swap(arr[j], arr[j + 1]);
swaped=true;
}

}
//checking  elements are sorted or not
if (!swaped){
    cout<<"array is already sorted after "<<i+1<<" iteration(s)";
    break;
}
}
}

// Function to print an array
void printArray(int* arr, int size){
int i;
for (i = 0; i < size; i++)
cout << arr[i] << " ";
cout << endl; }
// Driver code
int main(){
int arr[] = { 5, 1, 4, 2, 8};
int N = sizeof(arr) / sizeof(arr[0]);
bubbleSort(arr, N);
cout << "\nSorted array: \n";
printArray(arr, N);
return 0;
}
