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

    if (first != second) nodes[second] = first;
}

int main() {
    int n = 5;
    vector<int> nodes(n, 0);
    for (int i = 0; i < n; i++) {
        nodes[i] = i;
    }
    vector<int> result;
    vector<vector<int>> borders = { {1,4},{4,2},{2,3},{3,5},{5,2} };
    vector<int> in_degree(n, 0);
    vector<vector<int>> vec;
    for (auto border : borders) {
        in_degree[border[1] - 1]++;
        if (in_degree[border[1] - 1] == 2) {
            vec.push_back(border);
        }
    }

    if (vec.size() > 0) {
        bool is_first = true;
        for (int i = 0; i < n; i++) {
            nodes[i] = i;
        }
        for (auto border : borders) {
            if (border == vec[vec.size() - 1]) continue;
            if (dsu_find(border[0] - 1, nodes) == dsu_find(border[1] - 1, nodes)) {
                is_first = false;
                break;
            }
            dsu_union(border[0] - 1, border[1] - 1, nodes);
        }
        result = is_first ? vec[vec.size() - 1] : vec[vec.size() - 2];
    } else {
        for (int i = 0; i < n; i++) {
            nodes[i] = i;
        }
        for (auto border : borders) {
            if (dsu_find(border[0] - 1, nodes) == dsu_find(border[1] - 1, nodes)) {
                result = border;
                break;
            }
            dsu_union(border[0] - 1, border[1] - 1, nodes);
        }

    }
    return 0;
}