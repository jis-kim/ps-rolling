#include <vector>
#include <climits>

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

class BSTIterator {
private:
    stack<TreeNode*> st;
    
    // 현재 노드부터 가장 왼쪽 노드까지 모든 노드를 스택에 푸시
    void pushLeftNodes(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }
    
public:
    BSTIterator(TreeNode* root) {
        pushLeftNodes(root);
    }
    
    int next() {
        TreeNode* curr = st.top();
        st.pop();
        
        // 오른쪽 서브트리가 있으면 처리
        if (curr->right) {
            pushLeftNodes(curr->right);
        }
        return curr->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */