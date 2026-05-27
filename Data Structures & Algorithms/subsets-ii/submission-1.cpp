/*
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
*/
class Solution {
public:
/*
| Type            | Complexity                |
| --------------- | ------------------------- |
| Time            | O(n log n + n . 2^n) |
| Auxiliary Space | O(n)                      |
| Output Space    | O(n . 2^n)            |

*/
    vector<vector<int>> result;
    vector<int> subset;
    void backtrack(vector<int>& nums, int start){
        result.push_back(subset);
        for(int i=start;i<nums.size();i++){
            if(i>start && nums[i]==nums[i-1]) continue;
            subset.push_back(nums[i]);
            backtrack(nums,i+1);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtrack(nums,0);
        return result;
        }
};
