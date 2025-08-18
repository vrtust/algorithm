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
    int start = 1;
    int end = n;

    vector<vector<int>> grid;
    grid.push_back({ 5,6,-2 }); grid.push_back({ 1,2,1 });
    grid.push_back({ 5,3,1 });  grid.push_back({ 2,5,2 });
    grid.push_back({ 2,4,-3 }); grid.push_back({ 4,6,4 });
    grid.push_back({ 1,3,5 });

    vector<int> minDst(n + 1, INT_MAX);
    minDst[start] = 0;
    bool circle = false;

    for (int i = 1; i <= n; i++) {
        if (i < n) {
            for (auto edge : grid) {
                if (minDst[edge[0]] < INT_MAX && minDst[edge[0]] + edge[2] < minDst[edge[1]]) {
                    minDst[edge[1]] = minDst[edge[0]] + edge[2];
                }
            }
        } else {
            for (auto edge : grid) {
                if (minDst[edge[0]] < INT_MAX && minDst[edge[0]] + edge[2] < minDst[edge[1]]) {
                    circle = true;
                    break;
                }
            }
        }
        cout << "对所有边松弛 " << i << "次" << endl;
        for (int k = 1; k <= n; k++) {
            cout << minDst[k] << " ";
        }
        cout << endl;
    }

    if (circle) {
        cout << "circle" << endl;
    } else if (minDst[n] == INT_MAX) {
        cout << "unconnected" << endl;
    } else {
        cout << minDst[n] << endl;
    }

    return 0;
}