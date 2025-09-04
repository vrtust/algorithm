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

void traval(vector<int>& nums, vector<vector<int>>& result, vector<int>& path, int target, int cursor) {
    if (path.size() == target) {
        result.push_back(path);
        return;
    }

    for (int i = cursor; i < nums.size(); i++) {
        path.push_back(nums[i]);
        traval(nums, result, path, target, i + 1);
        path.pop_back();
    }

    return;
}


vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> path;

    for (int i = 0; i <= nums.size(); i++) {
        traval(nums, result, path, i, 0);
    }

    return result;
}

int main() {
    vector<int> nums = { 1,2,3 };

    auto result = subsets(nums);

    return 0;
}