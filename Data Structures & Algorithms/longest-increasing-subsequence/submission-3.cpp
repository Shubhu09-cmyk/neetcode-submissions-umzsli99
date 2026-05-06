class Solution {
    //  TC O(n^2). sc O(n)
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if (n==0)  return 0;  //if (nums.empty()) return 0;
      vector<int> dp(n,1);
      for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        
      } 
      int maxLen=0;
      for(int x:dp){
        maxLen=max(x,maxLen);
      } 
      return maxLen;
    }
};
