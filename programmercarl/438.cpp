#include<iostream>
#include<array>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    array<int, 26> s_count{}, t_count{};
    for (char c : s) {
        s_count[c - 'a']++;
    }
    for (char c : t) {
        t_count[c - 'a']++;
    }
    return std::equal(s_count.begin(), s_count.end(), t_count.begin());
}

vector<int> findAnagrams(string s, string p) {
    int s_len = s.size();
    int p_len = p.size();
    vector<int> result;

    if (s_len < p_len) return result;

    int i = 0;
    for (char c : s) {
        if (i + p_len > s_len) {
            break;
        }

        string temp_str = s.substr(i, p_len);
        if (isAnagram(temp_str, p)) {
            result.push_back(i);
        }

        i++;
    }

    return result;
}

int main() {
    string s = "abab";
    string t = "ab";
    findAnagrams(s, t);
}