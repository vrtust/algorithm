#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;

void backtracking(const vector<int>& nums, vector<int>& path, vector<vector<int>>& result) {
    if (path.size() == nums.size()) {
        result.push_back(path);
    }

    for (int i = 0; i < nums.size(); i++) {
        bool is_used = false;
        for (auto n : path) {
            if (n == nums[i]) {
                is_used = true;
                break;
            }
        }
        if (is_used) {
            continue;
        }

        path.push_back(nums[i]);
        backtracking(nums, path, result);
        path.pop_back();
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;

    vector<int> path;

    backtracking(nums, path, result);
    return result;
}

int main() {
    vector<int> nums = { 1,2,3 };
    permute(nums);
}