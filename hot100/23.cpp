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

ListNode* merge(ListNode* head1, ListNode* head2) {
    ListNode* result = new ListNode(0);
    ListNode* temp = result;

    while (head1 != nullptr || head2 != nullptr) {
        if (head1 != nullptr && (head2 == nullptr || head1->val <= head2->val)) {
            temp->next = head1;
            head1 = head1->next;
        } else {
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }

    return result->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    // if (lists.empty()) return nullptr;

    // while (lists.size() > 1) {
    //     ListNode* newList = merge(lists[0], lists[1]);
    //     lists.erase(lists.begin());
    //     lists.erase(lists.begin());
    //     lists.push_back(newList);
    // }

    // return lists[0];

    auto cmp = [](const ListNode* a, const ListNode* b) {
        return a->val > b->val;
        };

    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
    for (auto head : lists) {
        if (head != nullptr) {
            pq.push(head);
        }
    }

    ListNode* dummpy = new ListNode(0);
    ListNode* temp = dummpy;
    while (!pq.empty()) {
        ListNode* cur = pq.top();
        pq.pop();

        if (cur->next != nullptr) {
            pq.push(cur->next);
        }
        temp->next = cur;
        temp = temp->next;
    }

    return dummpy->next;
}

int main() {
    vector<ListNode*> lists = { build({ 1,4,5 }), build({ 1,3,4 }), build({ 2,6 }) };

    auto result = mergeKLists(lists);

    return 0;
}