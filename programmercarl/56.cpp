#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> result;

    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] != b[0]) {
            return a[0] < b[0];
        }
        return a[1] < b[1];
        });

    int start = intervals[0][0];
    int end = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= end) {
            end = max(end, intervals[i][1]);
        } else {
            result.push_back({ start, end });
            start = intervals[i][0];
            end = intervals[i][1];
        }

        if (i == intervals.size() - 1) {
            result.push_back({ start, end });
        }
    }

    if (result.empty()) {
        result.push_back({ start, end });
    }

    return result;
}

int main() {
    vector<vector<int>> intervals = { {1, 3}, {2, 6}, {8, 10}, {15, 18} };

    merge(intervals);
}