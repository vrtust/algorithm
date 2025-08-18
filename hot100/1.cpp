#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    // unordered_map<int, vector<int>> map;
    // for (int i = 0; i < nums.size(); i++) {
    //     map[nums[i]].push_back(i);
    // }

    // sort(nums.begin(), nums.end());
    // int l = 0;
    // int r = nums.size() - 1;

    // while (l <= r) {
    //     int sum = nums[l] + nums[r];
    //     if (sum > target) {
    //         r--;
    //     } else if (sum < target) {
    //         l++;
    //     } else {
    //         if (nums[l] == nums[r]) return map[nums[l]];
    //         else return { map[nums[l]][0], map[nums[r]][0] };
    //     }
    // }

    // return { -1,-1 };
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++) {
        if (hash.count(target - nums[i]) > 0) {
            return { hash[target - nums[i]], i };
        }
        hash[nums[i]] = i;
    }
    return { -1,-1 };
}

int main() {
    vector<int> nums = { 2,7,11,15 };
    int target = 9;
    auto result = twoSum(nums, target);

    return 0;
}