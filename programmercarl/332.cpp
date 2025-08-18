#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;

bool backtracking(int tickets_num, unordered_map<string, map<string, int>>& targets, vector<string>& result) {
    if (tickets_num + 1 == result.size()) {
        return true;
    }

    for (auto& target : targets[result[result.size() - 1]]) {
        if (target.second > 0) {
            result.push_back(target.first);
            target.second--;
            if (backtracking(tickets_num, targets, result)) return true;
            result.pop_back();
            target.second++;
        }
    }

    return false;
}

vector<string> findItinerary(vector<vector<string>>& tickets) {
    vector<string> result;
    unordered_map<string, map<string, int>> targets;

    for (auto ticket : tickets) {
        targets[ticket[0]][ticket[1]]++;
    }

    result.push_back("JFK");

    backtracking(tickets.size(), targets, result);
    return result;
}

int main() {
    vector<string> a = { "MUC","LHR" };
    vector<string> b = { "JFK","MUC" };
    vector<string> c = { "SFO","SJC" };
    vector<string> d = { "LHR","SFO" };
    vector<vector<string>> tickets;
    tickets.push_back(a);
    tickets.push_back(b);
    tickets.push_back(c);
    tickets.push_back(d);
    findItinerary(tickets);
}