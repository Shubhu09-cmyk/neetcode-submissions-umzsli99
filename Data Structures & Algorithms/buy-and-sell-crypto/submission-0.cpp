class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //approach 1 two pointer style
        int l=0;   //left buy
        int r=1;    //right sell
        int max_profit=0;
        while(r<prices.size()){
            if(prices[r]>prices[l]){
            int profit=prices[r]-prices[l];
            max_profit=max(profit,max_profit);
            }else{
                l=r;  //new low price for buy prices[r]<prices[l]
            }
            r++;

        }

        return max_profit;
    }
};
