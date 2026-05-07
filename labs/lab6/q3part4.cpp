#include <iostream>
#include <string>
using namespace std;
class sort {
int comparisons, swaps;

public:
sort() {
comparisons = 0;
swaps = 0;
}
int number_of_comparisons() {
return comparisons;
}
int number_of_swaps() {
return swaps;
}
void resetCounts() {
comparisons = 0;
swaps = 0;
}
void bubbleSort(int* arr, int n) {
resetCounts();
for (int i = 0; i < n - 1; i++) {
bool swapped = false;
for (int j = 0; j < n - i - 1; j++) {
comparisons++;
if (arr[j] > arr[j + 1]) {
swap(arr[j], arr[j + 1]);
swapped = true;
swaps++;}}
if (!swapped)
break;
}
cout << "\nAfter Bubble Sort: ";
for (int i = 0; i < n; i++) cout << arr[i] << " ";
cout << endl;
}
void selectionSort(int* arr, int n) {
resetCounts();
for (int i = 0; i < n - 1; i++) {
int min_idx = i;
for (int j = i + 1; j < n; j++) {
comparisons++;
if (arr[j] < arr[min_idx])
min_idx = j;
}
if (min_idx != i) {
swap(arr[min_idx], arr[i]);
swaps++;
}
}
cout << "\nAfter Selection Sort: ";
for (int i = 0; i < n; i++) cout << arr[i] << " ";
cout << endl;
}
void insertionSort(int* arr, int n) {
resetCounts();
for (int i = 1; i < n; i++) {
int key = arr[i];
int j = i - 1;
while (j >= 0) {
comparisons++;
if (arr[j] > key) {
arr[j + 1] = arr[j];
swaps++;
j--;
} else {
break;
}
}
arr[j + 1] = key;
}
cout << "\nAfter Insertion Sort: ";
for (int i = 0; i < n; i++) cout << arr[i] << " ";
cout << endl;
}
void sortArray(string choice, int* arr, int n) {
int* temp = new int[n]; // store original array in temp pointer
for (int i = 0; i < n; i++) temp[i] = arr[i];
if (choice == "bubble" || choice == "bubble sort") {
bubbleSort(temp, n);
cout << "Comparisons: " << number_of_comparisons()
<< ", Swaps: " << number_of_swaps() << endl;
}
else if (choice == "selection" || choice == "selection sort") {
selectionSort(temp, n);
cout << "Comparisons: " << number_of_comparisons()
<< ", Swaps: " << number_of_swaps() << endl;
}
else if (choice == "insertion" || choice == "insertion sort") {
insertionSort(temp, n);
cout << "Comparisons: " << number_of_comparisons()
<< ", Swaps: " << number_of_swaps() << endl;
}
else if (choice == "all") {
compareAll(arr, n);
}
else {
cout << "Invalid choice!\n";
}
delete[] temp;
}
void compareAll(int* arr, int n) {
int cmp, swp;
int total[3]; // to store total operations for each sort
string names[3] = {"Bubble", "Selection", "Insertion"};
// Bubble Sort
int* temp = new int[n];
for (int i = 0; i < n; i++) temp[i] = arr[i];
bubbleSort(temp, n);
cmp = number_of_comparisons();
swp = number_of_swaps();
total[0] = cmp + swp;
cout << " Bubble | Comparisons: " << cmp << ", Swaps: " << swp << endl;
// Selection Sort
for (int i = 0; i < n; i++) temp[i] = arr[i];
selectionSort(temp, n);
cmp = number_of_comparisons();
swp = number_of_swaps();
total[1] = cmp + swp;
cout << " Selection | Comparisons: " << cmp << ", Swaps: " << swp << endl;
// Insertion Sort
for (int i = 0; i < n; i++) temp[i] = arr[i];
insertionSort(temp, n);
cmp = number_of_comparisons();
swp = number_of_swaps();
total[2] = cmp + swp;
cout << " Insertion | Comparisons: " << cmp << ", Swaps: " << swp << endl;
// Find Best and Worst case
int best = 0, worst = 0;
for (int i = 1; i < 3; i++) {
if (total[i] < total[best])
best = i;
if (total[i] > total[worst])
worst = i;
}
cout << "\n (Best Case): " << names[best];
cout << "\n (Worst Case): " << names[worst] << endl;
delete[] temp;
    }
};

int main() {
int arr[] = {15,10,23,12,7,13};
int N = sizeof(arr) / sizeof(arr[0]);
sort s;
cout << "Enter sorting choice (bubble / selection / insertion / all): ";
string choice;
getline(cin, choice);
s.sortArray(choice, arr, N);
return 0;
}
