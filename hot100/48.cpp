#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<stack>
#include<unordered_set>
#include<queue>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = i; j < matrix[0].size(); j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size() / 2; j++) {
            swap(matrix[i][j], matrix[i][matrix[0].size() - j - 1]);
        }
    }
}

int main() {
    vector<vector<int>> matrix = { {1,2,3},{4,5,6},{7,8,9} };
    rotate(matrix);

    return 0;
}