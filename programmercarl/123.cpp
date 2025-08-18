#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<math.h>
#include<unordered_set>

using namespace std;

int maxProfitOnce(vector<int>& prices, int start, int end) {
    int cur = start;
    int intrest = 0;
    for (int i = start + 1; i <= end; i++) {
        if (prices[i] > prices[cur]) {
            intrest = max(intrest, prices[i] - prices[cur]);
        } else {
            cur = i;
        }
    }
    return intrest;
}

int maxProfit(vector<int>& prices) {
    // 解1
    // int result = 0;

    // for (int i = 1; i < prices.size(); i++) {
    //     int val1 = maxProfitOnce(prices, 0, i - 1);
    //     int val2 = maxProfitOnce(prices, i, prices.size() - 1);
    //     result = max(result, val1 + val2);
    // }

    // result = max(result, maxProfitOnce(prices, 0, prices.size() - 1));

    // return result;

    // 解2
    // vector<vector<int>> dp(prices.size(), vector<int>(4, 0));

    // dp[0][0] = -prices[0];  // buy1
    // dp[0][1] = 0;           // sell1
    // dp[0][2] = -prices[0];  // buy2
    // dp[0][3] = 0;           // sell2

    // for (int i = 1; i < prices.size(); i++) {
    //     dp[i][0] = max(dp[i - 1][0], -prices[i]);
    //     dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    //     dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);
    //     dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
    // }

    // return dp[prices.size() - 1][3];

    // 解2-2
    int buy1 = -prices[0];  // buy1
    int sell1 = 0;           // sell1
    int buy2 = -prices[0];  // buy2
    int sell2 = 0;           // sell2

    for (int i = 1; i < prices.size(); i++) {
        sell2 = max(sell2, buy2 + prices[i]);
        buy2 = max(buy2, sell1 - prices[i]);
        sell1 = max(sell1, buy1 + prices[i]);
        buy1 = max(buy1, -prices[i]);
    }

    return sell2;
}

int main() {
    vector<int> nums = { 3,3,5,0,0,3,1,4 };
    auto result = maxProfit(nums);

    return 0;
}