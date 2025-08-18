#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;

int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (auto& str : strs) {
        int zero = 0;
        int one = 0;
        for (auto c : str) {
            if (c == '0') zero++;
            else one++;
        }

        for (int i = m; i >= zero; i--) {
            for (int j = n; j >= one; j--) {
                dp[i][j] = max(dp[i][j], dp[i - zero][j - one] + 1);
            }
        }
    }

    return dp[m][n];
}

int main() {
    vector<string> strs = { "10", "0001", "111001", "1", "0" };
    int m = 5;
    int n = 3;

    auto result = findMaxForm(strs, m, n);

    return 0;
}