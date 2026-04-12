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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        queue<TreeNode*> q;
        if(root==nullptr){
            return v;
        }
        q.push(root);
        while(!q.empty()){
            vector<int> v1;
            int x=q.size();
            
            for(int i=0;i<x;i++){
                TreeNode* curr=q.front();
            q.pop();
                if(curr->left!=nullptr){
                    q.push(curr->left);
                }if(curr->right!=nullptr){
                    q.push(curr->right);
            }
             v1.push_back(curr->val);
            }
            v.push_back(v1);
        }
        return v;
    }
};
