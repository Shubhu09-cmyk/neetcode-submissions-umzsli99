class Solution {
public:

/*
Complexity:
Time: O(V + E)
Space: O(V + E)

*/
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);

        //build graph and calculate indegree for each node. step1 
        for(auto& p:prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> que;
        //step 2 if indegree =0
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                que.push(i);
            }
        }
        vector<int> result;
        //do bfs
        while(!que.empty()){
            int curr=que.front();
            que.pop();
            result.push_back(curr);
            //neighbours
            for(int nbr:adj[curr]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    que.push(nbr);
                }
            }
        }
        if(result.size()==numCourses){
            return result;
        }
        return {};     
    }
};
