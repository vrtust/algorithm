#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<stack>
#include<unordered_set>
#include<queue>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
    // if (nums.size() == 0) return 1;
    // if (nums.size() == 1) return nums[0] == 1 ? 2 : 1;
    // sort(nums.begin(), nums.end());

    // int result = 1;
    // bool find = false;
    // for (int i = 0; i < nums.size(); i++) {
    //     if (nums[i] > 0) {
    //         int temp_result = result;
    //         if (result == nums[i]) {
    //             result++;
    //         } else {
    //             find = true;
    //             break;
    //         }

    //         while (i + 1 < nums.size() && temp_result == nums[i + 1]) {
    //             i++;
    //         }
    //     }
    // }

    // return result;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
            int j = nums[i] - 1;
            swap(nums[i], nums[j]);
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }

    return nums.size() + 1;
}

int main() {
    vector<int> nums = { 0,2,2,1,1 };
    auto result = firstMissingPositive(nums);

    return 0;
}