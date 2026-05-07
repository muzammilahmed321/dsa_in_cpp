#include <iostream>
#include <vector>
using namespace std;
void permute(vector<int>& nums, int start, vector<vector<int>>& result) {
if (start >= nums.size()) {
result.push_back(nums);
return;
}
for (int i = start; i < nums.size(); i++) {
swap(nums[start], nums[i]);
permute(nums, start + 1, result);
swap(nums[start], nums[i]);
}
}
vector<vector<int>> getPermutations (vector<int>& nums) {
vector<vector<int>> result;
permute(nums, 0, result);
return result;
}
int main() {
vector<int> nums = {1,2,3};
vector<vector<int>> permutations = getPermutations (nums);
cout << "All permutations:\n";
for (const auto& perm: permutations) {
for (int num: perm) {
cout << num << " ";
}
cout << endl;
}
return 0;
}
