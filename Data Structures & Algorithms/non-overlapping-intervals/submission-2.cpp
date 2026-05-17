class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return 0;
        sort(intervals.begin(),intervals.end());
        int count=1;//intervals to keep
        int prevEnd=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=intervals[prevEnd][1]) {
                prevEnd=i;
                count++;
            }
            else{//keep the element with smaller value
                if(intervals[i][1]<intervals[prevEnd][1]) prevEnd =i;
            }
        }
        return intervals.size()-count;//elements to remove
        
    }
};
