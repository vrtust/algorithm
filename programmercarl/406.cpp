#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;

// vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
//     vector<vector<int>> result;

//     sort(people.begin(), people.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
//         if (a[0] != b[0]) {
//             return a[0] > b[0]; // 身高降序
//         }
//         return a[1] < b[1]; // k 值升序
//         });

//     for (auto person : people) {
//         result.insert(result.begin() + person[1], person);
//     }

//     return result;
// }

// my version
bool cmp(vector<int> A, vector<int> B) {
    return A[0] > B[0];
}

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    vector<vector<int>> back;
    vector<vector<int>> result;

    sort(people.begin(), people.end());
    back = people;

    while (result.size() != people.size()) {
        int i = 0;
        for (; i < people.size(); i++) {
            if (people[i][1] == 0) {
                people[i][0] = -1;
                break;
            }
        }

        result.push_back(back[i]);

        for (i = 0; i < people.size(); i++) {
            if (people[i][0] == -1) {
                continue;
            }
            if (people[i][0] > result[result.size() - 1][0]) {
                break;
            }
            people[i][1]--;
        }
    }

    return result;
}

int main() {
    vector<vector<int>> people = { {7,0},{4,4},{7,1},{5,0},{6,1},{5,2} };

    reconstructQueue(people);
}