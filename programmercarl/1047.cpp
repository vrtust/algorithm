#include <iostream>
#include <stack>

using namespace std;

string removeDuplicates(string s) {
    // stack<char> stack_s;
    // for (char c : s) {
    //     if (!stack_s.empty() && c == stack_s.top()) {
    //         stack_s.pop();
    //         continue;
    //     }
    //     stack_s.push(c);
    // }

    // string result = "";
    // while (!stack_s.empty()) {
    //     result = stack_s.top() + result;
    //     stack_s.pop();
    // }
    // return result;

    string result;
    for(char c : s){
        if(!result.empty() && result.back() == c){
            result.pop_back();
        } else {
            result.push_back(c);
        }
    }
    return result;
}

int main() {
    string s = "abbaca";
    cout << removeDuplicates(s) << endl;
}