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
    Node* dfs(Node* curr,unordered_map<Node*,Node*>& mp){   //better make map as global parameter so no need to pass everytime
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

        /*for(Node* nbr : curr->neighbors){
    clone->neighbors.push_back(dfs(nbr, mp));
}. can use this also
*/
        return clone;
    }
public:
    
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        if(!node) return nullptr;
        return dfs(node,mp);
     }

};
