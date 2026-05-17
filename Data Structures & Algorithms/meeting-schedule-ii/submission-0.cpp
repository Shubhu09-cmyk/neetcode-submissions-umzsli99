/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
    //time O(n log n). space O(n)
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        map<int,int> events;
        for(auto& meeting:intervals){
            events[meeting.start]++;
            events[meeting.end]--;
        }
        int overlap=0;
        int maxOverlap=0;
        for(auto& pq:events){
            overlap+=pq.second;
            maxOverlap=max(maxOverlap,overlap);
       }
        
     return maxOverlap;   
    }
};
