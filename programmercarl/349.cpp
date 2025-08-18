#include<iostream>
#include<array>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    unordered_set<int> nums1_set(nums1.begin(), nums1.end());
    unordered_set<int> nums2_set(nums2.begin(), nums2.end());

    for (auto num : nums1_set) {
        if (nums2_set.count(num) > 0) {
            result.push_back(num);
        }
    }

    return result;
}

int main() {
    vector<int> nums1 = { 1,2,2,1 };
    vector<int> nums2 = { 2,2 };

    intersection(nums1, nums2);
}