#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<math.h>
#include<unordered_set>

using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    // vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
    // dp[0][0] = -prices[0];
    // dp[0][1] = 0;

    // for (int i = 1; i < prices.size(); i++) {
    //     dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
    //     dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
    // }

    // return dp[prices.size() - 1][1];

    int buy = -prices[0];
    int sell = 0;

    for (int i = 1; i < prices.size(); i++) {
        buy = max(buy, sell - prices[i]);
        sell = max(sell, buy + prices[i] - fee);
    }

    return sell;
}

int main() {
    vector<int> nums = { 1, 3, 2, 8, 4, 9 };
    int fee = 2;
    auto result = maxProfit(nums, fee);

    return 0;
}