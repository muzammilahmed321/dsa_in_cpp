#include<iostream>
#include<string>
using namespace std;
int main(){
string student[4]={"Muzammil","shazeeb","rehan","tafseer"};
float gpa[4][4]={{3.65,4,-1,3.8},
                {3.32,4,2,4},
                {3.2,3.6,-1,-1},
                {3,2,4,-1},
};
for(int i=0; i<4; i++){
float total=0;
int count=0;
for(int j=0; j<4;j++){
if(gpa[i][j]!=-1){
total+=gpa[i][j];
count++;
}}
float cgpa=(count>0)? total/count:0;
cout<<student[i]<<" cgpa ="<<cgpa<<endl;
}
return 0;
}
