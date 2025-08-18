#include<iostream>
#include<array>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>

using namespace std;

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    unordered_map<int, int> record;
    int result = 0;

    for (int num1 : nums1) {
        for (int num2 : nums2) {
            record[num1 + num2]++;
        }
    }

    for (int num3 : nums3) {
        for (int num4 : nums4) {
            if (record.count(-(num3 + num4)) > 0) {
                result += record.find(-(num3 + num4))->second;
            }
        }
    }

    return result;
}

int main() {
    vector<int> nums1 = { -1,-1 };
    vector<int> nums2 = { -1,1 };
    vector<int> nums3 = { -1,1 };
    vector<int> nums4 = { 1,-1 };

    fourSumCount(nums1, nums2, nums3, nums4);
}