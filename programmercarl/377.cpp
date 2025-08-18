#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;

int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1, 0);

    dp[0] = 1;

    for (int i = 0; i <= target; i++) {
        for (int j = 0; j < nums.size(); j++) {
            if (i >= nums[j] && dp[i] <= INT_MAX - dp[i - nums[j]]) {
                dp[i] += dp[i - nums[j]];
            }
        }
    }

    return dp[target];
}

int main() {
    vector<int> nums = { 1, 2, 5 };
    int target = 5;

    auto result = combinationSum4(nums, target);

    return 0;
}