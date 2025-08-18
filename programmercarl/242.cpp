#include<iostream>
#include<array>

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

int main() {
    string s = "anagram";
    string t = "nagaram";

    cout << isAnagram(s, t) << endl;
}