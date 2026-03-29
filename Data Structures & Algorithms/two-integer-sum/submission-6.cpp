class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            int complement=target-nums[i];

//.contains checks with the key
            if (mp.contains(complement)){//.count or .contains both are same in unordered map
                return {mp[complement],i} ; //mp[complement] returns index of mp. returns vector
            }
            mp[nums[i]]=i;  //key->value.  value mapped to its index
        }
        return {};
    }
    
};
