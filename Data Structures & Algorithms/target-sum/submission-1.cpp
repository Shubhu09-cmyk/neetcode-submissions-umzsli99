class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum=0;
        for(int x : nums){
          totalSum+=x;  
        }
        if(target>totalSum) return 0;
        if((target+totalSum)%2==1) return 0;//if sum -ve. then can't find subset
        int subsetSum=(target+totalSum)/2;
        vector<int> dp(subsetSum+1,0);
        dp[0]=1;  //for sum to be 0; only one way possible
        for(int num:nums){
            for(int j=subsetSum;j>=num;j--){
                dp[j]+=dp[j-num];
            }
        }
        return dp[subsetSum];
    }
};
