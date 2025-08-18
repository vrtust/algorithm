#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
#include<stack>
#include<list>

using namespace std;

struct Knight {
    int x;
    int y;
    int g;
    int h;
    int f;

    bool operator < (const Knight& knight) const {
        return knight.f < f;
    }
};

int compute(const Knight& k, int b1, int b2) {
    return (k.x - b1) * (k.x - b1) + (k.y - b2) * (k.y - b2);
}

int astar(const vector<int>& goal) {
    int b1 = goal[2];
    int b2 = goal[3];

    Knight start, cur, next;
    start.x = goal[0];
    start.y = goal[1];
    start.g = 0;
    start.h = compute(start, b1, b2);
    start.f = start.g + start.h;

    priority_queue<Knight> que;
    que.push(start);
    vector<vector<int>> moves(1001, vector<int>(1001, 0));

    vector<vector<int>> dirs = { {1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2} };

    while (!que.empty()) {
        cur = que.top();
        que.pop();
        if (cur.x == b1 && cur.y == b2) break;
        for (const auto& dir : dirs) {
            next.x = cur.x + dir[0];
            next.y = cur.y + dir[1];
            if (next.x < 1 || next.x > 1000 || next.y < 1 || next.y > 1000) continue;
            if (moves[next.x][next.y] == 0) {
                moves[next.x][next.y] = moves[cur.x][cur.y] + 1;

                next.g = cur.g + 5;
                next.h = compute(next, b1, b2);
                next.f = next.g + next.h;
                que.push(next);
            }
        }
    }

    return moves[b1][b2];
}

int main() {
    vector<vector<int>> testCases;
    testCases.push_back({ 5,2,5,4 }); testCases.push_back({ 1,1,2,2 });
    testCases.push_back({ 1,1,8,8 }); testCases.push_back({ 1,1,8,7 });
    testCases.push_back({ 2,1,3,3 }); testCases.push_back({ 4,6,4,6 });

    for (const auto& testCase : testCases) {
        cout << astar(testCase) << endl;
    }

    return 0;
}