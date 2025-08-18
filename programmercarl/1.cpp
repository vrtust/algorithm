#include<iostream>
#include<array>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> record;
    for (int i = 0; i < nums.size(); i++) {
        if (record.count(target - nums[i]) > 0) {
            return { record.find(target - nums[i])->second,i };
        }
        record.insert({ nums[i],i });
    }
    return {};
}

int main() {
    vector<int> nums = { 2,7,11,15 };
    int target = 9;
    twoSum(nums, target);
}