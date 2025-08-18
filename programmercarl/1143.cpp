#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<math.h>
#include<unordered_set>

using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    // vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));

    // for (int i = 0; i < text1.size(); i++) {
    //     for (int j = 0; j < text2.size(); j++) {
    //         if (j == 0) {
    //             if (text1[i] == text2[j]) dp[i][j] = 1;
    //             else if (i != 0) dp[i][j] = dp[i-1][j];
    //             continue;
    //         }
    //         if (i == 0) {
    //             if (text1[i] == text2[j]) dp[i][j] = 1;
    //             else dp[i][j] = dp[i][j - 1];
    //         } else {
    //             if (text1[i] == text2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
    //             else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    //         }
    //     }
    // }

    // return dp[text1.size() - 1][text2.size() - 1];

    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

    for (int i = 1; i <= text1.size(); i++) {
        for (int j = 1; j <= text2.size(); j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[text1.size()][text2.size()];
}

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    auto result = longestCommonSubsequence(text1, text2);

    return 0;
}