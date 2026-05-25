class Solution {
    //space O(T/M). time O(2T)
public:
    void getAllCombination(vector<int>& nums, int target, int i, vector<int>& combination, vector<vector<int>>& ans){
       
       //Worst case: O(2^n) (exponential)
        if(i==nums.size() || target<0){
            return;
        }
        if(target==0){
            ans.push_back(combination);
            return;
        }
        combination.push_back(nums[i]);
        //getAllCombination(nums,target-nums[i],i+1,combination,ans);  //single inclusion  (to avoid dupl;icate entry or create set and track if target is 0 and push unique)
        getAllCombination(nums,target-nums[i],i,combination,ans);  //multiple inclusion. reuse allowed
        combination.pop_back(); //backtrack
        getAllCombination(nums,target,i+1,combination,ans); //exclusion

    }
   
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        getAllCombination(nums,target,0,combination,ans);
        return ans;


        /* more better without set
        class Solution {
public:
    set<vector<int>> s;
    void combination(vector<int>& candidates, int target,int i,vector<int>& comb,vector<vector<int>>& ans){
        if(i==candidates.size() || target<0) return ;//bc1
        if(target==0){
            if(!s.contains(comb)){
                ans.push_back(comb);
                s.insert(comb);
            }
            return;
        }
            comb.push_back(candidates[i]);
            combination(candidates,target-candidates[i],i+1,comb,ans);     //single inclusion
            combination(candidates,target-candidates[i],i,comb,ans);     //multiple inclusion
            comb.pop_back();//backtrack
            combination(candidates,target,i+1,comb,ans);//exclusion

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        combination(candidates,target,0,comb,ans);
        return ans;
        
    }
};
*/
        
    }
};
