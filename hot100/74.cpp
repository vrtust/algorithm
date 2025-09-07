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

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int mid_row = 0;
    int up = 0;
    int down = matrix.size() - 1;
    bool up_last = false;
    bool down_last = true;

    while (up <= down) {
        mid_row = (up + down) / 2;
        up_last = false;
        down_last = true;
        if (matrix[mid_row][0] > target) {
            down = mid_row - 1;
            down_last = true;
        } else if (matrix[mid_row][0] < target) {
            up = mid_row + 1;
            up_last = true;
        } else {
            return true;
        }
    }

    if (up_last) mid_row = up;
    if (down_last) mid_row = down;
    if (mid_row < 0 || mid_row >= matrix.size()) {
        return false;
    }

    int mid_col = 0;
    int left = 0;
    int right = matrix[0].size() - 1;

    while (left <= right) {
        mid_col = (left + right) / 2;
        if (matrix[mid_row][mid_col] > target) {
            right = mid_col - 1;
        } else if (matrix[mid_row][mid_col] < target) {
            left = mid_col + 1;
        } else {
            return true;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> nums = { {1,3,5,7},{10,11,16,20},{23,30,34,50} };
    auto result = searchMatrix(nums, 11);

    return 0;
}