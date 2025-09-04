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

void traval(vector<int>& nums, vector<vector<int>>& result, vector<int>& path, vector<int>& record) {
    if (path.size() == nums.size()) {
        result.push_back(path);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (record[i] == 0) {
            record[i]++;
            path.push_back(nums[i]);
            traval(nums, result, path, record);
            record[i]--;
            path.pop_back();
        }
    }

    return;
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> path;
    vector<int> record(nums.size(), 0);

    traval(nums, result, path, record);

    return result;
}

int main() {
    vector<int> nums = { 1,2,3 };

    auto result = permute(nums);

    return 0;
}