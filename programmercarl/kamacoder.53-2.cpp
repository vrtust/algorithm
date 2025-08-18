#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
#include<stack>

using namespace std;

struct Edge {
    int l, r, val;
};

int dsu_find(int i, vector<int>& nodes) {
    if (nodes[i] == i) return i;
    else return nodes[i] = dsu_find(nodes[i], nodes);
}

void dsu_join(int i, int j, vector<int>& nodes) {
    int first = dsu_find(i, nodes);
    int second = dsu_find(j, nodes);
    if (first == second) return;
    else nodes[j] = first;
}

int main() {
    int v = 7;
    int e = 11;
    vector<Edge> edges;
    edges.push_back({ 1,2,1 }); edges.push_back({ 1,3,1 });
    edges.push_back({ 1,5,2 }); edges.push_back({ 2,6,1 });
    edges.push_back({ 2,4,2 }); edges.push_back({ 2,3,2 });
    edges.push_back({ 3,4,1 }); edges.push_back({ 4,5,1 });
    edges.push_back({ 5,6,2 }); edges.push_back({ 5,7,1 });
    edges.push_back({ 6,7,1 });

    vector<int> nodes(v + 1, -1);
    for (int i = 1; i < v + 1; i++) {
        nodes[i] = i;
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.val < b.val;
        });

    int result = 0;
    vector<Edge> validEdge;
    for (auto edge : edges) {
        if (dsu_find(edge.l, nodes) != dsu_find(edge.r, nodes)) {
            dsu_join(edge.l, edge.r, nodes);
            result += edge.val;
            validEdge.push_back(edge);
        }
    }

    return 0;
}