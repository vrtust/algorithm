#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;

int wiggleMaxLength(vector<int>& nums) {
    if (nums.size() == 1) return 1;
    if (nums.size() == 2 && nums[0] != nums[1]) {
        return 2;
    } else if (nums.size() == 2 && nums[0] == nums[1]) {
        return 0;
    }

    int result = 1;
    int prediff = 0;
    int curdiff = 0;

    for (int i = 0; i < nums.size() - 1; i++) {
        curdiff = nums[i + 1] - nums[i];
        if ((prediff >= 0 && curdiff < 0) || (prediff <= 0 && curdiff > 0)) {
            result++;
            prediff = curdiff;
        }
    }

    return result;
}

int main() {
    vector<int> nums = { 1,7,4,9,2,5 };

    wiggleMaxLength(nums);
}