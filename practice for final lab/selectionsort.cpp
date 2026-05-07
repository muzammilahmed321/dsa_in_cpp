#include<iostream>
#include<algorithm>
using namespace std;
void selection(int* arr,int n){

for(int i=0;i<n-1;i++){

int min_indx=i;
for(int j=i+1;j<n;j++){
    if(arr[j]<arr[min_indx]){
        min_indx=j;
    }

}
if(min_indx!=i){
        swap(arr[min_indx],arr[i]);
    }
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
    int arr[] = {1,4,2,5,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "before sorting" << endl;
    print(arr, n);
    cout << "\n";
   selection(arr, n);

    cout << "after sorting:\n";
    print(arr, n);
    cout << "\n";

    return 0;
}
