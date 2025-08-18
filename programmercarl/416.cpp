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

int main() {
    vector<int> nums = { 3,3,3,4,5 };

    auto result = canPartition(nums);

    return 0;
}