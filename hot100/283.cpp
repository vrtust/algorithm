#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>

using namespace std;

void moveZeroes(vector<int>& nums) {
    int n = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[n++] = nums[i];
        }
    }

    for (int i = n; i < nums.size(); i++) {
        nums[i] = 0;
    }
}

int main() {
    vector<int> nums = { 1,0,1,2 };
    moveZeroes(nums);

    return 0;
}