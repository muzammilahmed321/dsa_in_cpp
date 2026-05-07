#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &arr, int st, int mid, int end) {
    vector<int> temp;
    int i = st, j = mid + 1;
    int invcount = 0;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
            invcount += (mid - i + 1); // Count inversions
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++) {
        arr[st + idx] = temp[idx];
    }

    return invcount;
}

int merge_sort(vector<int> &arr, int st, int end) {
    int invcount = 0;
    if (st < end) {
        int mid = st + (end - st) / 2;
        invcount += merge_sort(arr, st, mid);      // Sort left half
        invcount += merge_sort(arr, mid + 1, end); // Sort right half
        invcount += merge(arr, st, mid, end);      // Merge and count
    }
    return invcount;
}

int main() {
    vector<int> arr = {6, 3, 5, 2, 7};

    int invCount = merge_sort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << "\nInversion count: " << invCount << endl;

    return 0;
}

