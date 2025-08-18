#include<iostream>
#include<array>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>

using namespace std;

// vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//     vector<int> result;
//     vector<int> final_result;
//     unordered_map<int, int> count1, count2;
//     unordered_set<int> nums1_set(nums1.begin(), nums1.end());
//     unordered_set<int> nums2_set(nums2.begin(), nums2.end());

//     for (auto num : nums1_set) {
//         if (nums2_set.count(num) > 0) {
//             result.push_back(num);
//         }
//     }

//     for (auto num : result) {
//         for (auto num1 : nums1) {
//             if(num == num1){
//                 count1[num]++;
//             }
//         }
//         for (auto num2 : nums2) {
//             if(num == num2){
//                 count2[num]++;
//             }
//         }
//     }

//     for (int num : result) {
//         for(int i=0;i<min(count1[num], count2[num]);i++){
//             final_result.push_back(num);
//         }
//     }

//     return final_result;
// }

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return intersect(nums2, nums1);
    }
    vector<int> result;
    unordered_map<int, int> freqmap;
    for (auto num : nums1) {
        freqmap[num]++;
    }

    for (auto num : nums2) {
        if (freqmap.count(num) > 0 && freqmap[num] > 0) {
            result.push_back(num);
            freqmap[num]--;
        }
    }

    return result;
}

int main() {
    vector<int> nums1 = { 1,2,2,1 };
    vector<int> nums2 = { 2,2 };

    intersect(nums1, nums2);
}