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
    int v = 7;
    int e = 11;
    vector<vector<int>> edge(v + 1, vector<int>(v + 1, 10001));
    edge[1][2] = 1; edge[1][3] = 1; edge[1][5] = 2; edge[2][6] = 1;
    edge[2][4] = 2; edge[2][3] = 2; edge[3][4] = 1; edge[4][5] = 1;
    edge[5][6] = 2; edge[5][7] = 1; edge[6][7] = 1;

    vector<int> minDis(v + 1, 10001);
    vector<bool> isInTree(v + 1, false);
    minDis[1] = 0;

    vector<int> parent(v + 1, -1);

    for (int i = 1; i < v; i++) {
        int cur = -1;
        int minNum = INT_MAX;
        for (int j = 1; j <= v; j++) {
            if (!isInTree[j] && minDis[j] < minNum) {
                minNum = minDis[j];
                cur = j;
            }
        }
        isInTree[cur] = true;
        for (int j = 1; j <= v; j++) {
            if (!isInTree[j] && edge[cur][j] < minDis[j]) {
                minDis[j] = edge[cur][j];
                parent[j] = cur;
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= v; i++) {
        result += minDis[i];
    }
    cout << result << endl;

    return 0;
}