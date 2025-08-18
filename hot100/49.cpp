#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result;
    unordered_map<string, vector<string>> hashs;

    for (const auto& str : strs) {
        auto temp = str;
        sort(temp.begin(), temp.end());
        hashs[temp].push_back(str);
    }

    for (const auto& [key, val] : hashs) {
        result.push_back(val);
    }

    return result;
}

int main() {
    vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
    auto result = groupAnagrams(strs);

    return 0;
}