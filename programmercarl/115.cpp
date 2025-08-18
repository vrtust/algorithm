#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;

int numDistinct(string s, string t) {
    vector<vector<long long unsigned>> dp(s.size() + 1, vector<long long unsigned>(t.size() + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= s.size(); i++) {
        dp[i][0] = 1;
    }
    for (int j = 1; j <= t.size(); j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= s.size(); i++) {
        for (int j = 1; j <= t.size(); j++) {
            if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            else dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[s.size()][t.size()];
}

int main() {
    string s = "abc";
    string t = "ahbgdc";

    auto result = numDistinct(s, t);
}