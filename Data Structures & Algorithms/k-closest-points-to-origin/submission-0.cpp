class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> maxHeap;  //buy default max heap(distance,points)
        for(auto& point:points){
           int dist=point[0]*point[0]+point[1]*point[1];
                maxHeap.push({dist,{point[0],point[1]}});
                 if(maxHeap.size()>k){
                    maxHeap.pop();
            }
        }
        vector<vector<int>> vec;
       while(!maxHeap.empty()){
        
        vec.push_back({maxHeap.top().second.first,maxHeap.top().second.second});
       // vec.push_back(maxHeap.top().second.second);
        maxHeap.pop();

       } 
       return vec;
    }
};
