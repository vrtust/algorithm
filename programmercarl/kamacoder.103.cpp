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

void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
    visited[x][y] = true;
    for (auto word : words) {
        int next_x = x + word[0];
        int next_y = y + word[1];
        if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size()) {
            continue;
        }
        if (!visited[next_x][next_y] && grid[x][y] <= grid[next_x][next_y]) {
            dfs(grid, visited, next_x, next_y);
        }
    }
}

int main() {
    int m = 5, n = 5;
    vector<vector<int>> grid = { {1,3,1,2,4},
                                 {1,2,1,3,2},
                                 {2,4,7,2,1},
                                 {4,5,6,1,1},
                                 {1,4,1,2,1} };
    vector<vector<bool>> first_border(n, vector<bool>(m, false));
    vector<vector<bool>> second_border(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        dfs(grid, first_border, i, 0);
        dfs(grid, second_border, i, m - 1);
    }

    for (int j = 0; j < m; j++) {
        dfs(grid, first_border, 0, j);
        dfs(grid, second_border, n - 1, j);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (first_border[i][j] && second_border[i][j]) {
                cout << i << " " << j << endl;
            }
        }
    }

    return 0;
}