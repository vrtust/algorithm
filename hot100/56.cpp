#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<stack>
#include<unordered_set>
#include<queue>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() == 1) return intervals;
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;
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

    return result;
}

int main() {
    vector<vector<int>> intervals = { {1,3},{2,6},{8,10},{15,18} };
    auto result = merge(intervals);

    return 0;
}