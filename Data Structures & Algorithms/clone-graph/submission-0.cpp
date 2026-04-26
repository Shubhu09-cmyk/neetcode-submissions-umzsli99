/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    private:
    Node* dfs(Node* curr,unordered_map<Node*,Node*>& mp){
        if(mp.count(curr)){
            return mp[curr];
        }
        
            Node* clone=new Node(curr->val);
            mp[curr]=clone;
        

        vector<Node*> neighbor;
        for(Node* nbr:curr->neighbors){
            
                neighbor.push_back(dfs(nbr,mp));
            
        }
        clone->neighbors=neighbor;
        return clone;
    }
public:
    
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        if(!node) return nullptr;
        return dfs(node,mp);
     }

};
