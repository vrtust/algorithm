#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<math.h>
#include<unordered_set>

using namespace std;

int rob(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return max(nums[0], nums[1]);

    vector<int> dp(nums.size() + 1, 0);
    dp[1] = nums[0];
    dp[2] = max(nums[0], nums[1]);

    for (int i = 3; i <= nums.size(); i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
    }

    return dp[nums.size()];
}

int main() {
    vector<int> nums = { 2,1,1,2 };
    auto result = rob(nums);

    return 0;
}