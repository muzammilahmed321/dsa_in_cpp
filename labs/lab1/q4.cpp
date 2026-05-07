#include <iostream>
using namespace std;

int search(int nums[], int n, int target) {
int l = 0, r = n - 1;
while (l <= r) {
int mid = l + (r - l) / 2;
if (nums[mid] == target) return mid;
else if (nums[mid] < target) l = mid + 1;
else r = mid - 1;
}
return -1;
}
int main() {
int n, target;
cout<<"enter number of terms required:";
cin >>n;
cout<<endl;
cout<<"enter target:";
cin>> target;
int nums[n];
for (int i = 0; i < n; i++) cin >> nums[i];
cout<<"required target is at index:";
cout << search(nums, n, target);
return 0;
}
