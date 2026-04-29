class Solution {
public:
//Time: O(E log V) Djksashtra
//Space: O(V + E)
//Dijkstra finds how fast each node can receive 
//the signal, and the answer is how long we must wait for the slowest one.so max
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj_graph(n+1);
        for(auto& edge:times){
            adj_graph[edge[0]].push_back({edge[1],edge[2]});   //u->{v,w}. node->nbr,weight
        }
        vector<int> dis(n+1,INT_MAX);
        dis[k] = 0;//set source dis
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> qu; //min_heap
        qu.push({0,k});  //source node takes 0 time to travel to self
        while(!qu.empty()){
            auto [time,node]=qu.top();
            qu.pop();
            if(time>dis[node]) continue;  //skip outdated entries
            for(auto& [nbr,t]:adj_graph[node]){
                if(dis[node]+t<dis[nbr]){
                    dis[nbr]=dis[node]+t;
                    qu.push({dis[nbr],nbr});
                }
            }
        }
            int max_time=0;
            for(int i=1;i<=n;i++){
                if(dis[i]==INT_MAX) return -1;
                max_time=max(dis[i],max_time);
            
        }
     return max_time;   
    }
};
