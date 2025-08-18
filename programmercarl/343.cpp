#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;

int integerBreak(int n) {
    int result = 0;
    vector<int> dp(n + 1, 0);

    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= n; i++) {
        for (int j = 1; j <= i / 2; j++) {
            dp[i] = max(dp[i], j * max(i - j, dp[i - j]));
        }
    }

    return dp[n];
}

int main() {
    int n = 10;
    auto result = integerBreak(n);
}