#include<iostream>
#include<array>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result;
    unordered_map<string, vector<string>> hashs;

    for (auto str : strs) {
        string sorted_str = str;
        sort(sorted_str.begin(), sorted_str.end());
        hashs[sorted_str].push_back(str);
    }

    for (auto const [key, val] : hashs) {
        result.push_back(val);
    }

    return result;
}

int main() {
    vector<string> strs = {"aa", "bb", "cc"};
    groupAnagrams(strs);
}