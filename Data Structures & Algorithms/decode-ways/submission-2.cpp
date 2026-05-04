class Solution {
    /*
public:
//space and time O(n)
    int numDecodings(string s) {
       int n=s.length();
        if(n==0) return 0; //If n == 0, your dp[1] access is invalid.
        vector<int> dp(n+1,0);
        dp[0]=1;  //if no string.length==0 then 1 way not to do anything
        dp[1]=(s[0]=='0')?0:1;   //'0' as char
        for(int i=2;i<=n;i++){
            //for single digit
            if(s[i-1]!='0'){ //since s[i] is char not string, convert in int i
                dp[i]+=dp[i-1];
            }
            //for two digit
            int two_digit=(s[i-2]-'0')*10+(s[i-1]-'0');
            if(two_digit>=10 && two_digit<=26){
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }
    */

    //tabulation space O(1)
   // prev = dp[i-1]
//prev2 = dp[i-2]
public:
    int numDecodings(string s) {
        int n=s.length();
        if(n==0) return 0;
        int prev2=1;
        int prev1=(s[0]=='0')?0:1;
        for(int i=2;i<=n;i++){
            int curr=0;
            if(s[i-1]!='0'){
                curr+=prev1;
            }
            int two_digit=(s[i-2]-'0')*10+(s[i-1]-'0');
            if(two_digit>=10 && two_digit<=26){
                curr+=prev2;
            }
            prev2=prev1;
            prev1=curr;
        }
       return prev1;
    }

};
