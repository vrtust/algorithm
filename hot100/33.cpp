#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<stack>
#include<unordered_set>
#include<queue>
#include<stack>
#include<set>

using namespace std;

int search(vector<int>& nums, int target) {
    if (nums.size() == 0) {
        return -1;
    } else if (nums.size() == 1) {
        if (nums[0] == target) {
            return 0;
        } else {
            return -1;
        }
    }
    int total_left = 0;
    int total_right = nums.size() - 1;
    while (total_left < total_right) {
        int mid = (total_left + total_right) / 2;
        if (nums[mid] > nums[total_right]) {
            total_left = mid + 1;
        } else {
            total_right = mid;
        }
    }

    int min_num = total_left;
    int left = 0;
    int right = 0;
    if (target >= nums[0]) {
        left = 0;
        right = min_num - 1;
        if (min_num == 0) {
            right = nums.size() - 1;
        }
    } else {
        left = min_num;
        right = nums.size() - 1;
    }

    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = { 1,3 };
    auto result = search(nums, 3);

    return 0;
}