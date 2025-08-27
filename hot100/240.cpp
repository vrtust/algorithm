#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<stack>
#include<unordered_set>
#include<queue>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // if (matrix[matrix.size() - 1][matrix[0].size() - 1] < target) return false;
    // if (matrix[matrix.size() - 1][matrix[0].size() - 1] == target) return true;
    // int range_x = matrix.size() - 1;
    // int range_y = matrix[0].size() - 1;
    // for (; range_y > 0; range_y--) {
    //     if (matrix[0][range_y] <= target) {
    //         break;
    //     }
    // }
    // for (; range_x > 0; range_x--) {
    //     if (matrix[range_x][0] <= target) {
    //         break;
    //     }
    // }

    // for (int i = 0; i <= range_x; i++) {
    //     for (int j = 0; j <= range_y; j++) {
    //         if (matrix[i][j] == target) return true;
    //         else if (matrix[i][j] > target) break;
    //     }
    // }

    // return false;

    int x = 0;
    int y = matrix[0].size() - 1;

    while (x < matrix.size() && y >= 0) {
        if (matrix[x][y] > target) {
            y--;
        } else if (matrix[x][y] == target) {
            return true;
        } else if (matrix[x][y] < target) {
            x++;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> matrix = { {1,3,5} };
    auto result = searchMatrix(matrix, 3);

    return 0;
}