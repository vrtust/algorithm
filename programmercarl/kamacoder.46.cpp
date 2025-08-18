#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;

int main() {
    int M = 6;
    int N = 1;

    vector<int> weight = { 2,2,3,1,5,2 };
    vector<int> value = { 2,3,1,5,4,3 };

    vector<vector<int>> bag(M, vector<int>(N + 1, 0));

    for (int j = 0; j < N; j++) {
        if (j >= weight[0]) bag[0][j] = value[0];
    }

    for (int i = 1; i < M; i++) {
        for (int j = 1; j <= N; j++) {
            if (j < weight[i]) bag[i][j] = bag[i - 1][j];
            else bag[i][j] = max(bag[i - 1][j], bag[i - 1][j - weight[i]] + value[i]);
        }
    }

    cout << bag[M - 1][N] << endl;

    return 0;
}