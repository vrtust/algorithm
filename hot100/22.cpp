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

void traval(vector<string>& result, string path, int target, int left, int right) {
    if (left == target && right == target) {
        result.push_back(path);
        return;
    }

    if (left < target) {
        left++;
        path.push_back('(');
        traval(result, path, target, left, right);
        left--;
        path.pop_back();
    }

    if (right < target && right < left) {
        right++;
        path.push_back(')');
        traval(result, path, target, left, right);
        right--;
        path.pop_back();
    }

    return;
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    string path;

    traval(result, path, n, 0, 0);
    return result;
}

int main() {
    auto result = generateParenthesis(3);

    return 0;
}