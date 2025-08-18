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
    if (cur_node == 5) {
        all_path.push_back(path);
        return;
    }

    for (auto node : graph[cur_node]) {
        dfs(graph, node, all_path, path);
        path.pop_back();
    }
}

int main() {
    vector<vector<int>> graph(5 + 1, vector<int>());
    vector<vector<int>> all_path;
    vector<int> path;
    graph[1].push_back(3);
    graph[3].push_back(5);
    graph[1].push_back(2);
    graph[2].push_back(4);
    graph[4].push_back(5);

    dfs(graph, 1, all_path, path);

    return 0;
}