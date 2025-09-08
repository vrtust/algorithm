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
#include<cctype>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> st;
    vector<int> result(temperatures.size(), 0);

    for (int i = 0; i < temperatures.size(); i++) {
        while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
            result[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }

    return result;
}

int main() {
    vector<int> temperatures = { 73,74,75,71,69,72,76,73 };
    auto result = dailyTemperatures(temperatures);

    return 0;
}