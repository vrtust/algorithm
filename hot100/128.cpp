#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    sort(nums.begin(), nums.end());
    vector<int> all_result(nums.size(), 1);

    int result = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] - 1 == nums[i - 1]) {
            result++;
            all_result[i] = result;
        } else if (nums[i] == nums[i - 1]) {
            continue;
        } else {
            result = 1;
        }
    }

    for (auto temp : all_result) {
        result = max(result, temp);
    }

    return result;
}

int main() {
    vector<int> nums = { 1,0,1,2 };
    auto result = longestConsecutive(nums);

    return 0;
}