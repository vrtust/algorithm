#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
#include<stack>

using namespace std;

int main() {
    int n = 5;
    int m = 4;
    vector<int> indegree(n, 0);
    vector<vector<int>> edges;
    edges.push_back({ 0,1 });
    edges.push_back({ 0,2 });
    edges.push_back({ 1,3 });
    edges.push_back({ 2,4 });

    queue<int> que;
    unordered_map<int, vector<int>> mapping;
    vector<int> result;

    for (auto edge : edges) {
        mapping[edge[0]].push_back(edge[1]);
        indegree[edge[1]]++;
    }
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) que.push(i);
    }
    while (!que.empty()) {
        auto cur = que.front();
        result.push_back(cur);
        que.pop();
        for (auto num : mapping[cur]) {
            indegree[num]--;
            if (indegree[num] == 0) {
                que.push(num);
            }
        }
    }

    if (result.size() != n) {
        result.clear();
        result.push_back(-1);
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;

    return 0;
}