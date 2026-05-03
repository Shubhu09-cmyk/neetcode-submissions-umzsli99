class Solution {
private:
    int maximumNonAdjacentSum(vector<int>& nums){
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<nums.size();i++){
            int take=nums[i];
            if(i>0) take+=prev2;
            int non_take=0+prev;
            int curri=max(take,non_take);
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp1;
        vector<int> temp2;
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);//excluding first element
            if(i!=(n-1)) temp2.push_back(nums[i]);//exclude last element
        }
        return max(maximumNonAdjacentSum(temp1),maximumNonAdjacentSum(temp2));
    }
};
