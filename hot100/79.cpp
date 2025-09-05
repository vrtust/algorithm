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

bool traval(vector<vector<char>>& board, vector<vector<bool>>& visted, string word, int x, int y, int cursor) {
    if (cursor == word.size()) {
        return true;
    }

    for (const auto& ward : wards) {
        int next_x = x + ward[0];
        int next_y = y + ward[1];
        if (next_x >= 0 && next_x < board.size() && next_y >= 0 && next_y < board[0].size() && !visted[next_x][next_y] && board[next_x][next_y] == word[cursor]) {
            visted[next_x][next_y] = true;
            if (traval(board, visted, word, next_x, next_y, cursor + 1)) {
                return true;
            }
            visted[next_x][next_y] = false;
        }
    }

    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    vector<vector<bool>> visted(board.size(), vector<bool>(board[0].size(), false));

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == word[0]) {
                visted[i][j] = true;
                if (traval(board, visted, word, i, j, 1)) {
                    return true;
                }
                visted[i][j] = false;
            }
        }
    }

    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCB";

    auto result = exist(board, word);

    return 0;
}