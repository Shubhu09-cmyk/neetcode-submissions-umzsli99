class Solution {
public:
//most optimal bottom up approach.  TC O(m*n) SC O(n). 1D - DP
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.length();
        int n=s2.length();
        int N=s3.length();
        if(m+n!=N) return false;
        vector<bool> dp(n+1);//j
        //i taken from s1 ; j taken from s2
        dp[0]=true; //s1=0 s2=0 then definitely s3=0

        //initialise first row where i=0. s1 is 0
        for(int j=1;j<=n;j++){   //Because DP includes empty prefixes too.  so m+1,n+1
           dp[j]=dp[j-1] && (s2[j-1]==s3[j-1]);
          }
        for(int i=1;i<=m;i++){
           //initialise first column. //s2 is0
              dp[0]=dp[0] && (s1[i-1]==s3[i-1]);   //s3[i+j-1] but j=0

              for(int j=1;j<=n;j++){   //Because DP includes empty prefixes too.  so m+1,n+1
            bool st2=dp[j-1] && (s2[j-1]==s3[i+j-1])  ;
            bool st1=dp[j] && (s1[i-1]==s3[i+j-1]);
             dp[j]=st1||st2;
            }
        }
       return dp[n]; 
    }
};
            