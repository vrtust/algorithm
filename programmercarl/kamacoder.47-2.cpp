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
    int n = 7;
    int m = 9;
    int start = 1;
    int end = n;

    vector<list<Edge>> grid(n + 1);
    grid[1].push_back(Edge(2, 1)); grid[1].push_back(Edge(3, 4));
    grid[2].push_back(Edge(3, 2)); grid[2].push_back(Edge(4, 5));
    grid[3].push_back(Edge(4, 2)); grid[4].push_back(Edge(5, 3));
    grid[2].push_back(Edge(6, 4)); grid[5].push_back(Edge(7, 4));
    grid[6].push_back(Edge(7, 9));

    vector<int> minDst(n + 1, INT_MAX);
    vector<bool> visited(n + 1, false);

    auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
        };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    pq.push(pair<int, int>(start, 0));

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        if (visited[cur.first]) continue;

        visited[cur.first] = true;

        for (auto edge : grid[cur.first]) {
            if (!visited[edge.to] && edge.val + minDst[cur.first] < minDst[edge.to]) {
                minDst[edge.to] = edge.val + minDst[cur.first];
                pq.push(pair<int, int>(edge.to, minDst[edge.to]));
            }
        }
    }

    int result = minDst[n] == INT_MAX ? -1 : minDst[n];
    cout << result << endl;

    return 0;
}