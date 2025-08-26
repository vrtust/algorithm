#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<stack>
#include<unordered_set>
#include<queue>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    vector<vector<int>> zero;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 0) {
                zero.push_back({ i,j });
            }
        }
    }

    for (auto index : zero) {
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i][index[1]] = 0;
        }
        for (int j = 0; j < matrix[0].size(); j++) {
            matrix[index[0]][j] = 0;
        }
    }

    return;
}

int main() {
    vector<vector<int>> matrix = { {0,1} };
    setZeroes(matrix);

    return 0;
}