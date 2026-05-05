class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);   //INT_MAX. each element infinity
        dp[0]=0;
        for(int i=1;i<=amount;i++){  //here dp[i] is amount
        for(int coin:coins){
            if(i>=coin){
                dp[i]=min(dp[i],dp[i-coin]+1);//here 1 is coin itself like 1,5 or 10
            }
        }

        }
       return (dp[amount]>amount)?-1:dp[amount]; //dp[amount]==INT_MAX)?-1:dp[amount]
    }
};
