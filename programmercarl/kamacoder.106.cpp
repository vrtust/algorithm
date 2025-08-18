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
    int m = 5, n = 5;
    vector<vector<int>> grid = { {0,0,0,0,0},
                                 {0,1,0,1,0},
                                 {0,1,1,1,0},
                                 {0,1,1,1,0},
                                 {0,0,0,0,0} };
    int result = 0;

    // vector<vector<int>> words = { {0,1},{1,0},{0,-1},{-1,0} };
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         if (grid[i][j] == 1) {
    //             for (auto word : words) {
    //                 int next_x = i + word[0];
    //                 int next_y = j + word[1];
    //                 if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m || grid[next_x][next_y] == 0)
    //                     result++;
    //             }
    //         }
    //     }
    // }

    int count = 0;
    int cover = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                count++;
                if (i > 0 && grid[i - 1][j] == 1) cover++;
                if (j > 0 && grid[i][j - 1] == 1) cover++;
            }
        }
    }
    result = count * 4 - cover * 2;

    return 0;
}