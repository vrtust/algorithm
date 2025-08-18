#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;

void backtracking(const vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& result) {
    if (path.size() > 1) {
        result.push_back(path);
    }
    if (start >= nums.size()) {
        return;
    }

    // unordered_set<int> record;
    vector<int> record(200, 0);

    for (int i = start; i < nums.size(); i++) {
        // if (record.count(nums[i]) > 0 || (path.size() >= 1 && nums[i] < path[path.size() - 1])) {
        //     continue;
        // }
        if (record[nums[i] + 100] > 0 || (path.size() >= 1 && nums[i] < path[path.size() - 1])) {
            continue;
        }
        record[nums[i] + 100]++;
        path.push_back(nums[i]);
        backtracking(nums, i + 1, path, result);
        path.pop_back();
    }
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.empty()) return result;

    vector<int> path;

    backtracking(nums, 0, path, result);
    return result;
}

int main() {
    vector<int> nums = { 1,2,3 };
    findSubsequences(nums);
}