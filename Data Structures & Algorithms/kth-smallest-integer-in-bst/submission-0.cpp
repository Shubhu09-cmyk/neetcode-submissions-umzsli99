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
    int kthSmallest(TreeNode* root, int k) {
        //“kth smallest in BST = inorder traversal + stop early”
        //“Push left → pop smallest → repeat until k = 0”

        stack<TreeNode*> st;
        st.push(root);
        while(!root || !st.empty()){

            while(root){ //we need to reach at the most left 
                st.push(root);
                root=root->left;
            }
            root=st.top();
            st.pop();
            k--;
            if(k==0){
                return root->val;
            }

        root=root->right;
        }
    }
};
