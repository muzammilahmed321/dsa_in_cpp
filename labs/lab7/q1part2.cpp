#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int partition(vector<int>& arr, int st, int end) {
int idx = st - 1, pivot = arr[end];
for (int j=st; j<end; j++) {
if (arr[j]<=pivot) {
idx++;
swap(arr[j], arr[idx]);
}}
idx++;
swap(arr[end], arr[idx]);
return idx;}
void quickSortIterative(vector<int>& arr, int st, int end) {
stack<int> s;
s.push(st);
s.push(end);
while(!s.empty()){
end =s.top();
s.pop();
st=s.top();
s.pop();
if(st<end){
int middle=partition(arr, st, end);
if(middle+1< end){
s.push(middle+1);
s.push(end);
}
if(st<(middle-1)){
s.push(st);
s.push(middle-1);
}}}}
int main() {
vector<int> arr = {12, 31, 35, 8, 32, 17};
cout <<"\nbefore applying quick sort"<< endl;
for(int val : arr) {
cout<< val<<" ";
}
quickSortIterative(arr, 0, arr.size() - 1);
cout<< "\nafter applying quick sort non recursively using stack"<< endl;
for(int val:arr) {
cout <<val<< " ";
}
cout << endl;
}
