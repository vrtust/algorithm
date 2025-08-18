#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;

int climbStairs(int n, int m) {
    vector<int> dp(m + 1, 0);

    dp[0] = 1;

    for (int i = 1; i <= m; i++) {
        for (int j = i; j >= 0 && j >= i-n; j--) {
            dp[i] += dp[j];
        }
    }

    return dp[m];
}

int main() {
    auto result = climbStairs(2, 3);

    return 0;
}