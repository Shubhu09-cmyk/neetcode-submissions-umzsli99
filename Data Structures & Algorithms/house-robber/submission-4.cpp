class Solution {
    /*
private:
   int solu(int n,vector<int>& nums,vector<int>& dp){
    if(n==0) return nums[n];
    if(n<0) {return 0;}
    if(dp[n]!=-1) {return dp[n];}
    int pick=nums[n]+solu((n-2),nums,dp);
    int not_pick=0+solu((n-1),nums,dp);
    return dp[n]=max(pick,not_pick);    //tc=0(n) sc= o(n)+o(n)
   }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solu(n-1,nums,dp);
    }
    */


    //now most optimized tabulation form ;  sc O(1).  TC O(n)
    
    public:
    int rob(vector<int>& nums){
        int prev=nums[0];
        int prev2=0;  //if negative
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

};