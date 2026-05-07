#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
int n;
cout<<"enter number of intervals:";
cin >> n;
vector<vector<int>> intervals(n, vector<int>(2));
cout<<"Enter intervals(start, end):"<<endl;
for(int i = 0; i < n; i++){
cin>>intervals[i][0]>>intervals[i][1];
}
sort(intervals.begin(), intervals.end());
vector<vector<int>> merge;
for (int i = 0; i < n; i++){
int start = intervals[i][0];
int end = intervals[i][1];
if (merge.empty()){
merge.push_back({start, end});
}else if(start <= merge.back()[1]) {
if(end > merge.back()[1]){
merge.back()[1] = end;
}}
else{
merge.push_back({start, end});
}
}
cout<<"\nMerged Intervals:";
for(int j = 0; j < merge.size(); j++) {
cout<<"["<<merge[j][0]<<","<<merge[j][1]<<"] ";
}
cout<<endl;
return 0;
}
