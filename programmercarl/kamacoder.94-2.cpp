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

struct Edge {
    int to;
    int val;

    Edge(int t, int v) : to(t), val(v) {}
};

int main() {
    int n = 6;
    int m = 7;
    int start = 1;
    int end = n;

    vector<list<Edge>> grid(n + 1);
    grid[5].push_back(Edge(6, -2)); grid[1].push_back(Edge(2, 1));
    grid[5].push_back(Edge(3, 1));  grid[2].push_back(Edge(5, 2));
    grid[2].push_back(Edge(4, -3)); grid[4].push_back(Edge(6, 4));
    grid[1].push_back(Edge(3, 5));

    vector<int> minDst(n + 1, INT_MAX);
    minDst[start] = 0;

    queue<int> que;
    que.push(1);

    vector<bool> isInQueue(n + 1, false);

    while (!que.empty()) {
        auto cur = que.front();
        que.pop();
        isInQueue[cur] = false;
        for (auto edge : grid[cur]) {
            if (minDst[cur] < INT_MAX && minDst[cur] + edge.val < minDst[edge.to]) {
                minDst[edge.to] = minDst[cur] + edge.val;
                if (!isInQueue[edge.to]) {
                    isInQueue[edge.to] = true;
                    que.push(edge.to);
                }
            }
        }
        cout << "对 " << cur << " 指向的边松弛" << endl;
        for (int k = 1; k <= n; k++) {
            cout << minDst[k] << " ";
        }
        cout << endl;
    }

    int result = minDst[n] == INT_MAX ? -1 : minDst[n];
    cout << result << endl;

    return 0;
}