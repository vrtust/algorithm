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
#include<cctype>

using namespace std;

string decodeString(string s) {
    stack<string> str;
    stack<int> nums;

    string cur_string = "";
    int cur_num = 0;
    for (char c : s) {
        if (isdigit(c)) {
            cur_num = 10 * cur_num + (c - '0');
        } else if (c == '[') {
            str.push(cur_string);
            nums.push(cur_num);
            cur_string = "";
            cur_num = 0;
        } else if (c == ']') {
            int k = nums.top();
            nums.pop();

            string repeat_str;
            while (k--) {
                repeat_str += cur_string;
            }

            cur_string = str.top() + repeat_str;
            str.pop();
        } else {
            cur_string += c;
        }
    }

    return cur_string;
}

int main() {
    string s = "3[a]2[bc]";
    auto result = decodeString(s);

    return 0;
}