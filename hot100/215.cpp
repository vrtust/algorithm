#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<stack>
#include<unordered_set>
#include<queue>
#include<stack>
#include<set>
#include<cctype>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    vector<int> cnt(10000 * 2 + 1, 0);

    for (int num : nums) {
        cnt[10000 + num]++;
    }

    int n = 0;
    for (int i = cnt.size() - 1; i >= 0; i--) {
        if (n < k && n + cnt[i] >= k) {
            return i - 10000;
        }
        n += cnt[i];
    }

    return 0;
}

int main() {
    vector<int> nums = { 2,1,5,6,2,3 };
    auto result = findKthLargest(nums, 5);

    return 0;
}