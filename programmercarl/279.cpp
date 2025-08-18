#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<math.h>

using namespace std;

int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        double num = sqrt(i);
        int int_num = num;
        if (num - int_num == 0) {
            for (int j = i; j <= n; j++) {
                if (dp[j - i] != INT_MAX) {
                    dp[j] = min(dp[j - i] + 1, dp[j]);
                }
            }
        }
    }

    if (dp[n] == INT_MAX) return -1;
    return dp[n];
}

int main() {
    auto result = numSquares(12);

    return 0;
}