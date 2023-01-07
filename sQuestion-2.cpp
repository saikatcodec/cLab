#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s;
    cout << "Enter bracket: ";
    cin >> s;

    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (!st.empty()) {
            char front = st.top();
            if (front == '(' && s[i] == ')') {
                st.pop();
            } else if (front == '[' && s[i] == ']') {
                st.pop();
            } else if (front == '{' && s[i] == '}') {
                st.pop();
            } else {
                st.push(s[i]);
            }
        } else {
            st.push(s[i]);
        }
    }

    if (st.empty()) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}