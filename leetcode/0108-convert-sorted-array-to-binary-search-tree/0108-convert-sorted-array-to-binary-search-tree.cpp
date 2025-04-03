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
    TreeNode* makeTree(vector<int>& nums, int left, int right){
        if (left > right) return nullptr;
        int middle = left + (right - left) / 2;

        TreeNode* head = new TreeNode(nums[middle]);
        head->left = makeTree(nums, left, middle - 1);
        head->right = makeTree(nums, middle + 1, right);
        return head;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeTree(nums, 0, nums.size() - 1);
    }
};