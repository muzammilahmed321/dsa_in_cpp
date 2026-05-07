#include <iostream>
using namespace std;
// Function to swap two elements
void swap(int& a, int& b) {
int temp = a;
a = b;
b = temp;
}
// Partition function: places the pivot element in its correct position
int partition(int arr[], int low, int high) {
int pivot = arr[high]; // Choosing the last element as pivot
int i = low - 1; // Index of smaller element
for (int j = low; j < high; j++) {
// If the current element is smaller than or equal to the pivot
if (arr[j] <= pivot) {
i++; // Move the smaller element's index forward
swap(arr[i], arr[j]);
}
}
// Place the pivot in its correct position
swap(arr[i + 1], arr[high]);
return i + 1; // Return the partition index
}
// Quick Sort function
void quickSort(int arr[], int low, int high,int pivot) {
if (low < high) {
        pivot=high;
// Partition the array
int pi = partition(arr, low, high);
// Recursively sort elements before and after partition
for(int k=low;k<=high;k++)
if(arr[k]<pivot){
low=0; high=pivot-1;}
else if(arr[k]>pivot){
low=pivot+1;
}
}
// Function to print the array
void printArray(int arr[], int size) {
for (int i = 0; i < size; i++) {
cout << arr[i] << " ";
}
cout << endl;
}
int main() {
int arr[] = {10, 7, 8, 9, 1, 5};
int n = sizeof(arr) / sizeof(arr[0]);
cout << "Unsorted array: ";
printArray(arr, n);
// Perform Quick Sort
quickSort(arr, 0, n - 1);
cout << "Sorted array: ";
printArray(arr, n);
return 0;
}
