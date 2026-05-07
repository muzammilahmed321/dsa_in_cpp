#include<iostream>
using namespace std;
int main(){
int r,c;

cout<<"enter row";
cin>>r;
cout<<"enter colomn";
cin>>c;
int onearr[r*c],n=0;
int arr[r][c];
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++)
    {

        cin>>arr[i][j];
    }
}
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++)
    {

    onearr[n]=arr[j][i];
     n++;
    }
}
for(int i=0;i<n;i++){
    cout<<onearr[i];
}
}
