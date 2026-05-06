class Solution {
public:
/*
TC O(m*n). SC O(m*n)
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0) dp[i][j]=1;
                else{
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
    */

    //make space optimised.  C O(m*n). SC O(n) taking 1 D array in dp
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[j]+=dp[j-1];  //before update dp[j] was top and dp[j-1] is already updated left
            }
        }
return dp[n-1];
    }
};
