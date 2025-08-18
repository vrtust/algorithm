#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int cur = 0;
    int total = 0;
    int index = 0;

    for (int i = 0; i < gas.size(); i++) {
        cur += gas[i] - cost[i];
        total += gas[i] - cost[i];

        if (cur < 0) {
            index = i + 1;
            cur = 0;
        }
    }

    if (total < 0) return -1;

    return index;
}

int main() {
    vector<int> gas = { 5,8,2,8 };
    vector<int> cost = { 6,5,6,6 };

    canCompleteCircuit(gas, cost);
}