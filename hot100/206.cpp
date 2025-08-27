#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<stack>
#include<unordered_set>
#include<queue>

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

ListNode* reverseList(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* cur = nullptr;

    while (head != nullptr) {
        cur = head;
        head = head->next;
        cur->next = pre;
        pre = cur;
    }

    return cur;
}

int main() {
    ListNode* head = build({ 1,2,3,4,5 });


    auto result = reverseList(head);

    return 0;
}