/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void traversal(TreeNode *node, vector<int>& v) {
        if (!node) return;
        traversal(node->left, v);
        v.emplace_back(node->val);
        traversal(node->right, v);

    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;

        traversal(root, result);
        return result;
    }
};