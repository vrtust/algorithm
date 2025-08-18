#include<iostream>
#include<array>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    if (nums.size() < 4) return {};
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;

    for (int j = 0; j < nums.size() - 3; j++) {
        if (j > 0 && nums[j] == nums[j - 1]) {
            continue;
        }
        for (int i = j + 1; i < nums.size() - 2; i++) {
            if (i > j + 1 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                if ((long long)nums[i] + nums[left] + nums[right] == (long long)target - nums[j]) {
                    result.push_back({ nums[j],nums[i],nums[left],nums[right] });
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while ((long long)left < right && nums[right] == (long long)nums[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;
                } else if ((long long)nums[i] + nums[left] + nums[right] > (long long)target - nums[j]) {
                    right--;
                } else {
                    left++;
                }
            }
        }
    }

    return result;
}

int main() {
    vector<int> nums = { 2,2,2,2 };

    fourSum(nums, 8);
}