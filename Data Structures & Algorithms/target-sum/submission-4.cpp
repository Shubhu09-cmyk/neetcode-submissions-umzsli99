class Solution {
public:
//O(n * subsetSum).  O(subsetSum)
/*

transform +ve/-ve problem intro subsetSum Problem
Because the problem says:
Put either + or - before every number so that the final expression equals target.
So divide the numbers into 2 groups:
P → numbers given +
N → numbers given -
Then the final expression becomes:
(sum of positive numbers) - (sum of negative numbers)
which is:
P - N
And since this final value must equal target:
P - N = target
*/
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum=0;
        for(int x : nums){
          totalSum+=x;  
        }
        if(abs(target)>totalSum) return 0;  //impossible case
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
