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

ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            ListNode* index1 = head;
            ListNode* index2 = slow;
            while (index1 != index2) {
                index1 = index1->next;
                index2 = index2->next;
            }
            return index1;
        }
    }

    return nullptr;
}

int main() {
    ListNode* head = build({ 1,1,2,1 });


    auto result = detectCycle(head);

    return 0;
}