#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<stack>
#include<unordered_set>
#include<queue>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int sum = nums[0];
    int result = sum;

    for (int i = 1; i < nums.size(); i++) {
        sum = max(sum + nums[i], nums[i]);

        result = max(sum, result);
    }

    return result;
}

int main() {
    vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
    auto result = maxSubArray(nums);

    return 0;
}