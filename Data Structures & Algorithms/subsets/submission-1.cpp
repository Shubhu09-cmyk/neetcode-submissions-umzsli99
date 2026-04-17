class Solution {
public:
 void getAllsubset(vector<int>& nums,vector<int>& ans, int i,vector<vector<int>>& allSubsets){
    if(i==nums.size()){
        allSubsets.push_back(ans);
        return;  //Then you must STOP further recursion
    }
    ans.push_back(nums[i]);
    getAllsubset(nums,ans,i+1,allSubsets);//inclusion
    ans.pop_back();//backtrack
    getAllsubset(nums,ans,i+1,allSubsets);//exclusion


 }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> ans;
        getAllsubset(nums,ans,0,allSubsets);
        return allSubsets;     
    }
};
