class Solution {
private:
    bool dfsCycle(int curr,int parent,vector<bool>& vis,vector<vector<int>>& adj){
        vis[curr]=true;
        for(int nbr:adj[curr]){
            if(!vis[nbr]){
                if(dfsCycle(nbr,curr,vis,adj)==true){
                    return true;
                }
            }
            else{
                    if(nbr!=parent){
                        return true;   //cycle detected
                    }
                }
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        //for valid tree edges should be n-1;
        if(edges.size()!=n-1){  //condition1
            return false;
        }
        
        vector<vector<int>> adj(n);
        //build adjacency list
        for(auto& e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n,false);
        if(dfsCycle(0,-1,vis,adj)==true){//if cycle formed  //condition 2
        return false;   //node 0 parent -1
        }

        //condition 3. if no unvisited node is there it means connected
        for(bool v:vis){
            if(!v){
                return false;
            }
        }
        return true;

    }
};
