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
        result.push_back(path);
        return;
    }

    for (int i = start_index; i <= n - (k - path.size()) + 1; i++) {
        path.push_back(i);
        backTracking(n, k, i + 1);
        path.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    backTracking(n, k, 1);
    return result;
}

int main() {

}