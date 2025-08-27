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

bool isPalindrome(ListNode* head) {
    ListNode* middleNode = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        middleNode = middleNode->next;
        fast = fast->next->next;
    }

    ListNode* pre = nullptr;
    ListNode* reverseHead = nullptr;
    ListNode* originalHead = head;

    while (middleNode != nullptr) {
        reverseHead = middleNode;
        middleNode = middleNode->next;
        reverseHead->next = pre;
        pre = reverseHead;
    }

    while (originalHead != nullptr && reverseHead != nullptr) {
        if (originalHead->val != reverseHead->val) {
            return false;
        }
        originalHead = originalHead->next;
        reverseHead = reverseHead->next;
    }

    return true;
}

int main() {
    ListNode* head = build({ 1,1,2,1 });


    auto result = isPalindrome(head);

    return 0;
}