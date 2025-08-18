#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid.size() == 1 && obstacleGrid[0].size() == 1 && obstacleGrid[0][0] != 1) return 1;
    else if (obstacleGrid.size() == 1 && obstacleGrid[0].size() == 1 && obstacleGrid[0][0] == 1) return 0;

    if (obstacleGrid[0][0] == 1) return 0;

    vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));

    for (int i = 0; i < obstacleGrid.size(); i++) {
        for (int j = 0; j < obstacleGrid[0].size(); j++) {
            if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
            else if (i == 0 && j == 0) continue;

            else if (i == 0 && j == 1 && obstacleGrid[i][j] != 1) dp[i][j] = 1;
            else if (i == 0 && j == 1 && obstacleGrid[i][j] == 1) dp[i][j] = 0;
            else if (i == 0) dp[i][j] = dp[i][j - 1];

            else if (j == 0 && i == 1 && obstacleGrid[i][j] != 1) dp[i][j] = 1;
            else if (j == 0 && i == 1 && obstacleGrid[i][j] == 1) dp[i][j] = 0;
            else if (j == 0) dp[i][j] = dp[i - 1][j];

            else if (obstacleGrid[i][j] != 1) dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            else if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
        }
    }

    return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
}

int main() {
    vector<vector<int>> obstacleGrid = {
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {1, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {1, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 1},
        {0, 0},
        {0, 0},
        {1, 0},
        {0, 0},
        {0, 0},
        {0, 1},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 1},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {1, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0} };
    auto result = uniquePathsWithObstacles(obstacleGrid);
}