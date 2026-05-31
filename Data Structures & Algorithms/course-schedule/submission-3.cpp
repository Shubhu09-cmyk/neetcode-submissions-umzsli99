/*
class Solution {
    //DFS Cycle Detection
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
*/

class Solution {
    //Time: O(V + E) space same. Most optimal khan's algo or topological sort
    public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);
        //making graph and indegree
        for(auto& p:prerequisites){
            graph[p[1]].push_back(p[0]);//1->0
            indegree[p[0]]++;
        }
        //push 0 indegree elements in queue
        queue<int> qu;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) qu.push(i);
        }
        int count=0;
        while(!qu.empty()){
            int node=qu.front();
            qu.pop();
            count++;
                        // early exit optimization.  not necessary
            if (count == numCourses) return true;
            //check neighbors
            for(auto& nbr:graph[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0) qu.push(nbr);
            }
            
        }
        return count==numCourses;
    }};
