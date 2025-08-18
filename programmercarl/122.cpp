#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int max_num = -99999;
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        count += nums[i];

        max_num = max(max_num, count);

        if (count < 0) count = 0;
    }

    return max_num;
}

int main() {
    vector<int> nums = { 5,4,-1,7,8 };

    maxSubArray(nums);
}