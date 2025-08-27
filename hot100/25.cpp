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

ListNode* reverseKGroup(ListNode* head, int k) {
    int len = 0;
    ListNode* temp = head;
    while (temp != nullptr) {
        len++;
        temp = temp->next;
    }

    if (len < k) return head;
    int group = len / k;
    int range = len - len % k;

    temp = head;
    int count = 0;
    ListNode* pre = nullptr;
    ListNode* cur = nullptr;
    ListNode* result = nullptr;
    while (count < group) {
        count++;
        int i = 0;
        ListNode* node = temp;
        ListNode* node_pre = pre;
        while (i < k) {
            i++;
            cur = temp;
            temp = temp->next;
            cur->next = pre;
            pre = cur;
        }
        if (node_pre != nullptr) {
            node_pre->next = cur;
        } else {
            result = cur;
        }
        node->next = temp;
        pre = node;
    }

    return result;
}

int main() {
    ListNode* head = build({ 1,2,3,4,5 });

    auto result = reverseKGroup(head, 2);

    return 0;
}