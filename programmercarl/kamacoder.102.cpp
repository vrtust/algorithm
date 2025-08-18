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

int bfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited) {
    queue<pair<int, int>> que;
    que.push({ x,y });
    int area = 1;
    bool out = false;
    vector<vector<int>> record;
    record.push_back({ x,y });

    while (!que.empty()) {
        auto cur = que.front();
        que.pop();
        if (cur.first == 0 || cur.first == grid.size() - 1 || cur.second == 0 || cur.second == grid[0].size() - 1) {
            out = true;
        }
        for (auto word : words) {
            int next_x = cur.first + word[0];
            int next_y = cur.second + word[1];
            if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size()) {
                continue;
            }
            if (!visited[next_x][next_y] && grid[next_x][next_y] == 1) {
                que.push({ next_x, next_y });
                visited[next_x][next_y] = true;
                area++;
                record.push_back({ next_x,next_y });
            }
        }
    }

    if (!out) {
        for (auto node : record) {
            grid[node[0]][node[1]] = 0;
        }
    }

    return out ? 0 : area;
}

int main() {
    int m = 5, n = 4;
    vector<vector<int>> grid = { {1,1,0,0,0},{1,1,0,0,0},{0,0,1,0,0},{0,0,0,1,1} };
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int result = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                visited[i][j] = true;
                result += bfs(grid, i, j, visited);
            }
        }
    }

    return 0;
}