#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<stack>
#include<unordered_set>
#include<queue>
#include<stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
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

ListNode* swapPairs(ListNode* head) {
    ListNode* new_head = new ListNode(0);
    new_head->next = head;
    ListNode* temp = new_head;

    while (temp != nullptr && temp->next != nullptr && temp->next->next != nullptr) {
        ListNode* p = temp->next;
        ListNode* pp = temp->next->next;
        ListNode* ppp = temp->next->next->next;

        temp->next = pp;
        temp->next->next = p;
        temp->next->next->next = ppp;

        temp = p;
    }

    return new_head->next;
}

int main() {
    ListNode* head = build({ 1,2,3,4 });

    auto result = swapPairs(head);

    return 0;
}