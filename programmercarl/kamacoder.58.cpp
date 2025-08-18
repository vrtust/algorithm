#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& array) {
    if (array.empty()) return {};

    vector<int> result;
    int up = 0;
    int down = array.size() - 1;
    int left = 0;
    int right = array[0].size() - 1;

    while (true) {
        for (int i = left; i <= right; i++) {
            result.push_back(array[up][i]);
        }
        if (++up > down) {
            break;
        }
        for (int i = up; i <= down; i++) {
            result.push_back(array[i][right]);
        }
        if (--right < left) {
            break;
        }
        for (int i = right; i >= left; i--) {
            result.push_back(array[down][i]);
        }
        if (--down < up) {
            break;
        }
        for (int i = down; i >= up; i--) {
            result.push_back(array[i][left]);
        }
        if (++left > right) {
            break;
        }
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