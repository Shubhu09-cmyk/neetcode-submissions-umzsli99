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
    TreeNode* invertTree(TreeNode* root) {
        /*method 1 recursion
        if(root==nullptr){
            return nullptr;
        }
        TreeNode* left=invertTree(root->left);
        TreeNode* right=invertTree(root->right);
        root->left=right;
        root->right=left;
        return root;
        */
        if(root==nullptr){
            return nullptr;
        }
        queue<TreeNode*> q;
        //step 1.  push the root
        q.push(root);
        //step 2. pop root from queue and invert it
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            TreeNode* temp=curr->left;
            curr->left=curr->right;
            curr->right=temp;

            if(curr->left!=nullptr){
                q.push(curr->left);
            }
            if(curr->right!=nullptr){
                q.push(curr->right);
            }

        }
        return root;

        
    }
};
