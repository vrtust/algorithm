#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<math.h>
#include<unordered_set>

using namespace std;

int robUtil(vector<int>& nums, int start, int end) {
    if (start == end) return nums[start];
    if (end - start == 1) return max(nums[start], nums[end]);

    vector<int> dp(nums.size() + 1, 0);
    dp[start] = nums[start];
    dp[start + 1] = max(nums[start], nums[start + 1]);

    for (int i = start + 2; i <= end; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[end];
}

int rob(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return max(nums[0], nums[1]);

    int result1 = robUtil(nums, 0, nums.size() - 2);
    int result2 = robUtil(nums, 1, nums.size() - 1);

    return max(result1, result2);
}

int main() {
    vector<int> nums = { 1,2,3,1 };
    auto result = rob(nums);

    return 0;
}