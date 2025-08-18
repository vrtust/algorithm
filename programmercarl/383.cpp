#include<iostream>
#include<array>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    if (ransomNote.size() > magazine.size()) return false;

    array<int, 26> ransomNote_count{}, magazine_count{};
    for (char c : ransomNote) {
        ransomNote_count[c - 'a']++;
    }
    for (char c : magazine) {
        magazine_count[c - 'a']++;
    }
    for(int i = 0; i < 26; ++i) {
        if (ransomNote_count[i] > magazine_count[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    string s = "aa";
    string t = "ab";

    cout << canConstruct(s, t) << endl;
}