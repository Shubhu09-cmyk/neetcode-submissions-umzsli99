/*class Solution {
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
*/
class Solution {
    //time complexity O(n⋅n!) ; O(n).  //without using vector used, space(n^2) because find use extra mem
public:
    void backtrack(vector<vector<int>>& result,vector<int>& temp,vector<bool>& used,vector<int>& nums){
        if(temp.size()==nums.size()) {
            result.push_back(temp);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]==true) continue ;
            used[i]=true;
            temp.push_back(nums[i]);
            backtrack(result,temp,used,nums);
            //backtrack
            temp.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        vector<bool> used(nums.size(),false);
        backtrack(result,temp,used,nums);
        return result;        
    }
};
