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

/*
Time
O(H + k)
Worst case:
O(n)
Space
O(H)
where H is tree height.
*/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        //“kth smallest in BST = inorder traversal + stop early”
        //“Push left → pop smallest → repeat until k = 0”

        stack<TreeNode*> st;
        TreeNode* curr=root;
        while(curr!=nullptr || !st.empty()){
            while(curr){ //we need to reach at the most left 
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            st.pop();
            k--;
            if(k==0){
                return curr->val;
            }

        curr=curr->right;
        }
        return -1;
    }
};
