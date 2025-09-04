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

void traval(vector<int>& candidates, vector<vector<int>>& result, vector<int>& path, int target, int cursor, int sum) {
    if (sum == target) {
        result.push_back(path);
        return;
    }

    for (int i = cursor; i < candidates.size(); i++) {
        sum += candidates[i];
        if (sum > target) break;

        path.push_back(candidates[i]);

        traval(candidates, result, path, target, i, sum);

        sum -= candidates[i];
        path.pop_back();
    }

    return;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> path;

    sort(candidates.begin(), candidates.end());

    traval(candidates, result, path, target, 0, 0);

    return result;
}

int main() {
    vector<int> candidates = { 2,3,6,7 };

    auto result = combinationSum(candidates, 7);

    return 0;
}