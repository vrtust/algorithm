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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    bool carry = false;
    ListNode* result = new ListNode(0);
    ListNode* temp = result;

    while (l1 != nullptr || l2 != nullptr) {
        int sum = 0;
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }
        if (carry) {
            sum += 1;
            carry = false;
        }
        if (sum / 10 != 0) {
            carry = true;
            temp->next = new ListNode(sum - 10);
        } else {
            temp->next = new ListNode(sum);
        }

        temp = temp->next;
    }

    if (carry) {
        temp->next = new ListNode(1);
    }

    return result->next;
}

int main() {
    ListNode* list1 = build({ 2,3,4 });
    ListNode* list2 = build({ 5,6,4 });

    auto result = addTwoNumbers(list1, list2);

    return 0;
}