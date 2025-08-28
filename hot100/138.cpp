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

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* build(vector<vector<int>> nums) {
    Node* head = new Node(nums[0][0]);
    vector<Node*> all_node;
    Node* final_head = head;
    all_node.push_back(head);
    for (int i = 1; i < nums.size(); i++) {
        head->next = new Node(nums[i][0]);
        all_node.push_back(head->next);
        head = head->next;
    }

    head = final_head;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i].size() == 2) {
            all_node[i]->random = all_node[nums[i][1]];
        }
    }

    return final_head;
}

Node* copyRandomList(Node* head) {
    Node* result = new Node(0);
    Node* temp_result = result;
    unordered_map<Node*, Node*> node_map;
    Node* temp_head = head;

    while (temp_head != nullptr) {
        temp_result->next = new Node(temp_head->val);
        node_map[temp_head] = temp_result->next;

        temp_head = temp_head->next;
        temp_result = temp_result->next;
    }

    temp_head = head;
    for (auto node : node_map) {
        if (node.first->random != nullptr) {
            node.second->random = node_map[node.first->random];
        }
    }

    return result->next;
}

int main() {
    Node* head = build({ {7},{13,0},{11,4},{10,2},{1,0} });

    auto result = copyRandomList(head);

    return 0;
}