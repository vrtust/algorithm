#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;

void backtracking(const vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& result) {
    result.push_back(path);
    if (start >= nums.size()) {
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        if (i > start && nums[i] == nums[i - 1]) {
            continue;
        }
        path.push_back(nums[i]);
        backtracking(nums, i + 1, path, result);
        path.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.empty()) return result;

    vector<int> path;

    sort(nums.begin(), nums.end());

    backtracking(nums, 0, path, result);
    return result;
}

int main() {
    vector<int> nums = { 1,2,3 };
    subsetsWithDup(nums);
}