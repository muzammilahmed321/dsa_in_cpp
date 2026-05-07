#include<iostream>
#include<stack>
#include<string>
using namespace std;
string preproces(string &s){
 stack<char>st;
for(char ch : s){
if(ch=='#'){
if(!st.empty()){
st.pop();
}

}
else{
st.push(ch);
}
}
string total;
while(!st.empty()){
    total=st.top()+total;
    st.pop();
}
return total;
}


int main(){
string s;
cin>>s;
cout<<endl;
string output=preproces(s);
cout<<"preprocessig string"<<output;

}
