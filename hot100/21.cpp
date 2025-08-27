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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* result = new ListNode(0);
    ListNode* temp = result;

    while (list1 != nullptr || list2 != nullptr) {
        if (list1!=nullptr && (list2==nullptr || list1->val <= list2->val)) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    return result->next;
}

int main() {
    ListNode* list1 = build({ 1,2,4 });
    ListNode* list2 = build({ 1,3,4 });

    auto result = mergeTwoLists(list1, list2);

    return 0;
}