class Solution {
private:
        bool dfsCycle(int src,vector<bool>& vis,vector<bool>& recPath,vector<vector<int>>& adj_graph){
            vis[src]=true;
            recPath[src]=true;
            for(auto& nbr:adj_graph[src]){
                    if(vis[nbr]==false){
                        if(dfsCycle(nbr,vis,recPath,adj_graph)==true){
                            return true;
                        }
                    }else{  //if vis[v]==true
                        if(recPath[nbr]==true){
                        return true;
                        }
                    }
                }
            
            recPath[src]=false;
            return false;
        }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            vector<vector<int>> adj_graph(numCourses);
        // build graph: u -> v means u depends on v
        for(auto& p:prerequisites){
            adj_graph[p[1]].push_back(p[0]);//b->a. 1->0
 }
       vector<bool> vis(numCourses,false);
     vector<bool> recPath(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(vis[i]==false){
             if(dfsCycle(i,vis,recPath,adj_graph)){
                return false;
             }
             
            }
           
        }
       return true; 
    }
};
