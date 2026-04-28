class Solution {
public:/*

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1);
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<=cost.size();i++){
            dp[i]=min(cost[i-1]+dp[i-1],cost[i-2]+dp[i-2]);  //dp=mincost
        }
      return dp[cost.size()]  ;  //return min(dp[n-1], dp[n-2]);
    }
};*/
//optimal in terms of space
    int minCostClimbingStairs(vector<int>& cost) {
        
        int prev1=cost[1];  // cost to reach step 1
        int prev2=cost[0];  //cost to reach step 0
        for(int i=2;i<=cost.size()-1;i++){

           /* 👉 cost[i] = cost of stepping on index i
So valid indices are:
0 → n-1
But the “top” is NOT inside the array — it is after index n-1.*/
            int curri=cost[i]+min(prev1,prev2);  
            prev2=prev1;
            prev1=curri;
        }
      return  min(prev1,prev2) ;  //return min(dp[n-1], dp[n-2]);
    }
};
