class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(int x:nums){
            total+=x;
        }
        
        if(total%2) return 0;
        int target=total/2;
        vector<bool> dp(target+1,false);
        dp[0]=true;
        for(int num:nums){
            for(int j=target;j>=num;j--){
                dp[j]=dp[j]||dp[j-num];
            }
        }
       return dp[target]; 
    }
};
