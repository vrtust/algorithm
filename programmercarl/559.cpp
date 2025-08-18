#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

int maxDepth(Node* root) {
    deque<Node*> dq;

    if (root != nullptr) {
        dq.push_back(root);
    }

    int count = 0;

    while (!dq.empty()) {
        count++;
        int size = dq.size();
        for (int i = 0; i < size; i++) {
            Node* node = dq.front();
            dq.pop_front();
            for (auto child : node->children) {
                dq.push_back(child);
            }
        }
    }

    return count;
}

int main() {
    Node* root = new Node(1);
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(5));
    root->children[0]->children.push_back(new Node(6));

    bool result = maxDepth(root);
}