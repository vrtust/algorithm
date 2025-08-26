#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<stack>
#include<unordered_set>
#include<queue>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    int left = 0;
    int right = matrix[0].size() - 1;
    int top = 0;
    int bottom = matrix.size() - 1;

    while (true) {
        for (int i = left; i <= right; i++) {
            result.push_back(matrix[top][i]);
        }
        if (++top > bottom) break;

        for (int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }
        if (--right < left) break;

        for (int i = right; i >= left; i--) {
            result.push_back(matrix[bottom][i]);
        }
        if (--bottom < top) break;

        for (int i = bottom; i >= top; i--) {
            result.push_back(matrix[i][left]);
        }
        if (++left > right) break;
    }

    return result;
}

int main() {
    vector<vector<int>> matrix = { {1,2,3},{4,5,6},{7,8,9} };
    spiralOrder(matrix);

    return 0;
}