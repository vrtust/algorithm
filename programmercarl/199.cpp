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

vector<vector<int>> rightSideView(Node* root) {
    vector<vector<int>> result;
    queue<Node*> queue_node;

    if (root != nullptr) {
        queue_node.push(root);
        result.push_back({ root->val });
    }

    while (!queue_node.empty()) {
        int size = queue_node.size();
        vector<int> temp;

        for (int i = 0; i < size; i++) {
            Node* node = queue_node.front();
            queue_node.pop();
            for (auto child : node->children) {
                queue_node.push(child);
                temp.push_back(child->val);
            }
        }
        if (temp.size() > 0) {
            result.push_back(temp);
        }
    }

    return result;
}


int main() {
    Node* root = new Node();

    rightSideView(root);
}