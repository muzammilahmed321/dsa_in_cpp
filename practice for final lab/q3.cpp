#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class find_median{

vector<int> nums;
public:
    void add_nums(int num){
    nums.push_back(num);
    sort(nums.begin(),nums.end());
    }
    double median(){
     int n=nums.size();
    if(n%2==0){
        return (nums[n/2-1]+nums[n/2])/2.0;
    }
    return nums[n/2];
    }
};
int main(){
    find_median mf;
    mf.add_nums(1);
    mf.add_nums(2);
    cout<<mf.median()<<endl;

}
