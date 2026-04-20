class Solution {
public:
    void allSubset(vector<int>& nums,vector<vector<int>>& result,vector<int>& subset,int i){
        if(i==nums.size()){
            result.push_back(subset);
            return ;
        }
        subset.push_back(nums[i]);
        allSubset(nums,result,subset,i+1);
        subset.pop_back();
        int idx=i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]){    
            idx++;
        }
        allSubset(nums,result,subset,idx);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        sort(nums.begin(),nums.end());
        allSubset(nums,result,subset,0);
        return result;       
    }
};
