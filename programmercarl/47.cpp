#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;

void backtracking(const vector<int>& nums, vector<int>& path, vector<vector<int>>& result, vector<int>& record) {
    if (path.size() == nums.size()) {
        result.push_back(path);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int used_count = 0;
        for (auto n : path) {
            if (n == nums[i]) {
                used_count++;
            }
        }
        if (used_count == record[nums[i] + 10]) {
            continue;
        }

        path.push_back(nums[i]);
        backtracking(nums, path, result, record);
        path.pop_back();
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> path;
    vector<int> record(21, 0);

    sort(nums.begin(), nums.end());
    for (auto num : nums) {
        record[num + 10]++;
    }

    backtracking(nums, path, result, record);
    return result;
}

int main() {
    vector<int> nums = { 1,2,3 };
    permuteUnique(nums);
}