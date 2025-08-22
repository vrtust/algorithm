#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<stack>
#include<unordered_set>
#include<queue>

using namespace std;

void rotate(vector<int>& nums, int k) {
    // vector<int> result(nums.size(), 0);

    // for (int i = 0; i < nums.size(); i++) {
    //     result[(i + k) % nums.size()] = nums[i];
    // }

    // for (int i = 0; i < nums.size(); i++) {
    //     nums[i] = result[i];
    // }

    // return;

    // 超时
    // while (k--) {
    //     int temp = nums[nums.size() - 1];
    //     for (int i = nums.size() - 1; i > 0; i--) {
    //         nums[i] = nums[i - 1];
    //     }
    //     nums[0] = temp;
    // }

    if (nums.size() == 0) return;
    k = k % nums.size();
    if (k == 0) return;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

int main() {
    vector<int> nums = { 1,2,3,4,5,6,7 };
    int k = 3;
    rotate(nums, k);

    return 0;
}