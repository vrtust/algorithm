#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;

int climbStairs(int n) {
    if (n < 3) {
        return n;
    }

    int pre = 2;
    int prepre = 1;

    int result = 0;

    for (int i = 3; i <= n; i++) {
        result = pre + prepre;

        prepre = pre;
        pre = result;
    }

    return result;
}

int main() {
    auto result = climbStairs(44);
}