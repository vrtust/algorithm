#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;

int largestSumAfterKNegations(vector<int>& nums, int k) {
    int min_num = 101;
    int min_index = 0;
    int sum = 0;
    bool have_sum = false;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < nums.size(); j++) {
            if (min_num > nums[j]) {
                min_num = nums[j];
                min_index = j;
            }
            if (!have_sum) {
                sum += nums[j];
            }
        }
        have_sum = true;

        sum = sum - nums[min_index] * 2;
        nums[min_index] = -nums[min_index];
        min_num = 101;
        min_index = 0;
    }

    return sum;
}

int main() {
    vector<int> nums = { 2,-3,-1,5,-4 };
    int k = 2;

    largestSumAfterKNegations(nums, k);
}