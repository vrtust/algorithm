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

vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.size() == 0) return { -1,-1 };
    int left = 0;
    int right = nums.size() - 1;
    int mid = 0;

    while (left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            break;
        }
    }

    if (nums[mid] != target) {
        return { -1,-1 };
    }

    int start = mid;
    int end = mid;
    while (start >= 0 && nums[start] == nums[mid]) {
        start--;
    }
    start++;

    while (end < nums.size() && nums[end] == nums[mid]) {
        end++;
    }
    end--;

    return { start, end };
}

int main() {
    vector<int> nums = { 1,3,5,7 };
    auto result = searchRange(nums, 11);

    return 0;
}