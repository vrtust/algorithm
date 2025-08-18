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

void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int mark) {
    visited[x][y] = true;
    grid[x][y] = mark;
    area++;
    for (auto word : words) {
        int next_x = x + word[0];
        int next_y = y + word[1];
        if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size()) {
            continue;
        }
        if (!visited[next_x][next_y] && grid[next_x][next_y] == 1) {
            dfs(grid, visited, next_x, next_y, mark);
        }
    }
}

int main() {
    int m = 5, n = 4;
    vector<vector<int>> grid = { {1,1,0,0,0},{1,1,0,0,0},{0,0,1,0,0},{0,0,0,1,1} };

    vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(m, false));
    unordered_map<int, int> grid_num;
    int result = 0;

    int mark = 2;
    bool is_grid = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) is_grid = false;
            if (!visited[i][j] && grid[i][j] == 1) {
                area = 0;
                dfs(grid, visited, i, j, mark);
                grid_num[mark] = area;
                mark++;
            }
        }
    }

    if (is_grid) {
        result = n * m;
        cout << result << endl;
    } else {
        unordered_set<int> visited_grid;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) continue;
                area = 1;
                visited_grid.clear();
                for (auto word : words) {
                    int next_x = i + word[0];
                    int next_y = j + word[1];
                    if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size()) {
                        continue;
                    }
                    if (!visited_grid.count(grid[next_x][next_y])) {
                        visited_grid.insert(grid[next_x][next_y]);
                        area += grid_num[grid[next_x][next_y]];
                    }
                }
                result = max(result, area);
            }
        }
    }

    return 0;
}