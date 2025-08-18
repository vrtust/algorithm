#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;

void backtracking(int n, vector<vector<string>>& result,
    vector<string>& path, vector<bool> col,
    vector<bool> dia1, vector<bool> dia2) {

    if (n == path.size()) {
        result.push_back(path);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (col[i] || dia1[i - path.size() + (n - 1)] || dia2[path.size() + i]) {
            continue;
        }

        col[i] = true;
        dia1[i - path.size() + (n - 1)] = true;
        dia2[path.size() + i] = true;

        string s = "";
        for (int j = 0; j < i; j++) {
            s.push_back('.');
        }
        s.push_back('Q');
        for (int j = i + 1; j < n; j++) {
            s.push_back('.');
        }

        path.push_back(s);
        backtracking(n, result, path, col, dia1, dia2);
        path.pop_back();

        col[i] = false;
        dia1[i - path.size() + (n - 1)] = false;
        dia2[path.size() + i] = false;
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> path;
    vector<bool> col(n, false), dia1(2 * n - 1, false), dia2(2 * n - 1, false);

    backtracking(n, result, path, col, dia1, dia2);

    return result;
}

int main() {
    int n = 1;

    solveNQueens(n);
}