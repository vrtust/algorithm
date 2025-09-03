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

vector<vector<int>> wards = { {0,1},{1,0},{0,-1},{-1,0} };

void dfs(vector<vector<char>>& grid, int x, int y) {
    grid[x][y] = '0';
    for (const auto& ward : wards) {
        int next_x = x + ward[0];
        int next_y = y + ward[1];
        if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size()) {
            continue;
        }
        if (grid[next_x][next_y] == '0') {
            continue;
        }
        dfs(grid, next_x, next_y);
    }
}

int numIslands(vector<vector<char>>& grid) {
    int result = 0;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '0') {
                continue;
            }
            dfs(grid, i, j);
            result++;
        }
    }

    return result;
}

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    auto result = numIslands(grid);

    return 0;
}