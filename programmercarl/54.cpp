#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    // 自己想的
    // int size = matrix.size() * matrix[0].size();
    // vector<int> result(size, 0);
    // int start_x = 0;
    // int start_y = 0;
    // int offset_x = 1;
    // int offset_y = 1;
    // int i = 0;
    // int j = 0;
    // int count = 0;
    // int loop = min(matrix.size(), matrix[0].size()) / 2;

    // while (loop--) {
    //     for (j = start_y, i = start_x; j < matrix[0].size() - offset_y; j++) {
    //         result[count++] = matrix[i][j];
    //     }
    //     for (; i < matrix.size() - offset_x; i++) {
    //         result[count++] = matrix[i][j];
    //     }
    //     for (; j > start_y; j--) {
    //         result[count++] = matrix[i][j];
    //     }
    //     for (; i > start_x; i--) {
    //         result[count++] = matrix[i][j];
    //     }

    //     offset_x++;
    //     offset_y++;
    //     start_x++;
    //     start_y++;
    // }

    // i = start_x;
    // j = start_y;
    // if (matrix.size() == matrix[0].size() && matrix.size() % 2 == 1) {
    //     result[count++] = matrix[i][j];
    // } else if (matrix.size() == 1) {
    //     for (; j < matrix[0].size(); j++) {
    //         result[count++] = matrix[i][j];
    //     }
    // } else if (matrix[0].size() == 1) {
    //     for (; i < matrix.size(); i++) {
    //         result[count++] = matrix[i][j];
    //     }
    // } else if (matrix.size() % 2 == 1 && matrix.size() < matrix[0].size()) {
    //     for (; j <= matrix[0].size() - offset_x; j++) {
    //         result[count++] = matrix[i][j];
    //     }
    // } else if (matrix[0].size() % 2 == 1&& matrix.size() > matrix[0].size()) {
    //     for (; i <= matrix.size() - offset_y; i++) {
    //         result[count++] = matrix[i][j];
    //     }
    // }

    // return result;

    if (matrix.empty()) {
        return {};
    }

    int up = 0;
    int down = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;

    vector<int> result;
    while (true) {
        for (int i = left; i <= right;i++) {
            result.push_back(matrix[up][i]);
        }
        if (++up > down) break;
        for (int i = up;i <= down;i++) {
            result.push_back(matrix[i][right]);
        }
        if (--right < left) break;
        for (int i = right;i >= left;i--) {
            result.push_back(matrix[down][i]);
        }
        if (--down < up) break;
        for (int i = down; i >= up;i--) {
            result.push_back(matrix[i][left]);
        }
        if (++left > right) break;
    }

    return result;
}

int main() {
    vector<vector<int>> n = { {2,3,4},{5,6,7},{8,9,10},{11,12,13},{14,15,16} };

    vector<int> result = spiralOrder(n);
    for (auto num : result) {
        cout << num << " ";
    }

    cout << endl;

    // cout << s.substr(0, 1) << endl;
    // cout << s.substr(0, 2) << endl;
    // cout << s.substr(1, 2) << endl;
    // cout << s.substr(1, 1) << endl;
    // cout << s.substr(2, 2) << endl;

    return 0;
}