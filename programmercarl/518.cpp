#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;

int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);

    dp[0] = 1;

    for (int i = 0; i < coins.size(); i++) {
        for (int j = coins[i]; j <= amount; j++) {
            if (dp[j] < INT_MAX - dp[j - coins[i]]) {
                dp[j] += dp[j - coins[i]];
            }
        }
    }

    return dp[amount];
}

int main() {
    vector<int> coins = { 1, 2, 5 };
    int amount = 5;

    auto result = change(amount, coins);

    return 0;
}