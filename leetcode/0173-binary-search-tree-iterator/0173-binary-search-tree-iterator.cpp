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
    vector<TreeNode*> index;
    vector<TreeNode*>::iterator indexIt;

    void makeMetaTree(TreeNode* root) {
        if(!root) return ;

        makeMetaTree(root->left);
        index.push_back(root);
        makeMetaTree(root->right);
    }

public:
    /**
    * in-order(중위순회)하는 BST iterator를 만들어라
    * 왼쪽 자식 -> 루트 -> 오른쪽자식.
    */
    BSTIterator(TreeNode* root) { //생성자
        makeMetaTree(root);
        indexIt = index.end();
    }
    
    int next() {
        // first call will return the smallest element
        // next가 ㄹㅇ로 있는 경우에만 호출한다고 가정함.
        // 부모가 있다면, 부모.
        // 부모가 없다면, 오른쪽 자식.
        if (indexIt == index.end()) {
            indexIt = index.begin();
        } else {
            ++indexIt;
        }
        return (*indexIt)->val;
    }
    
    bool hasNext() {
        return (indexIt + 1) != index.end();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */