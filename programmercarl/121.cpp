#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<math.h>
#include<unordered_set>

using namespace std;

int maxProfit(vector<int>& prices) {
    vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
    dp[0][0] -= prices[0];
    dp[0][1] = 0;

    for (int i = 1; i < prices.size(); i++) {
        dp[i][0] = max(dp[i - 1][0], -prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }

    return max(dp[prices.size() - 1][0], dp[prices.size() - 1][1]);
}

int main() {
    vector<int> prices = { 7,1,5,3,6,4 };
    auto result = maxProfit(prices);

    return 0;
}