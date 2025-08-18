#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;

bool canJump(vector<int>& nums) {
    int cover = 0;

    for (int i = 0; i <= cover; i++) {
        cover = max(cover, i + nums[i]);
        if (cover >= nums.size() - 1) return true;
    }

    return false;
}

int main() {
    vector<int> nums = { 3,2,1,0,4 };

    canJump(nums);
}