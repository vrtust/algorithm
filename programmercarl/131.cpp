#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;

vector<vector<string>> result;
vector<string> path;

void backtracking(string s, int start_index) {
    if (start_index >= s.size()) {
        result.push_back(path);
        return;
    }

    for (int i = start_index; i < s.size(); i++) {
        string temp_s = s.substr(start_index, i - start_index + 1);
        bool is_ok = true;
        for (int i = 0; i < temp_s.size() / 2; i++) {
            int n = temp_s.size();
            if (temp_s[i] != temp_s[temp_s.size() - i - 1]) {
                is_ok = false;
                break;
            }
        }
        if (is_ok) {
            path.push_back(temp_s);
        } else {
            continue;
        }

        backtracking(s, i + 1);
        path.pop_back();
    }
}

vector<vector<string>> partition(string s) {
    if (s.size() == 0) {
        return result;
    }

    backtracking(s, 0);
    return result;
}

int main() {
    string s = "aab";
    partition(s);
}