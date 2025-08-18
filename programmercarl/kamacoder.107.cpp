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
    int m = 4, n = 5;
    vector<int> nodes(n, 0);
    for (int i = 0; i < n; i++) {
        nodes[i] = i;
    }
    vector<int> s_d = { 1,4 };

    vector<vector<int>> borders = { {1,2},{1,3},{2,4},{3,4} };
    for (auto border : borders) {
        dsu_union(border[0], border[1], nodes);
    }

    if (dsu_find(s_d[0], nodes) == dsu_find(s_d[1], nodes)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}