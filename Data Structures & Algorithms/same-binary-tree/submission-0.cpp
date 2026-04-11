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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //method 1 recursion
        if(p==nullptr && q==nullptr)  //empty
        {
            return true;
        }
        if(p==nullptr || q==nullptr)  //any one empty. one not
        {
            return false;
        }
        if(p->val!=q->val){ //value mismatch
            return false;
        }
        //check left and right subtree
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        
        
    }
};
