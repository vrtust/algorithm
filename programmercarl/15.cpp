#include<iostream>
#include<array>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;

    for (int i = 0; i < nums.size() - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int left = i + 1;
        int right = nums.size() - 1;
        while (left < right) {
            if (nums[i] + nums[left] + nums[right] == 0) {
                result.push_back({ nums[i],nums[left],nums[right] });
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }
                left++;
                right--;
            } else if (nums[i] + nums[left] + nums[right] > 0) {
                right--;
            } else {
                left++;
            }
        }
    }

    return result;
}

int main() {
    vector<int> nums = { 0,0,0 };

    threeSum(nums);
}