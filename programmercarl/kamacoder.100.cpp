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

int area = 0;

void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited) {
    for (auto word : words) {
        int next_x = x + word[0];
        int next_y = y + word[1];
        if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size()) {
            continue;
        }
        if (!visited[next_x][next_y] && grid[next_x][next_y] == 1) {
            visited[next_x][next_y] = true;
            dfs(grid, next_x, next_y, visited);
            area++;
        }
    }
}

int main() {
    int m = 5, n = 4;
    vector<vector<int>> grid = { {1,1,0,0,0},{1,1,0,0,0},{0,0,1,0,0},{0,0,0,1,1} };
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int result = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                area = 1;
                visited[i][j] = true;
                dfs(grid, i, j, visited);
                result = max(area, result);
            }
        }
    }

    return 0;
}