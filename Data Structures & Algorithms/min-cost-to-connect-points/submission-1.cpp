class Solution {

    /*
    ⏱️ Time Complexity:
O(n ^2logn)
Because heap dominates.
🧠 Space Complexity:
O(n^2)
Because of adjacency list storage.
The most common interview solution is Prim's Algorithm without explicitly storing all edges.
*/
private:
    int mst(vector<vector<pair<int,int>>>& adj,int n){//prim's algo codd
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

/*
class Solution {
    
    Approach	Time	Space	Optimal?
Your version (heap + adjacency)	O(n² log n)	O(n²)	❌
Prim without adjacency (best)	O(n²)	O(n)	✅

public:
    int mst(vector<vector<pair<int,int>>>& adj,int n){
        priority_queue<
        pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>
        > pq;//min que cost,vertex
        int minCost=0;
        pq.push({0,0});//cost /edge 0 and vertex 0
        vector<bool> vis(n);
        while(!pq.empty()){
            auto [cost,node]=pq.top();
            pq.pop();
            if(vis[node]==true) continue;
            minCost+=cost;
            vis[node]=true;
            for(auto& nbr:adj[node]){
                if (!vis[nbr.second]) { 
                   // pq.push(nbr); sometimes fragile
                pq.push({nbr.first,nbr.second});//if in adj i,d pushed
                }
            }
        }
        return minCost;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>> adj(n);// distance,vertex
        //fill adjacency graph
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int d=abs((points[j][0]-points[i][0]))+abs((points[j][1]-points[i][1]));
                adj[j].push_back({d,i});
                adj[i].push_back({d,j});
            }
        }
        return mst(adj,n);//calling prim's algo
    }
};
*/
