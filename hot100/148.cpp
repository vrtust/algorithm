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

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* build(vector<int> nums) {
    ListNode* head = new ListNode(nums[0]);
    ListNode* final_head = head;
    for (int i = 1; i < nums.size(); i++) {
        head->next = new ListNode(nums[i]);
        head = head->next;
    }
    return final_head;
}

ListNode* sortList(ListNode* head) {
    map<int, vector<ListNode*>> nodes;
    set<int> nums;

    ListNode* temp = head;
    while (temp != nullptr) {
        nums.insert(temp->val);
        nodes[temp->val].push_back(temp);
        temp = temp->next;
    }

    ListNode* result = new ListNode(0);
    temp = result;
    for (int num : nums) {
        for (auto node : nodes[num]) {
            temp->next = node;
            temp = temp->next;
        }
    }
    temp->next = nullptr;

    return result->next;
}

int main() {
    ListNode* head = build({ 4,2,1,3 });

    auto result = sortList(head);

    return 0;
}