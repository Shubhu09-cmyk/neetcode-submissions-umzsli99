class Solution {
public:
//TC O(n). SC O(1)
    bool canJump(vector<int>& nums) {
        int farthest=0;
        for(int i=0;i<nums.size();i++){
            //if i>farthest  current index is unreachable
            if(i>farthest) return false;
            //update farthest reachablke index
            farthest=max(farthest,i+nums[i]);
            //already can reach end
            if(farthest>=(nums.size()-1)) return true;
        }
       return true; 
    }
};
