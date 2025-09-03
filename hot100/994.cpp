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

int orangesRotting(vector<vector<int>>& grid) {
    vector<vector<int>> wards = { {0,1},{1,0},{0,-1},{-1,0} };

    int goodOrangeCount = 0;
    int badOrangeCount = 0;
    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int, int>> que;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                badOrangeCount++;
                que.push(make_pair(i, j));
            } else if (grid[i][j] == 1) {
                goodOrangeCount++;
            }
        }
    }

    if (goodOrangeCount == 0) {
        return 0;
    } else if (badOrangeCount == 0) {
        return -1;
    }

    int min = 0;
    while (!que.empty() && goodOrangeCount != 0) {
        int size = que.size();
        while (size--) {
            auto cur = que.front();
            que.pop();

            for (const auto& ward : wards) {
                int next_x = cur.first + ward[0];
                int next_y = cur.second + ward[1];
                if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && grid[next_x][next_y] == 1) {
                    goodOrangeCount--;
                    badOrangeCount++;
                    grid[next_x][next_y] = 2;
                    que.push(make_pair(next_x, next_y));
                }
            }
        }
        min++;
    }

    if (goodOrangeCount != 0) return -1;
    else return min;
}

int main() {
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    auto result = orangesRotting(grid);

    return 0;
}