class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        //brute force algo, iterate through each element ; nested loop. O(n2)
       //optimal approach O(n)
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