class Solution {
    //time O(n log n)  space O(1)
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        //sorting
        sort(intervals.begin(),intervals.end());
        //traverse intervals
        for(auto& interval:intervals){
            //step 1: push non overlapping interval
            if(result.empty()||result.back()[1]<interval[0]){
                result.push_back(interval);
            }
            //step 2: merging overlapping elements
            else
            {
                result.back()[1]=max(result.back()[1],interval[1]);
            }
        }
       return result; 
    }
};
