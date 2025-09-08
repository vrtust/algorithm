#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<stack>
#include<unordered_set>
#include<queue>
#include<stack>
#include<set>

using namespace std;

bool isValid(string s) {
    stack<char> st;
    st.push(s[0]);

    for (int i = 1; i < s.size(); i++) {
        if (!st.empty() && s[i] != '(' && s[i] != '[' && s[i] != '{') {
            if ((st.top() == '(' && s[i] == ')') || (st.top() == '[' && s[i] == ']') || (st.top() == '{' && s[i] == '}')) {
                st.pop();
            } else {
                return false;
            }
        } else {
            st.push(s[i]);
        }
    }

    return st.empty();
}

int main() {
    string s = "()[]{}";
    auto result = isValid(s);

    return 0;
}