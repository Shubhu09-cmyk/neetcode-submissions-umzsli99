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
    bool isSame(TreeNode* a,TreeNode* b){
        if(a==nullptr && b==nullptr){
            return true;
        }
        if(a==nullptr || b==nullptr){
            return false;
        }
        return a->val==b->val &&
                isSame(a->left,b->left)&&
                isSame(a->right,b->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr){
            return false;  //If the main tree (root) is empty, it cannot contain subRoot.
        }
        if(isSame(root,subRoot)){
            return true;
        }
    
        return isSubtree(root->left, subRoot)  ||
               isSubtree(root->right, subRoot)  ;  //TRYING TO FIND. THE subroot in maint
    }
};
