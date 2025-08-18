#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
#include<stack>

using namespace std;

vector<vector<int>> words = { {0,1},{1,0},{0,-1},{-1,0} };

void dfs(vector<vector<int>>& grid, int x, int y) {
    grid[x][y] = 2;
    for (auto word : words) {
        int next_x = x + word[0];
        int next_y = y + word[1];
        if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size()) {
            continue;
        }
        if (grid[next_x][next_y] == 0 || grid[next_x][next_y] == 2) {
            continue;
        }
        dfs(grid, next_x, next_y);
    }
}

int main() {
    int m = 5, n = 4;
    vector<vector<int>> grid = { {1,1,0,0,0},{1,1,0,0,0},{0,0,1,0,0},{0,0,0,1,1} };
    int result = 0;

    for (int j = 0; j < m; j++) {
        if (grid[0][j] == 1) {
            dfs(grid, 0, j);
        }
        if (grid[n - 1][j] == 1) {
            dfs(grid, n - 1, j);
        }
    }

    for (int i = 0; i < n; i++) {
        if (grid[i][0] == 1) {
            dfs(grid, i, 0);
        }
        if (grid[i][m - 1] == 1) {
            dfs(grid, i, m - 1);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) grid[i][j] = 0;
            if (grid[i][j] == 2) grid[i][j] = 1;
        }
    }

    return 0;
}