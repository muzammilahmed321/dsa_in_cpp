#include <iostream>
#include <stack>
#include <string>
using namespace std;

string processString(const string& str) {
    stack<char> st;

    for (char ch : str) {
        if (ch == '#') {
            if (!st.empty()) {
                st.pop();
            }
        } else {
            st.push(ch);
        }
    }

    string result;
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }
    return result;
}

int main() {
    string input;
    cout << "Enter a string (use # as backspace): ";
    cin >> input;

    string output = processString(input);
    cout << "Processed string: " << output << endl;

    return 0;
}
