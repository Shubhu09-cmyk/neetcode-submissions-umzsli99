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
    int maxDepth(TreeNode* root) {
        /*
        method 1 :using recursion
        if(root==nullptr){
            return 0 ;
        }
        return 1+max(maxDepth(root->left),maxDepth(root->right)); //left=maxDepth(root->left)  
        */

        //method-2. using bfs iteration
        if(root==nullptr){
            return 0 ;
        }
        queue<TreeNode*> q;
        int level=0;   //level or depth
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            level++;

            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left!=nullptr){
                    q.push(curr->left);
                }
                if(curr->right!=nullptr){
                    q.push(curr->right);
            }
            }
        
        }
return level;
        
        
    }
};
