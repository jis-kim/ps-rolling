

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
    int total;

    int sumParent(TreeNode* cur, int prevSum) {
        prevSum = prevSum * 10 + cur->val;
        if (!cur->left && !cur->right) {
            cout << prevSum <<endl;
            return prevSum;
        } 
        int left = 0, right = 0;
        if (cur->left) {
            left = sumParent(cur->left, prevSum);
        }
        if (cur->right) {
            right = sumParent(cur->right, prevSum);
        }
        return left + right;
    }

public:
    int sumNumbers(TreeNode* root) {
        // int 범위 내의 숫자를 표현한다.
        // 즉 나의 부모를 모두 10의 숫자로 더한 숫자인(?) 거임. 그럼 재귀로 하면 되지 않을?까? 
        return sumParent(root, 0);
    }
};