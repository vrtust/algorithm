#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void moveZeroes(vector<int>& nums) {
    int n = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[n++] = nums[i];
        }
    }

    for(int i = n; i < nums.size(); i++){
        nums[i] = 0;
    }
}

int main() {
    vector<int> nums = { 0,1,0,3,12 };   // 输入数组
    vector<int> expectedNums = { 1,3,12,0,0 };  // 长度正确的预期答案。

    moveZeroes(nums);

    for (int i = 0; i < expectedNums.size(); i++) {
        if (nums[i] != expectedNums[i]) {
            std::cout << "Wrong!" << " nums[" << i << "]: " << nums[i] << ", expectedNums[" << i << "]: " << expectedNums[i] << std::endl;
            break;
        }
    }

    return 0;
}