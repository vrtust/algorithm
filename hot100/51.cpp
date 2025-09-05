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

void traval(vector<vector<int>>& grid, vector<vector<string>>& result, vector<string>& path, vector<bool>& x, vector<bool>& y, vector<bool>& line1, vector<bool>& line2, int start_x) {
    if (path.size() == grid.size()) {
        result.push_back(path);
        return;
    }

    for (int i = start_x; i < grid.size(); i++) {
        if (i == path.size()) {
            return;
        }
        for (int j = 0; j < grid.size(); j++) {
            if (!x[i] && !y[j] && !line1[j - i + grid.size()] && !line2[i + j]) {
                x[i] = true;
                y[j] = true;
                line1[j - i + grid.size()] = true;
                line2[i + j] = true;
                string str;
                for (int k = 0; k < j; k++) {
                    str.push_back('.');
                }
                str.push_back('Q');
                for (int k = j + 1; k < grid.size(); k++) {
                    str.push_back('.');
                }
                path.push_back(str);
                traval(grid, result, path, x, y, line1, line2, i + 1);
                path.pop_back();
                x[i] = false;
                y[j] = false;
                line1[j - i + grid.size()] = false;
                line2[i + j] = false;
            }
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<vector<string>> result;
    vector<string> path;
    vector<bool> x(n, false);
    vector<bool> y(n, false);
    vector<bool> line1(2 * n, false);
    vector<bool> line2(2 * n, false);

    traval(grid, result, path, x, y, line1, line2, 0);

    return result;
}

int main() {
    auto result = solveNQueens(4);

    return 0;
}