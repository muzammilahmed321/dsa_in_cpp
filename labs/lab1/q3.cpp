#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MedianFinder {
    vector<int> nums;
public:
    void addNum(int num) {
        nums.push_back(num);
        sort(nums.begin(), nums.end());
    }
    double findMedian() {
        int n = nums.size();
        if (n % 2 == 0) return (nums[n/2 - 1] + nums[n/2]) / 2.0;
        return nums[n/2];
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << mf.findMedian() << endl;
    mf.addNum(3);
    cout << mf.findMedian() << endl;
    return 0;
}
