class Solution {
    //TC O(mxn). SC O(amount)

    /*
    No — in the general case, you cannot reduce this to O(1) space for the Coin Change Problem.
Why O(1) space doesn’t work here
Your DP relies on this state definition:
dp[i] = minimum coins needed to make amount i
Each dp[i] depends on previously computed states (dp[i - coin]) for many different values of i.
So you need to keep all results from 0 → amount available at the same time.
That immediately implies:
Minimum required memory = O(amount)
*/
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
