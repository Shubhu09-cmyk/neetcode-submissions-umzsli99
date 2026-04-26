class Solution {
private:
        bool dfsCycle(int src,vector<bool>& vis,vector<bool>& recPath,vector<vector<int>>& prerequisites){
            vis[src]=true;
            recPath[src]=true;
            for(int i=0;i<prerequisites.size();i++){
                int v=prerequisites[i][0];
                int u=prerequisites[i][1];
                if(src==u){
                    if(vis[v]==false){
                        if(dfsCycle(v,vis,recPath,prerequisites)==true){
                            return true;
                        }
                    }else{  //if vis[v]==true
                        if(recPath[v]==true){
                        return true;
                        }
                    }
                }
            }
            recPath[src]=false;
            return false;
        }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<bool> vis(numCourses,false);
     vector<bool> recPath(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(vis[i]==false){
             if(dfsCycle(i,vis,recPath,prerequisites)){
                return false;
             }
             
            }
           
        }
       return true; 
    }
};
