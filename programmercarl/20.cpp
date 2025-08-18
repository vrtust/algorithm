#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) {
    if (s.empty()) return true;

    stack<char> stack_s;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stack_s.push(c);
        } else if (!stack_s.empty() && ((c == ')' && stack_s.top() != '(') || (c == ']' && stack_s.top() != '[') || (c == '}' && stack_s.top() != '{'))) {
            return false;
        } else {
            stack_s.pop();
        }
    }

    if (!stack_s.empty()) {
        return false;
    }

    return true;
}

int main() {
    string s = "){";
    cout << isValid(s) << endl;
}