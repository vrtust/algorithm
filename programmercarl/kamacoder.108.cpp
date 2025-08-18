#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
#include<stack>

using namespace std;

int dsu_find(int i, vector<int>& nodes) {
    if (nodes[i] == i) return i;
    else return nodes[i] = dsu_find(nodes[i], nodes);
}

void dsu_union(int i, int j, vector<int>& nodes) {
    int first = dsu_find(i, nodes);
    int second = dsu_find(j, nodes);

    if (first != second) nodes[first] = second;
}

int main() {
    int n = 5;
    vector<int> nodes(n, 0);
    for (int i = 0; i < n; i++) {
        nodes[i] = i;
    }
    vector<int> result;
    vector<vector<int>> borders = { {1,4},{4,2},{2,3},{3,5},{5,2} };
    for (auto border : borders) {
        if (dsu_find(border[0] - 1, nodes) == dsu_find(border[1] - 1, nodes)) {
            result = { border[0],border[1] };
            return 0;
        }
        dsu_union(border[0] - 1, border[1] - 1, nodes);
    }

    return 0;
}