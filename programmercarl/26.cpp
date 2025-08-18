#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[n]) {
            nums[++n] = nums[i];
        }
    }
    return n + 1;
}

int main() {
    vector<int> nums = { 1,1,2 };   // 输入数组
    vector<int> expectedNums = { 1,2 };  // 长度正确的预期答案。

    int k = removeDuplicates(nums);

    if (k != expectedNums.size()) {
        std::cout << "Wrong!" << " k: " << k << ", expectedNums.size(): " << expectedNums.size() << std::endl;
    }

    for (int i = 0; i < expectedNums.size(); i++) {
        if (nums[i] != expectedNums[i]) {
            std::cout << "Wrong!" << " nums[" << i << "]: " << nums[i] << ", expectedNums[" << i << "]: " << expectedNums[i] << std::endl;
            break;
        }
    }

    return 0;
}