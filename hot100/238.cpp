#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<stack>
#include<unordered_set>
#include<queue>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> left(nums.size(), 0);
    vector<int> right(nums.size(), 0);

    left[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        left[i] = left[i-1] * nums[i];
    }

    right[nums.size() - 1] = nums[nums.size() - 1];
    for (int i = nums.size() - 2; i >= 0; i--) {
        right[i] = right[i+1] * nums[i];
    }

    vector<int> result(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++) {
        if (i == 0) {
            result[i] = right[i + 1];
        } else if (i == nums.size() - 1) {
            result[i] = left[i - 1];
        } else {
            result[i] = left[i - 1] * right[i + 1];
        }
    }

    return result;
}

int main() {
    vector<int> nums = { 1,2,3,4 };
    auto result = productExceptSelf(nums);

    return 0;
}