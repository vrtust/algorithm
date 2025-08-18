#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;

bool canPartition(vector<int>& nums) {
    vector<int> dp(100 * 200 + 1, 0);

    int sum = 0;
    for (auto num : nums) {
        sum += num;
    }
    if (sum % 2 == 1) return false;
    int target = sum / 2;

    for (int i = 0; i < nums.size(); i++) {
        for (int j = target; j >= nums[i]; j--) {
            dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        }
    }

    if (dp[target] == target) return true;
    return false;
}

int lastStoneWeightII(vector<int>& stones) {
    vector<int> dp(30 * 100 / 2 + 1, 0);

    int sum = 0;
    for (auto stone : stones) {
        sum += stone;
    }
    int target = sum / 2;

    for (int i = 0; i < stones.size(); i++) {
        for (int j = target; j >= stones[i]; j--) {
            dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
        }
    }

    return sum - dp[target] - dp[target];
}

int main() {
    vector<int> nums = { 2,7,4,1,8,1 };

    auto result = lastStoneWeightII(nums);

    return 0;
}