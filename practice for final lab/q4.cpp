#include<iostream>
using namespace std;
int binary_search(int arr[],int n,int target){
    int l=0,r=n-1;
while(l<=r){
   int mid=l+(r-l)/2;
   if(arr[mid]==target){
        return mid;
   }
   else if(arr[mid]<target)
   {l=mid+1;
   }
   else {r=mid-1;
   }
}
return -1;
}
int main(){
    int n,target;

cout<<"ENTER NUMBER OF TERM REQUIRED:";
cin>>n;
cout<<endl;
cout<<"enter target";
cin>>target;
cout<<endl;
 int arr[n];
for(int i=0;i<n;i++) cin>> arr[i];
    cout<<endl;
cout<<"target index:";
cout<<binary_search(arr,n,target);

}
