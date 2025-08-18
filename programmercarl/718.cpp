#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<math.h>
#include<unordered_set>

using namespace std;

int findLength(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));
    int result = 0;

    for (int i = 0; i < nums1.size(); i++) {
        for (int j = 0; j < nums2.size(); j++) {
            if (nums1[i] == nums2[j]) {
                if (i == 0) dp[i][j]++;
                else if (j == 0) dp[i][j]++;
                else dp[i][j] = dp[i - 1][j - 1] + 1;
                result = max(result, dp[i][j]);
            }
        }
    }

    return result;
}

int main() {
    vector<int> nums1 = { 1,2,3,2,1 };
    vector<int> nums2 = { 3,2,1,4,7 };
    auto result = findLength(nums1, nums2);

    return 0;
}