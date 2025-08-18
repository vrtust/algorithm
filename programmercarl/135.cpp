#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;

int candy(vector<int>& ratings) {
    int result = ratings.size();
    int pre = 0;
    int post = 0;
    vector<int> forward(ratings.size(), 0), reverse(ratings.size(), 0);

    for (int i = 1; i < ratings.size(); i++) {
        if (ratings[i] > ratings[i - 1]) {
            forward[i] = pre + 1;
            pre = forward[i];
        } else {
            pre = 0;
        }
    }

    for (int i = ratings.size() - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            reverse[i] = post + 1;
            post = reverse[i];
        } else {
            post = 0;
        }
    }

    for (int i = 0; i < ratings.size(); i++) {
        result += max(forward[i], reverse[i]);
    }

    return result;
}

int main() {
    vector<int> ratings = { 1,0,2 };

    candy(ratings);
}