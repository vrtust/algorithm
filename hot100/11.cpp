#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>

using namespace std;

int maxArea(vector<int>& height) {
    // int water = 0;
    // for (int i = 0; i < height.size(); i++) {
    //     for (int j = i + 1; j < height.size(); j++) {
    //         water = max(water, (j - i) * min(height[i], height[j]));
    //     }
    // }
    // return water;

    int l = 0;
    int r = height.size() - 1;
    int water = 0;
    while (l < r) {
        water = max(water, (r - l) * min(height[l], height[r]));
        if (height[l] >= height[r]) r--;
        else l++;
    }
    return water;
}

int main() {
    vector<int> height = { 1,8,6,2,5,4,8,3 };
    maxArea(height);

    return 0;
}