#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    // 解法一，纯暴力
    // int result = 0;
    // for (int i = 0; i < nums.size(); i++) {
    //     if (nums[i] == val) {
    //         nums[i] = 9999;
    //         result++;
    //     }
    // }
    // sort(nums.begin(), nums.end());
    // return nums.size() - result;

    // 解法一，双指针，正常解法
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        // std::cout << "left: " << left << ", nums[left]: " << nums[left] << ", right: " << right << ", nums[right]: " << nums[right] << std::endl;
        if (nums[left] == val) {
            nums[left] = nums[right];
            right--;
        } else {
            left++;
        }
    }
    return left;
}

int main() {
    vector<int> nums = { 3,2,2,3 };   // 输入数组
    int val = 3; // 要移除的值
    vector<int> expectedNums = { 2,2 };  // 长度正确的预期答案。
    // 它以不等于 val 的值排序。
    int actualLength = 2;

    int k = removeElement(nums, val);

    if (k != expectedNums.size()) {
        std::cout << "Wrong!" << " k: " << k << ", expectedNums.size(): " << expectedNums.size() << std::endl;
    }

    for (int i = 0; i < actualLength; i++) {
        if (nums[i] != expectedNums[i]) {
            std::cout << "Wrong!" << " nums[" << i << "]: " << nums[i] << ", expectedNums[" << i << "]: " << expectedNums[i] << std::endl;
            break;
        }
    }

    return 0;
}