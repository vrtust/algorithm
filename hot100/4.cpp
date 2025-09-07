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

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        swap(nums1, nums2);
    }

    int left_size = (nums1.size() + nums2.size() + 1) / 2;

    int left = 0;
    int right = nums1.size();

    while (left <= right) {
        int mid1 = (left + right) / 2;
        int mid2 = left_size - mid1;

        int max_left1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
        int max_left2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
        int min_right1 = (mid1 == nums1.size()) ? INT_MAX : nums1[mid1];
        int min_right2 = (mid2 == nums2.size()) ? INT_MAX : nums2[mid2];

        if (max_left1 <= min_right2 && max_left2 <= min_right1) {
            if ((nums1.size() + nums2.size()) % 2 == 0) {
                double left_max = max(max_left1, max_left2);
                double right_min = min(min_right1, min_right2);
                return (left_max + right_min) / 2;
            } else {
                return max(max_left1, max_left2);
            }
        } else if (max_left1 > min_right2) {
            right = mid1 - 1;
        } else {
            left = mid1 + 1;
        }
    }
    return 0;
}

int main() {
    vector<int> nums1 = { 1,3 };
    vector<int> nums2 = { 2 };
    auto result = findMedianSortedArrays(nums1, nums2);

    return 0;
}