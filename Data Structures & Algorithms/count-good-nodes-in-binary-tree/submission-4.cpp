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
 // /*
        //method-1 recursion
    int ans=0 ;//global variable;
    void dfs(TreeNode* root,int max){
        if(root==nullptr){
            return ;
        }
        if(root->val>=max){
            ans++;
            max=root->val;
        }
        dfs(root->left,max);
        dfs(root->right,max);
    }
    int goodNodes(TreeNode* root) {
           dfs(root,root->val);
        return ans;
    }
  //  */
};
