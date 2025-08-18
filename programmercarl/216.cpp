#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;

vector<vector<int>> result;
vector<int> path;

void backTracking(int n, int k, int start_index) {
    if (path.size() == k) {
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += path[i];
        }
        if (sum == n) {
            result.push_back(path);
        }
        return;
    }

    for (int i = start_index; i <= 9; i++) {
        path.push_back(i);
        backTracking(n, k, i + 1);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    backTracking(n, k, 1);
    return result;
}

int main() {
    int n = 9;
    int k = 3;
    combinationSum3(n, k);
}