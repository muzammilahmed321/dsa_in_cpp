#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isPalindrome(string s) {
stack<char> st;


for (char ch : s) {
st.push(ch);
    }


for (char ch : s) {
char topChar = st.top();
st.pop();
if (ch != topChar) {
return false;
        }
    }
return true;
}

int main() {
string input;
cout << "Enter a string: ";
cin >> input;

if (isPalindrome(input)) {
cout << "The string is a palindrome." << endl;
} else {
cout << "The string is not a palindrome." << endl;
    }
return 0;
}
