class Solution {
public:
    void getAllCombination(vector<int>& nums, int target, int i, vector<int>& combination, vector<vector<int>>& ans){
        if(i==nums.size() || target<0){
            return;
        }
        if(target==0){
            ans.push_back(combination);
            return;
        }
        combination.push_back(nums[i]);
        //getAllCombination(nums,target-nums[i],i+1,combination,ans);  //single inclusion  (to avoid dupl;icate entry or create set)
        getAllCombination(nums,target-nums[i],i,combination,ans);  //multiple inclusion
        combination.pop_back(); //backtrack
        getAllCombination(nums,target,i+1,combination,ans); //exclusion

    }
   
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        getAllCombination(nums,target,0,combination,ans);
        return ans;
        
    }
};
