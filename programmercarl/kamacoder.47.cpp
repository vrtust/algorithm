#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
#include<stack>

using namespace std;

int main() {
    int n = 7;
    int m = 9;
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, INT_MAX));
    grid[1][2] = 1; grid[1][3] = 4; grid[2][3] = 2; grid[2][4] = 5;
    grid[3][4] = 2; grid[4][5] = 3; grid[2][6] = 4; grid[5][7] = 4;
    grid[6][7] = 9;

    vector<int> minDst(n + 1, INT_MAX);
    vector<bool> visited(n + 1, false);
    minDst[1] = 0;
    vector<int> parent(n + 1, 0);

    for (int i = 1; i < n; i++) {
        int cur = -1;
        int minNum = INT_MAX;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && minDst[j] < minNum) {
                cur = j;
                minNum = minDst[j];
            }
        }

        if (cur == -1) {
            break;
        }

        visited[cur] = true;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && grid[cur][j] != INT_MAX && minDst[cur] + grid[cur][j] < minDst[j]) {
                minDst[j] = minDst[cur] + grid[cur][j];
                parent[j] = cur;
            }
        }
    }

    if (minDst[n] == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << minDst[n] << endl;
    }

    for (int i = 1; i <= n; i++) {
        cout << parent[i] << "->" << i << endl;
    }

    return 0;
}