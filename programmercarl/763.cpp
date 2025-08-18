#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;

vector<int> partitionLabels(string s) {
    vector<int> result;
    vector<vector<int>> record(26, vector<int>(2, -1));
    for (int i = 0; i < s.size(); i++) {
        if (record[s[i] - 'a'][0] == -1) {
            record[s[i] - 'a'][0] = i;
            record[s[i] - 'a'][1] = i;
        } else {
            record[s[i] - 'a'][1] = i;
        }
    }

    int start = record[s[0] - 'a'][0];
    int end = record[s[0] - 'a'][1];
    for (int i = 1; i < s.size(); i++) {
        if (record[s[i] - 'a'][0] > end) {
            result.push_back(end - start + 1);
            start = record[s[i] - 'a'][0];
            end = record[s[i] - 'a'][1];
        }
        if (record[s[i] - 'a'][1] > end) {
            end = record[s[i] - 'a'][1];
        }
        if(i == s.size() - 1){
            result.push_back(end - start + 1);
        }
    }

    return result;
}

int main() {
    string s = "eaaaabaaec";

    partitionLabels(s);
}