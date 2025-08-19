#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<stack>
#include<unordered_set>

using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> target(26, 0);
    for (int i = 0; i < p.size(); i++) {
        target[p[i] - 'a']++;
    }

    vector<int> cur(26, 0);
    vector<int> result;
    int left = 0;
    for (int i = 0; i < s.size(); i++) {
        cur[s[i] - 'a']++;
        if (cur[s[i] - 'a'] == target[s[i] - 'a']) {
            if (cur == target) {
                result.push_back(left);
                cur[s[left] - 'a']--;
                left++;
            }
        }

        while (cur[s[i] - 'a'] > target[s[i] - 'a'] && left <= i) {
            cur[s[left++] - 'a']--;
        }
    }

    return result;
}

int main() {
    string s = "cbaebabacd";
    string p = "abc";
    auto result = findAnagrams(s, p);

    return 0;
}