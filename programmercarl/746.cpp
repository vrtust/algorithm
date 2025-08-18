#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int result = 0;
    int prepre = 0;
    int pre = 0;

    for (int i = 2; i <= cost.size(); i++) {
        result = min(prepre + cost[i - 2], pre + cost[i - 1]);
        prepre = pre;
        pre = result;
    }

    return result;
}

int main() {
    vector<int> cost = { 10,15,20 };
    auto result = minCostClimbingStairs(cost);
}