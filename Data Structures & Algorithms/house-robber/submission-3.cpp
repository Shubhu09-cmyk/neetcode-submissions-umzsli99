class Solution {
private:
   int solu(int n,vector<int>& nums,vector<int>& dp){
    if(n==0) return nums[n];
    if(n<0) {return 0;}
    if(dp[n]!=-1) {return dp[n];}
    int pick=nums[n]+solu((n-2),nums,dp);
    int not_pick=solu((n-1),nums,dp);
    return dp[n]=max(pick,not_pick);    //tc=0(n) sc= o(n)+o(n)
   }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solu(n-1,nums,dp);
    }
};