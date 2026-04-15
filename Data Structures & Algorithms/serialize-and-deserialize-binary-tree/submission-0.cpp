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

class Codec {
public:

    // Encodes a tree to a single string.
    void serializeHelper(TreeNode* root,string &s){
        if(root==nullptr){
            s+="N,";
            return ;
        }
        s+=to_string(root->val)+",";
        serializeHelper(root->left,s);
        serializeHelper(root->right,s);

    }
    string serialize(TreeNode* root) {
        string s="";
        serializeHelper(root,s);
        return s;    

    }

    // Decodes your encoded data to tree.

    //helper function
    TreeNode* build(vector<string>& data,int& i){
        if(i >= data.size()) return nullptr;

        if(data[i]=="N"){
            i++;
            return nullptr;
        }
    TreeNode* root=new TreeNode(stoi(data[i]));
    i++;
    root->left=build(data,i);
    root->right=build(data,i);
    return root;
    }
    TreeNode* deserialize(string data) {
        vector<string> vec;
        string temp="";
        for(char c : data){
            if(c==','){
                vec.push_back(temp);
                temp="";
            }else{
                temp+=c;
            }
        }
        if (!temp.empty()) vec.push_back(temp);
        int i=0;
        return build(vec,i);
        
    }
};
