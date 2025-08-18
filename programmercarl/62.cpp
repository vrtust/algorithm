#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;

int uniquePaths(int m, int n) {
    if (m == 1 && n == 1) return 1;
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            else if (i == 0) dp[i][j] = 1;
            else if (j == 0) dp[i][j] = 1;
            else dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }

    return dp[m - 1][n - 1];
}

int main() {
    int m = 3;
    int n = 7;
    auto result = uniquePaths(m, n);
}