#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
    if (points.size() < 2) return points.size();

    sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
        if (a[0] != b[0]) {
            return a[0] < b[0];
        }
        return a[1] < b[1];
        });

    int count = 1;
    int pre = points[0][1];

    for (int i = 1; i < points.size(); i++) {
        if (points[i][0] > pre) {
            count++;
            pre = points[i][1];
        } else {
            pre = min(pre, points[i][1]);
        }
    }

    return count;
}

int main() {
    vector<vector<int>> people = { {10,16},{2,8},{1,6},{7,12} };

    findMinArrowShots(people);
}