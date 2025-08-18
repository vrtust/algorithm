#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
#include<stack>
#include<list>

using namespace std;

int main() {
    int n = 6;
    int m = 7;
    int start = 2;
    int end = 6;
    int k = 1;

    vector<vector<int>> grid;
    grid.push_back({ 1,2,1 }); grid.push_back({ 2,4,-3 });
    grid.push_back({ 2,5,2 }); grid.push_back({ 1,3,5 });
    grid.push_back({ 3,5,1 }); grid.push_back({ 4,6,4 });
    grid.push_back({ 5,6,-2 });

    vector<int> minDst(n + 1, INT_MAX);
    vector<int> lastMinDst;
    minDst[start] = 0;
    bool circle = false;

    for (int i = 1; i <= k + 1; i++) {
        lastMinDst = minDst;
        for (auto& edge : grid) {
            if (lastMinDst[edge[0]] < INT_MAX && lastMinDst[edge[0]] + edge[2] < lastMinDst[edge[1]]) {
                minDst[edge[1]] = lastMinDst[edge[0]] + edge[2];
            }
        }
        cout << "对所有边松弛 " << i << "次" << endl;
        for (int k = 1; k <= n; k++) {
            cout << minDst[k] << " ";
        }
        cout << endl;
    }

    if (minDst[n] == INT_MAX) {
        cout << "unreachable" << endl;
    } else {
        cout << minDst[end] << endl;
    }

    return 0;
}