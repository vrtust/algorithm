#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
#include<stack>

using namespace std;

void dfs(vector<vector<int>>& graph, int cur_node, vector<vector<int>>& all_path, vector<int>& path) {
    path.push_back(cur_node);
    if (cur_node == graph.size() - 1) {
        all_path.push_back(path);
        return;
    }

    for (auto node : graph[cur_node]) {
        dfs(graph, node, all_path, path);
        path.pop_back();
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> all_path;
    vector<int> path;
    dfs(graph, 0, all_path, path);
    return all_path;
}

int main() {
    vector<vector<int>> graph;
    graph = { {1,2},{3},{3},{} };

    auto result = allPathsSourceTarget(graph);

    return 0;
}