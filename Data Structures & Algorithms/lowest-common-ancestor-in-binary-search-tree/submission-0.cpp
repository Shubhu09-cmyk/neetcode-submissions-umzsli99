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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //recursion
        if(root==nullptr){
            return nullptr;
        }
        if(root==p || root==q){
            return root;
        }
        TreeNode* leftLCA=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightLCA=lowestCommonAncestor(root->right,p,q);

        //4 conditions both null, both valid, either left bull or only right null


        if(leftLCA!=nullptr && rightLCA!=nullptr){
            return root;
        }
        else if(leftLCA!=nullptr){
            return leftLCA;
        }
        else{
            return rightLCA;
        }
        
    }
};
