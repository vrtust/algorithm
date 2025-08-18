#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
#include<stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    // vector<int> result(temperatures.size(), 0);

    // for (int i = 0; i < temperatures.size(); i++) {
    //     if (i >= 1 && temperatures[i - 1] == temperatures[i] && result[i - 1] > 0) {
    //         result[i] = result[i - 1] - 1;
    //     } else {
    //         int count = 0;
    //         for (int j = i + 1; j < temperatures.size(); j++) {
    //             count++;
    //             if (temperatures[i] < temperatures[j]) {
    //                 result[i] = count;
    //                 break;
    //             }
    //         }
    //     }
    // }

    // return result;

    vector<int> result(temperatures.size(), 0);
    stack<int> st;
    st.push(0);

    for (int i = 1; i < temperatures.size(); i++) {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
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
}