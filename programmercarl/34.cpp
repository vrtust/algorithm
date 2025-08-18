#include <iostream>
#include <vector>
using namespace std;

vector<int> search(vector<int>& nums, int target) {
    if (nums.empty()) return { -1, -1 };
    int left = 0;
    int right = nums.size() - 1;
    int mid;
    int first, last;

    first = -1;
    while (left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] == target) {
            first = mid;
            right = mid - 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    last = -1;
    left = 0;
    right = nums.size() - 1;
    while (left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] == target) {
            last = mid;
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return { first, last };
}


int main() {
    vector<int> nums = { 5,7,7,8,8,10 };
    int target = 8;
    vector<int> right_mid = { 3,4 };

    if (search(nums, target) == right_mid) {
        std::cout << "Right!" << std::endl;
    } else {
        std::cout << "Wrong!" << std::endl;
        std::cout << "{" << search(nums, target)[0] << "," << search(nums, target)[1] << "}" << std::endl;
    }
}