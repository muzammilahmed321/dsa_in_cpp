#include <iostream>
using namespace std;
class Sorting {
int *data;
int size;
public:
Sorting() {
data = NULL;
size = 0;
}

    void inputData() {
        cout << "Enter total elements: ";
        cin >> size;
        data = new int[size];
        cout << "Enter values: ";
        for (int i = 0; i < size; i++)
            cin >> data[i];
    }
    void bubble(int &cmp, int &swp) {
        int *arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = data[i];
        cmp = swp = 0;
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                cmp++;
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swp++;
                }
            }
        }

        cout << "\nAfter Bubble Sort: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;

        delete[] arr;
    }
    void selection(int &cmp, int &swp) {
        int *arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = data[i];
        cmp = swp = 0;

        for (int i = 0; i < size - 1; i++) {
            int minPos = i;
            for (int j = i + 1; j < size; j++) {
                cmp++;
                if (arr[j] < arr[minPos])
                    minPos = j;
            }
            if (minPos != i) {
                int temp = arr[i];
                arr[i] = arr[minPos];
                arr[minPos] = temp;
                swp++;
            }
        }
        cout << "\nAfter Selection Sort: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;

        delete[] arr;
    }
    void insertion(int &cmp, int &swp) {
        int *arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = data[i];
        cmp = swp = 0;

        for (int i = 1; i < size; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                swp++;
                j--;
                cmp++;
            }
cmp++;
arr[j + 1] = key;
}
cout << "\nAfter Insertion Sort: ";
for (int i = 0; i < size; i++)
cout << arr[i] << " ";
cout << endl;
delete[] arr;
}
void chooseSort() {
int option;
cout << "\nChoose Sorting Algorithm:\n";
cout << "1. Bubble\n2. Selection\n3. Insertion\n";
cout << "Enter your choice: ";
cin >> option;
int cmp = 0, swp = 0;
if (option == 1)
bubble(cmp, swp);
else if (option == 2)
selection(cmp, swp);
else if (option == 3)
insertion(cmp, swp);
else {
cout << "Invalid option!\n";
return;
}
cout << "Comparisons: " << cmp << ", Swaps: " << swp << endl;
}
void compareAll() {
int cmp, swp;
int score[3];
int sample[5] = {5, 6, 8, 3, 5};
cout << "\nTesting all methods on array: 5 6 8 3 5\n";
delete[] data;
size = 5;
data = new int[size];
for (int i = 0; i < size; i++)
data[i] = sample[i];
bubble(cmp, swp);
score[0] = cmp + swp;
cout << " Bubble | Comp: " << cmp << " Swaps: " << swp << endl;
for (int i = 0; i < size; i++)
data[i] = sample[i];
selection(cmp, swp);
score[1] = cmp + swp;
cout << " Selection | Comp: " << cmp << " Swaps: " << swp << endl;
for (int i = 0; i < size; i++)
data[i] = sample[i];
insertion(cmp, swp);
score[2] = cmp + swp;
cout << " Insertion | Comp: " << cmp << " Swaps: " << swp << endl;
int best = 0, worst = 0;
for (int i = 1; i < 3; i++) {
if (score[i] < score[best])
best = i;
if (score[i] > score[worst])
worst = i;
}
cout << "\nFastest: ";
if (best == 0) cout << "Bubble";
else if (best == 1) cout << "Selection";
else cout << "Insertion";
cout << "\nSlowest: ";
if (worst == 0) cout << "Bubble";
else if (worst == 1) cout << "Selection";
else cout << "Insertion";
cout << endl;
}
~Sorting() {
delete[] data;
}
};
int main() {
Sorting s;
s.inputData();
s.chooseSort();
s.compareAll();
return 0;
}
