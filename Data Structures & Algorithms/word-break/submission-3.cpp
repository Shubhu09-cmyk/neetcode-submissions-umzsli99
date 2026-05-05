class Solution {
public:

/*
w.length() is size_t. unsigned long so casting
🧠 Why casting is preferred
Because:
DP indices are int
string indices are int
mixing size_t often causes hidden bugs in loops
So we standardize everything to int.
Type	Cost
Time	O(n²) worst case
Space	O(n + dictionary)
*/
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        int n=s.length();
        vector<bool> dp(n+1,false);
        int maxLen=0;
        for(auto& w:wordDict){
            maxLen=max(maxLen,(int)w.length());
        }
        dp[0]=true;//empty string is always valid
        for(int i=1;i<=n;i++){   //iterate over dp[1] to dp[n]
            for(int j=i-1;j>=max(0,i-maxLen);j--){// index cannot go negative
                if(dp[j]==false) continue;  //it is false then not valid
            //    else{   //after if else is guaranteed
                    if(dict.count(s.substr(j,i-j))){
                        dp[i]=true;
                        break;
                }
                //}
            }
        }
        return dp[n];
    }
};
