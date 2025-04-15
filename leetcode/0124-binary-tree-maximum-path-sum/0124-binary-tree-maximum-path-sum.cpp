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
    int maxSum = INT_MIN;

    int traversal(TreeNode* root) {
        if (!root) return 0;

        int left = max(0, traversal(root->left));
        int right = max(0, traversal(root->right));

        int current = left + right + root->val;
        maxSum = max(maxSum, current);

        return root->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode* root) {
        traversal(root);
        return maxSum;
    }
};