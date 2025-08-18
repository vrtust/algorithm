#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;

vector<vector<int>> result;
vector<int> path;

void backtracking(vector<int>& candidates, int target, int start_index) {
    int sum = 0;
    for (int i = 0; i < path.size(); i++) {
        sum += path[i];
    }
    if (sum == target) {
        result.push_back(path);
        return;
    } else if (sum > target) {
        return;
    }

    for (int i = start_index; i < candidates.size(); i++) {
        path.push_back(candidates[i]);
        backtracking(candidates, target, i);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    if (candidates.size() == 0) return result;
    backtracking(candidates, target, 0);
    return result;
}

int main() {
    // int n = 9;
    // int k = 3;
    // combinationSum3(n, k);
}