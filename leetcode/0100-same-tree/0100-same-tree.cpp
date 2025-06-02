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
    bool traversalTwoTrees(TreeNode* pNode, TreeNode* qNode) {
        if (!pNode || !qNode) { return pNode == qNode; }
        if (pNode->val != qNode->val) return false;

        return traversalTwoTrees(pNode->left, qNode->left) && traversalTwoTrees(pNode->right, qNode->right);
    }

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return traversalTwoTrees(p, q);
    }
};