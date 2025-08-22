#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<stack>
#include<unordered_set>
#include<queue>

using namespace std;

string minWindow(string s, string t) {
    vector<int> cur(60, 0);
    vector<int> target(60, 0);
    for (int i = 0; i < t.size(); i++) {
        target[t[i] - 'A']++;
    }

    int left = 0;
    int len = INT_MAX;
    int min_left = 0;
    int formed = 0;
    int requred = t.size();

    for (int i = 0; i < s.size(); i++) {
        int c = s[i] - 'A';
        cur[c]++;

        if (target[c] > 0 && cur[c] <= target[c]) {
            formed++;
        }
        while (requred == formed && left <= i) {
            if (len > i - left + 1) {
                len = i - left + 1;
                min_left = left;
            }
            int left_char = s[left] - 'A';
            if (target[left_char] > 0 && cur[left_char] <= target[left_char]) {
                formed--;
            }
            cur[left_char]--;
            left++;
        }
    }

    return len == INT_MAX ? "" : s.substr(min_left, len);
}

int main() {
    string s = "AABC";
    string t = "ABC";
    auto result = minWindow(s, t);

    return 0;
}