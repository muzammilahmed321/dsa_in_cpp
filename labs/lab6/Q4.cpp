#include <iostream>
using namespace std;
void flip(int *arr, int k) {
int start = 0;
while (start < k) {
int temp = arr[start];
arr[start] = arr[k];
arr[k] = temp;
start++;
k--; } }
int findMaxIndex(int *arr, int n) {
int maxIndex = 0;
for (int i = 1; i < n; i++) {
if (arr[i] > arr[maxIndex])
maxIndex = i; }
return maxIndex;
}
void pancakeSort(int *arr, int n) {
for (int size = n; size > 1; size--) {
int maxIndex = findMaxIndex(arr, size);
if (maxIndex != size - 1) {
flip(arr, maxIndex);
flip(arr, size - 1);
} } }
void printArray(int *arr, int n) {
for (int i = 0; i < n; i++)
cout << arr[i] << " ";
cout << endl;
}
int main() {
int n;
cout << "Enter number of elements: ";
cin >> n;
int *arr = new int[n];
cout << "Enter elements: ";
for (int i = 0; i < n; i++)
cin >> arr[i];
cout << "Original array: ";
printArray(arr, n);
pancakeSort(arr, n);
cout << "Sorted array: ";
printArray(arr, n);
delete[] arr;
return 0;
}
