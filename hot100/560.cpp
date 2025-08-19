#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<stack>
#include<unordered_set>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int result = 0;
    int sum = 0;
    unordered_map<int, int> cnt;

    cnt[0] = 1;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        result += cnt.count(sum - k) > 0 ? cnt[sum - k] : 0;
        cnt[sum]++;
    }

    return result;
}

int main() {
    vector<int> nums = { 1,1,1 };
    int k = 2;
    auto result = subarraySum(nums, k);

    return 0;
}