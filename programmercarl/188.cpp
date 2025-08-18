#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<math.h>
#include<unordered_set>

using namespace std;

int maxProfit(int k, vector<int>& prices) {
    vector<int> result(2 * k, 0);

    for (int i = 0; i < 2 * k; i = i + 2) {
        result[i] = -prices[0];
    }

    for (int i = 0; i < prices.size(); i++) {
        for (int j = 2 * k - 1; j > 0; j--) {
            if ((j + 1) % 2 == 0) result[j] = max(result[j], result[j - 1] + prices[i]);
            else result[j] = max(result[j], result[j - 1] - prices[i]);
        }
        result[0] = max(result[0], -prices[i]);
    }

    return result[2 * k - 1];
}

int main() {
    vector<int> nums = { 2,4,1 };
    int k = 2;
    auto result = maxProfit(k, nums);

    return 0;
}