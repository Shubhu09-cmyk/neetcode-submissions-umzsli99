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
/*
comp is a non-static member function, but sort() expects:
either a static function
or lambda
*/
 class Solution {
    public:
    static bool comp(Interval a,Interval b){
        return a.start<b.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(),comp);

        for (int i = 1; i < intervals.size(); i++) {
            
            // conflict
            if (intervals[i].start < intervals[i - 1].end) {//class
                return false;
            }
        }

        return true;
    }
 };
/*
class Solution {
    
    Time: O(n log n) (sorting)
Space: O(1) excluding sorting space.
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());

        for (int i = 1; i < intervals.size(); i++) {
            
            // conflict
            if (intervals[i][0] < intervals[i - 1][1]) {
                return false;
            }
        }

        return true;
    }
};
*/        

