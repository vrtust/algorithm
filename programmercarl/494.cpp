#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;

int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    for (auto num : nums) {
        sum += num;
    }
    int A = (sum + target) / 2;

    if (abs(target) > sum || (sum + target) % 2 != 0) {
        return 0;
    }

    vector<int> dp(A + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < nums.size(); i++) {
        for (int j = A; j >= nums[i]; j--) {
            dp[j] = dp[j] + dp[j - nums[i]];
        }
    }

    return dp[A];
}

int main() {
    vector<int> nums = { 1,1,1,1,1 };
    int target = 3;

    auto result = findTargetSumWays(nums, target);

    return 0;
}