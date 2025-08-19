#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<stack>
#include<unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int result = 0;
    int len = 0;
    unordered_set<char> count;
    int left = 0;
    for (int i = 0; i < s.size(); i++) {
        len++;
        if (count.count(s[i]) != 0) {
            while (count.count(s[i]) > 0 && left < s.size()) {
                count.erase(s[left++]);
                len--;
            }
        }
        count.insert(s[i]);
        result = max(result, len);
    }

    return result;
}

int main() {
    string s = "dvdf";
    auto result = lengthOfLongestSubstring(s);

    return 0;
}