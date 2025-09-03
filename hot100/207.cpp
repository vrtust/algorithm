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

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> indegree(numCourses, 0);
    queue<int> que;
    int cnt = 0;
    vector<vector<int>> record(numCourses);

    for (const auto& prerequisite : prerequisites) {
        indegree[prerequisite[0]]++;
        record[prerequisite[1]].push_back(prerequisite[0]);
    }

    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            que.push(i);
        }
    }

    while (!que.empty()) {
        auto cur = que.front();
        que.pop();
        cnt++;
        for (int i = 0; i < record[cur].size(); i++) {
            indegree[record[cur][i]]--;
            if (indegree[record[cur][i]] == 0) {
                que.push(record[cur][i]);
            }
        }
    }

    return cnt == numCourses;
}

int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = { {1,0} };

    auto result = canFinish(numCourses, prerequisites);

    return 0;
}