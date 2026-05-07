#include <iostream>
using namespace std;

bool searchMatrix(int** matrix, int m, int n, int target) {
int l = 0, r = m * n - 1;
while (l <= r) {
int mid = l + (r - l) / 2;
int val = matrix[mid / n][mid % n];
if (val == target) return true;
else if (val < target) l = mid + 1;
else r = mid - 1;
    }
return false;
}

int main() {
int m, n, target;
cin >> m >> n >> target;

int** matrix = new int*[m];
for (int i = 0; i < m; i++)
matrix[i] = new int[n];

for (int i = 0; i < m; i++)
for (int j = 0; j < n; j++)
cin >> matrix[i][j];

cout << (searchMatrix(matrix, m, n, target) ? "true" : "false");

for (int i = 0; i < m; i++)
delete[] matrix[i];
delete[] matrix;

return 0;
}
