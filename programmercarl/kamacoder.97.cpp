#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
#include<stack>
#include<list>

using namespace std;

int main() {
    int n = 7;
    int m = 3;

    vector<vector<int>> grid;
    grid.push_back({ 2,3,4 }); grid.push_back({ 3,6,6 });
    grid.push_back({ 4,7,8 });

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 10005)));
    for (const auto& edge : grid) {
        dp[edge[0]][edge[1]][0] = edge[2];
        dp[edge[1]][edge[0]][0] = edge[2];
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j][k] = min(dp[i][k][k - 1] + dp[k][j][k - 1], dp[i][j][k - 1]);
            }
        }
    }

    if (dp[2][3][n] == 10005) cout << -1 << endl;
    else cout << dp[2][3][n] << endl;
    if (dp[3][4][n] == 10005) cout << -1 << endl;
    else cout << dp[3][4][n] << endl;

    return 0;
}