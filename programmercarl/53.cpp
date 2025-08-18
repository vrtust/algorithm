#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.size() < 2) {
        return 0;
    }

    int intrest = 0;
    int cur = 0;

    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] - prices[cur] < 0) {
            cur = i;
            continue;
        } else {
            intrest += prices[i] - prices[cur];
            cur = i;
        }
    }

    return intrest;
}

int main() {
    vector<int> nums = { 5,4,-1,7,8 };

    maxProfit(nums);
}