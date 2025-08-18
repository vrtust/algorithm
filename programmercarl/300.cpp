#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<math.h>
#include<unordered_set>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size() + 1, 1);
    int result = 1;

    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j <= i; j++) {
            if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
        result = max(result, dp[i]);
    }

    return result;
}

int main() {
    vector<int> nums = { 10,9,2,5,3,7,101,18 };
    auto result = lengthOfLIS(nums);

    return 0;
}