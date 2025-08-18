#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<deque>
#include<unordered_map>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    vector<int> result;

    for (int num : nums) {
        count[num]++;
    }

    vector<pair<int, int>> vec(count.begin(), count.end());
    sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
        });

    for (size_t i = 0; i < k; i++) {
        result.push_back(vec[i].first);
    }

    return result;
}

int main() {
    vector<int> tokens = { 5,5,5,6,6,7 };
    topKFrequent(tokens, 2);
}