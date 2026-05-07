#include<iostream>
#include<algorithm>
using namespace std;

void insertion(int* arr, int n){
    int key, i, j;
    for(i = 1; i < n; i++){
        key = arr[i]; // Store the element to be inserted
        j = i - 1;

        // Shift elements greater than key to the right
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j - 1;
        }

        // FIX: Insert the original 'key' into its correct sorted position
        arr[j+1] = key;
    }
}

void print(int* arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i];
        if (i < n - 1) {
            cout << ",";
        }
    }
}

int main(){
    int arr[] = {2, 0, 0, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "before sorting" << endl;
    print(arr, n);
    cout << "\n";

    insertion(arr, n);

    cout << "after sorting:\n";
    print(arr, n);
    cout << "\n";

    return 0;
}
