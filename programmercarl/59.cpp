#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> result(n, vector<int>(n, 0));
    int start_x = 0;
    int start_y = 0;
    int offset = 1;
    int i = 0;
    int j = 0;
    int count = 1;
    int num = n;
    int loop = n / 2;

    while (loop--) {
        for (j = start_y; j < n - offset; j++) {
            result[start_x][j] = count++;
        }
        for (i = start_x; i < n - offset; i++) {
            result[i][j] = count++;
        }
        for (; j > start_x; j--) {
            result[i][j] = count++;
        }
        for (; i > start_y; i--) {
            result[i][j] = count++;
        }

        offset++;
        start_x++;
        start_y++;
    }

    if (num % 2 == 1) {
        result[start_x][start_y] = count++;
    }

    return result;
}

int main() {
    int n = 4;
    vector<vector<int>> target = { {1,2,3}, {8,9,4}, {7,6,5} };

    vector<vector<int>> result = generateMatrix(n);
    for (auto row : result) {
        for (auto num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    // cout << s.substr(0, 1) << endl;
    // cout << s.substr(0, 2) << endl;
    // cout << s.substr(1, 2) << endl;
    // cout << s.substr(1, 1) << endl;
    // cout << s.substr(2, 2) << endl;

    return 0;
}