#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        int l = i + 1;
        int r = nums.size() - 1;
        int sum = -nums[i];

        while (l < r) {
            if (nums[l] + nums[r] > sum) {
                r--;
            } else if (nums[l] + nums[r] < sum) {
                l++;
            } else {
                result.push_back({ nums[i], nums[l], nums[r] });
                while (l + 1 < nums.size() && nums[l] == nums[l + 1] && l < r) l++;
                while (r - 1 > nums.size() && nums[r] == nums[r - 1] && l < r) r--;
                l++;
                r--;
            }
        }

        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
    }

    return result;
}

int main() {
    vector<int> height = { -4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6 };
    auto result = threeSum(height);

    return 0;
}