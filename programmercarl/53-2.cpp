#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;

int maxSubArray(vector<int>& nums) {
    // int max_num = -99999;
    // int count = 0;
    // for (int i = 0; i < nums.size(); i++) {
    //     count += nums[i];

    //     max_num = max(max_num, count);

    //     if (count < 0) count = 0;
    // }

    // return max_num;

    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int result = dp[0];

    for (int i = 1; i < nums.size(); i++) {
        dp[i] = max(nums[i], nums[i] + dp[i - 1]);
        result = max(dp[i], result);
    }

    return result;
}

int main() {
    vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };

    maxSubArray(nums);
}