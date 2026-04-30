class Solution {

    /*
    ⏱️ Time Complexity:
O(n 
2
 logn)
Because heap dominates.
🧠 Space Complexity:
O(n 
2
 )
Because of adjacency list storage.
*/
private:
    int mst(vector<vector<pair<int,int>>>& adj,int n){
        //create min heap pq
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});//weight/edge/cost  and vertex
        vector<bool> vis(n,false);
        
         int sum=0;
        while(!pq.empty()){
            auto [cost,currNode]=pq.top();
            pq.pop();
           if(vis[currNode]==true) continue;
            vis[currNode]=true;
            sum+=cost;
            for(auto& nbr:adj[currNode]){
                
                    pq.push({nbr.second,nbr.first});//pair<int, int>' does not provide a subscript operator
                
            }
        }
        return sum;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int v=points.size();//vertex
        //create adjacency list
        vector<vector<pair<int,int>>> adj(v);
        for(int i=0;i<v;i++){
            for(int j=i+1;j<v;j++){
               int d=abs(points[j][0]-points[i][0])+abs(points[j][1]-points[i][1]);
               adj[i].push_back({j,d});
               adj[j].push_back({i,d});
            }
        }
       return mst(adj,v);//call prim's algo  
    }
};
