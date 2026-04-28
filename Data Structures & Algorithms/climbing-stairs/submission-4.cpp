class Solution {
/*
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
       dp[0]=1;//if n==0 1 way, no jump
         dp[1]=1;//if n==1 , 1 way. as return
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];   
    }
};
*/

//space optimal
public:
    int climbStairs(int n) {
        if(n<=1) return 1;
        int prev2=1;
        int prev=1;
        for(int i=2;i<=n;i++){
            int curri=prev+prev2;
            prev2=prev;
            prev=curri;
        }
        return prev;
       
    }
};