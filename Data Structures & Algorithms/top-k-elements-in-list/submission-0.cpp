class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //creating mapping num to their frequency. {1,1}{2,2}{3,3}
        unordered_map<int,int> count;
        for (int num: nums){
        count[num]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_heap;

        //keeping map elements in min heap
        for (auto [num,freq]:count){
            min_heap.push({freq,num});   //{pair} 
            if (min_heap.size()>k){
                min_heap.pop();
            }
        }
            vector<int> result;
            while(!min_heap.empty()){
                result.push_back(min_heap.top().second);
                min_heap.pop();
            }

        return result;
        
    }
};
