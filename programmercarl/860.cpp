#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;

bool lemonadeChange(vector<int>& bills) {
    vector<int> m(3, 0);    // 0:5, 1:10, 2:20
    for (int bill : bills) {
        if (bill == 5) {
            m[0]++;
        } else if (bill == 10) {
            m[1]++;

            if (m[0] >= 1) {
                m[0]--;
            } else {
                return false;
            }
        } else if (bill == 20) {
            m[2]++;

            if (m[0] >= 1 && m[1] >= 1) {
                m[0]--;
                m[1]--;
            } else if (m[0] >= 3) {
                m[0] = m[0] - 3;
            } else {
                return false;
            }
        }
    }

    return true;
}

int main() {
    vector<int> bills = { 1,0,2 };

    lemonadeChange(bills);
}