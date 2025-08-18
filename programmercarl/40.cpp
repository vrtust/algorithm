#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;

vector<vector<int>> result;
vector<int> path;

void backtracking(vector<int>& candidates, int target, int start_index) {
    if (0 == target) {
        result.push_back(path);
        return;
    } else if (0 > target) {
        return;
    }

    for (int i = start_index; i < candidates.size(); i++) {
        // 跳过同一树层使用过的相同元素
        if (i > start_index && candidates[i] == candidates[i - 1]) {
            continue;
        }
        // 如果当前数字已经大于目标值，直接剪枝
        if (candidates[i] > target) {
            break;
        }

        path.push_back(candidates[i]);
        backtracking(candidates, target - candidates[i], i + 1);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    if (candidates.size() == 0) return result;
    sort(candidates.begin(), candidates.end());
    backtracking(candidates, target, 0);
    return result;
}

int main() {
    vector<int> candidates = { 10,1,2,7,6,1,5 };
    int target = 8;
    combinationSum2(candidates, target);
}