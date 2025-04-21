/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    Node* nodes[6000] = {};

    void preorder(Node *node, int level) {
        if (!node) return;

        if (nodes[level] != nullptr) { // 값이 있음
            nodes[level]->next = node;
        }
        nodes[level] = node;
        preorder(node->left, level + 1);
        preorder(node->right, level + 1);
    }

public:
    Node* connect(Node* root) {
        // 전위 순회하면서 이전 노드에 연결하는 식으로 하면 되지 않을까?
        preorder(root, 0);
        return root;
    }
};