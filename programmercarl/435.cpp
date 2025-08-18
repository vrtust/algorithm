#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.size() < 2) return 0;

    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
        if (a[1] != b[1]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
        });

    int count = 0;
    int pre_end = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < pre_end) {
            count++;
        } else {
            pre_end = intervals[i][1];
        }
    }

    return count;
}

int main() {
    vector<vector<int>> intervals = { {1,100},{11,22},{1,11},{2,12} };

    eraseOverlapIntervals(intervals);
}