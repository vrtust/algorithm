#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
#include<stack>

using namespace std;

int touch = 0;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node) {
    if (visited[node]) return;
    touch++;
    visited[node] = true;
    for (auto n : graph[node]) {
        dfs(graph, visited, n);
    }
}

int main() {
    int n = 4;
    int k = 4;
    vector<vector<int>> graph(n + 1, vector<int>());
    graph[1].push_back(2);
    graph[2].push_back(1);
    graph[1].push_back(3);
    graph[2].push_back(4);

    vector<bool> visited(n + 1, false);

    dfs(graph, visited, 1);

    return 0;
}