#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;

int longestPalindromeSubseq(string s) {
    // string t = s;
    // reverse(t.begin(), t.end());

    // vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, 0));
    // for (int i = 1; i <= s.size(); i++) {
    //     for (int j = 1; j <= t.size(); j++) {
    //         if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
    //         else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    //     }
    // }

    // return dp[s.size()][t.size()];

    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
    for (int i = 0; i < s.size(); i++) dp[i][i] = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        for (int j = i + 1; j < s.size(); j++) {
            if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
            else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }

    return dp[0][s.size() - 1];
}

int main() {
    string s = "bbbab";

    auto result = longestPalindromeSubseq(s);
}