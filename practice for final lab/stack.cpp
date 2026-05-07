#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool ispalindrom(string s){
    stack<char> st;
for(char ch : s){
st.push(ch);
}
for(char ch : s){
char top=st.top();
st.pop();
if(ch !=top){
return false;
}
}
return true;


}
int main(){
string c;
cin>>c;
if(ispalindrom(c)){
cout<<"true";
}
else{
cout<<"\n false";
}
return 0;

}



