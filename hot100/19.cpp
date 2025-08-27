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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* new_head = new ListNode(0);
    new_head->next = head;
    ListNode* slow = new_head;
    ListNode* fast = new_head;
    while (n--) {
        fast = fast->next;
    }

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;
    return new_head->next;
}

int main() {
    ListNode* head = build({ 1 });

    auto result = removeNthFromEnd(head, 2);

    return 0;
}