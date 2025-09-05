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

bool isValid(string s, int start, int end) {
    for (int i = start, j = end; i < j; i++, j--) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

void traval(string s, vector<vector<string>>& result, vector<string>& path, int start) {
    if (start == s.size()) {
        result.push_back(path);
        return;
    }

    for (int i = start; i < s.size(); i++) {
        if (isValid(s, start, i)) {
            path.push_back(s.substr(start, i - start + 1));
            traval(s, result, path, i + 1);
            path.pop_back();
        }
    }

    return;
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> path;

    traval(s, result, path, 0);

    return result;
}

int main() {
    string s = "aab";

    auto result = partition(s);

    return 0;
}