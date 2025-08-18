#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;

bool backtracking(vector<vector<char>>& board, vector<vector<bool>>& zone,
    vector<vector<bool>>& row, vector<vector<bool>>& col, int x, int y) {
    const int size = board.size();

    if (x == 9) {
        return true;
    }

    for (int i = x; i < size; i++) {
        int start_j = (i == x) ? y : 0;
        for (int j = start_j; j < size; j++) {
            if (board[i][j] != '.') {
                continue;
            }

            for (int k = 0; k < 9; k++) {
                if (zone[(i / 3) * (size / 3) + j / 3][k] || row[i][k] || col[j][k]) {
                    continue;
                }

                board[i][j] = '1' + k;

                zone[(i / 3) * (size / 3) + j / 3][k] = true;
                row[i][k] = true;
                col[j][k] = true;

                int next_i = (j == 8) ? i + 1 : i;
                int next_j = (j == 8) ? 0 : j + 1;

                if (backtracking(board, zone, row, col, next_i, next_j)) {
                    return true;
                }

                board[i][j] = '.';
                zone[(i / 3) * (size / 3) + j / 3][k] = false;
                row[i][k] = false;
                col[j][k] = false;
            }

            return false;
        }
    }

    return true;
}

struct count {
    vector<vector<bool>> zone;
    vector<vector<bool>> row;
    vector<vector<bool>> col;
};

struct count getCount(vector<vector<char>>& board) {
    int size = board.size();
    vector<vector<bool>> zone((size / 3) * (size / 3), vector<bool>(9, false));
    vector<vector<bool>> row(size, vector<bool>(size, false));
    vector<vector<bool>> col(size, vector<bool>(size, false));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == '.') {
                continue;
            }

            int zone_id = (i / 3) * (size / 3) + j / 3;
            zone[zone_id][board[i][j] - '1'] = true;
            row[i][board[i][j] - '1'] = true;
            col[j][board[i][j] - '1'] = true;
        }
    }

    return { zone, row, col };
}

void solveSudoku(vector<vector<char>>& board) {
    struct count all = getCount(board);

    backtracking(board, all.zone, all.row, all.col, 0, 0);
    int a = 0;
}

int main() {
    int n = 1;
    vector<vector<char>> board = { {'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'} };

    solveSudoku(board);
}