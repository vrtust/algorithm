#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    if (s.empty()) return 0;

    int count = 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int j = s.size() - 1;

    for (int i = g.size() - 1; i >= 0 && j >= 0; i--) {
        if (s[j] >= g[i]) {
            count++;
            j--;
        }
    }

    return count;
}

int main() {
    vector<int> g = { 1,2,3 };
    vector<int> s = { 3 };

    findContentChildren(g, s);
}