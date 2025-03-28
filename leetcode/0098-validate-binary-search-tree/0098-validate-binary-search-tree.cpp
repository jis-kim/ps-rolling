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
    TreeNode *prevNode = nullptr;
public:
    bool isValidBST(TreeNode* root) {
    // 이전에 나온 수보다 현재 수가 크거나 같은지 비교하면 된다.
        if (!root) return true;
 
        // 왼쪽 서브트리 검사
        if (!isValidBST(root->left)) return false;
        
        // 현재 노드가 이전 노드보다 커야 함 (중위 순회 특성)
        if (prevNode && root->val <= prevNode->val) return false;
        prevNode = root;
        
        // 오른쪽 서브트리 검사
        return isValidBST(root->right);
    }
};