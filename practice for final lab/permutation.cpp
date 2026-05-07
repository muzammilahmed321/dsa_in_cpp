#include <iostream>
#include <vector>
using namespace std;

// Recursive function to generate permutations
void permute(vector<int>& num, int start, vector<vector<int>>& result) {
    if (start >= num.size()) {
        result.push_back(num);  // ❌ Fixed: was "result=push_back(num)"
        return;
    }

    for (int i = start; i < num.size(); i++) {
        swap(num[start], num[i]);
        permute(num, start + 1, result);
        swap(num[start], num[i]); // backtrack
    }
}

// Helper function to start permutation
vector<vector<int>> getpermutation(vector<int>& num) {
    vector<vector<int>> result;
    permute(num, 0, result);
    return result;
}

int main() {
    vector<int> num = {1, 2, 3};
    vector<vector<int>> permutation = getpermutation(num);

    // Print all permutations
    for (const auto& perm : permutation) {
        for (int x : perm) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}




