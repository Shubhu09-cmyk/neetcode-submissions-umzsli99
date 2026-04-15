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
   int helper(TreeNode* root,int &maxSum){          //pass maxSum by reference otherWise it will take garbage  value or declare it globally
    if(root==nullptr){
        return 0;
    }
    int leftSum=max(0,helper(root->left,maxSum));//if root->left negative then consider 0
    int rightSum=max(0,helper(root->right,maxSum));
    maxSum=max(maxSum,(leftSum+rightSum+root->val));
    return root->val+max(leftSum,rightSum);
   }
  
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        helper(root,maxSum);
        return maxSum;
    }
};
