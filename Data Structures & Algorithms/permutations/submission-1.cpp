class Solution {
public:

    void backtrack(vector<int>& nums,vector<int>& temp,vector<vector<int>>& result){
        if(temp.size()==nums.size()){
            result.push_back(temp);
            return;
        }
        for(int number:nums){
            if(find(temp.begin(),temp.end(),number)!=temp.end()){
                continue;
            }
            temp.push_back(number);
            backtrack(nums,temp,result);
            temp.pop_back();

        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        backtrack(nums,temp,result);
        return result;
        
    }
};
