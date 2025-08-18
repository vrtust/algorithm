#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> stack_tokens;

    for (auto s : tokens) {
        if (s == "+") {
            int op1 = stack_tokens.top();
            stack_tokens.pop();
            int op2 = stack_tokens.top();
            stack_tokens.pop();
            stack_tokens.push(op2 + op1);
        } else if (s == "-") {
            int op1 = stack_tokens.top();
            stack_tokens.pop();
            int op2 = stack_tokens.top();
            stack_tokens.pop();
            stack_tokens.push(op2 - op1);
        } else if (s == "*") {
            int op1 = stack_tokens.top();
            stack_tokens.pop();
            int op2 = stack_tokens.top();
            stack_tokens.pop();
            stack_tokens.push(op2 * op1);
        } else if (s == "/") {
            int op1 = stack_tokens.top();
            stack_tokens.pop();
            int op2 = stack_tokens.top();
            stack_tokens.pop();
            stack_tokens.push(op2 / op1);
        } else {
            stack_tokens.push(stoi(s));
        }
    }

    return stack_tokens.top();
}

int main() {
    vector<string> tokens = { "4","13","5","/","+" };
    cout << evalRPN(tokens) << endl;
}