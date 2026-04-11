 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       
       /*
        //recursion.  normal binary tree
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
        */


        //BFS BST
        while(root!=nullptr){
            if(p->val <root->val && q->val <root->val){
                root=root->left;
            }
            else if(p->val >root->val && q->val >root->val){
                root=root->right;
            }
            else return root;
        }
        return nullptr;
    }

};

    
