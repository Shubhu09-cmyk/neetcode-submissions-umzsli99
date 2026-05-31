/*class Solution {
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
*/

class Solution {
    // there should be 3 condition 1.graph should be connected 2. edges=n-1 3. no cycle . check any two Using DSU is most optimal
    //DSU (Union-Find).time O(n α(n)) ≈ O(n).  spaceO(n)
    public:
        vector<int> parent;
        vector<int> rank;

        int findUltimateParent(int node){
            if(parent[node]==node) return node;
            else return parent[node]=findUltimateParent(parent[node]);
        }
        bool unite(int u,int v){
            int ul_u=findUltimateParent(u);
            int ul_v=findUltimateParent(v);
            if(ul_u==ul_v) return false;  //cycle found
            if(rank[ul_u]<rank[ul_v]) parent[ul_u]=ul_v;
            else if(rank[ul_u]>rank[ul_v]) parent[ul_v]=ul_u;
            else {parent[ul_u]=ul_v;
            rank[ul_v]++;
            }
            return true;

        }
    bool validTree(int n, vector<vector<int>>& edges) {
        //check for condition 1
        if(edges.size()!=n-1) return false;

            parent.resize(n);
            rank.resize(n,0);

            //fill parent array
            for(int i=0;i<n;i++){
                parent[i]=i;
            }

        //check cycle
            for(auto& v:edges){
                if(unite(v[0],v[1])==false) return false;  //if(!unite(v[0],v[1])). If a cycle is detected, the graph cannot be a tree.
            }
            return true;
    }
};

