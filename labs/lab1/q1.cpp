#include <iostream>
using namespace std;

int main() {
int rows, cols;
cout<<"enter number of rows and colomn";
cin >> rows >> cols;
int arr[rows][cols], oneDarr[rows * cols], k = 0;
for (int i = 0; i < rows; i++)
for (int j = 0; j < cols; j++)
cin >> arr[i][j];
for (int j = 0; j < cols; j++)
for (int i = 0; i < rows; i++)
oneDarr[k++] = arr[i][j];
for (int i = 0; i < k; i++)
cout << oneDarr[i] << " ";
return 0;
}

