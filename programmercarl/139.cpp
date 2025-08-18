#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<math.h>
#include<unordered_set>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> allWord(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;

    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j < i; j++) {
            string word = s.substr(j, i - j);
            if (allWord.find(word) != allWord.end() && dp[j]) {
                dp[i] = true;
            }
        }
    }

    return dp[s.size()];
}

int main() {
    string s = "leetcode";
    vector<string> wordDict = { "leet", "code" };
    auto result = wordBreak(s, wordDict);

    return 0;
}