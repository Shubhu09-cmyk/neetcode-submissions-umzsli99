class Solution {

    //O(ElogE)​ time; space O(E).  heizenhole algo
void dfs(string airport){  //string& will be wrong here
    auto& pq=adj[airport];  //pq is queue of nbr since pq is here refereneced
    while(!pq.empty()){
        string now=pq.top();
        pq.pop();
        dfs(now);
    }
    result.push_back(airport);// airport is just the current node
}
public:
unordered_map<string,priority_queue<string,vector<string>,greater<string>>> adj;
vector<string> result;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //create sorted adjacency list
        for(auto& ticket:tickets){
            adj[ticket[0]].push(ticket[1]);//priority queue
        }
        //dfs for starting airport
        dfs("JFK");
        reverse(result.begin(),result.end());
        return result;       
    }
};
