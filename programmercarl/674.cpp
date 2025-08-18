#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<math.h>
#include<unordered_set>

using namespace std;

int findLengthOfLCIS(vector<int>& nums) {
    // 解1
    // int result = 1;

    // for (int i = 0; i < nums.size(); i++) {
    //     int temp = 1;
    //     for (int j = i; j > 0; j--) {
    //         if (nums[j] > nums[j - 1]) temp++;
    //         else break;
    //     }
    //     result = max(result, temp);
    // }

    // return result;

    // 解2
    vector<int> dp(nums.size() + 1, 1);
    int result = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i - 1]) dp[i] = dp[i - 1] + 1;
        result = max(dp[i], result);
    }

    return result;
}

int main() {
    vector<int> nums = { 1,3,5,4,2,3,4,5 };
    auto result = findLengthOfLCIS(nums);

    return 0;
}