#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;

vector<string> result;
string path;

const string letterMap[10] = {
    "", // 0
    "", // 1
    "abc", // 2
    "def", // 3
    "ghi", // 4
    "jkl", // 5
    "mno", // 6
    "pqrs", // 7
    "tuv", // 8
    "wxyz", // 9
};

void backtracking(string digits, int index) {
    if (path.size() == digits.size()) {
        result.push_back(path);
        return;
    }

    int digit = digits[index] - '0';
    for (int i = 0; i < letterMap[digit].size(); i++) {
        path.push_back(letterMap[digit][i]);
        backtracking(digits, index + 1);
        path.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    if (digits.size() == 0) return result;
    backtracking(digits, 0);
    return result;
}

int main() {
    // int n = 9;
    // int k = 3;
    // combinationSum3(n, k);
}