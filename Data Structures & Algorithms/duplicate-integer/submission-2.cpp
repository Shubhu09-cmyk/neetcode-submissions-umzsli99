class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        //brute force algo, iterate through each element ; nested loop. O(n^2)time
       //optimal approach space O(n) 0(n)time
       unordered_set<int>  set;
       for(int num:nums){
        if(set.contains(num)){
            return true;
        }
        set.insert(num);
       }
return false;
    }
};