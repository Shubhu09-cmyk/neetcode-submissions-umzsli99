class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            int complement=target-nums[i];


            if (mp.count(complement)){
                return {mp[complement],i} ; //mp[complement] returns index of mp. returns vector
            }
            mp[nums[i]]=i;
        }
        return {};
    }
    
};
