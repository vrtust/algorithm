#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
#include<stack>

using namespace std;

int main() {
    int length = 6;
    string startStr = "abc";
    string endStr = "def";
    unordered_set<string> str_dic = { "efc", "dbc", "ebc", "dec", "dfc", "yhn" };

    unordered_map<string, int> visited;
    visited.insert(pair<string, int>(startStr, 1));

    queue<string> que;
    que.push(startStr);

    while (!que.empty()) {
        auto word = que.front();
        que.pop();
        int path = visited[word];

        for (int i = 0; i < word.size(); i++) {
            string new_word = word;
            for (int j = 0; j < 26; j++) {
                new_word[i] = 'a' + j;
                if (new_word == endStr) {
                    cout << path + 1 << endl;
                    return 0;
                }

                if (str_dic.count(new_word) > 0 && !visited.count(new_word)) {
                    que.push(new_word);
                    visited.insert(pair<string, int>(new_word, path + 1));
                }
            }
        }
    }

    return 0;
}