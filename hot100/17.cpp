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

void traval(string digits, vector<string>& result, string& path, vector<vector<char>> buttons, int cursor) {
    if (path.size() == digits.size()) {
        result.push_back(path);
        return;
    }

    int cur = digits[cursor] - '2';

    for (int i = 0; i < buttons[cur].size(); i++) {
        path.push_back(buttons[cur][i]);
        traval(digits, result, path, buttons, cursor + 1);
        path.pop_back();
    }

    return;
}

vector<string> letterCombinations(string digits) {
    if (digits == "") return{};
    vector<vector<char>> buttons = {
        {'a','b','c',},
        {'d','e','f',},
        {'g','h','i',},
        {'j','k','l',},
        {'m','n','o',},
        {'p','q','r','s',},
        {'t','u','v',},
        {'w','x','y','z',}
    };
    vector<string> result;
    string path;

    traval(digits, result, path, buttons, 0);

    return result;
}

int main() {
    string digits = "23";

    auto result = letterCombinations(digits);

    return 0;
}