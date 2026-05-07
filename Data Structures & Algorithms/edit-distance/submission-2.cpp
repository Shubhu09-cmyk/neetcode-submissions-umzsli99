class Solution {
/*
    //memorization.  
    // Time Complexity = O(n * m). space Complexity = O(n * m)
private:
    int f(int i,int j,string& s1,string& s2,vector<vector<int>>& dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=f(i-1,j-1,s1,s2,dp); //because i,j are indices
        return dp[i][j]=1+min(f(i-1,j,s1,s2,dp),min(f(i,j-1,s1,s2,dp),f(i-1,j-1,s1,s2,dp)));
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,word1,word2,dp);       
    }
    */
/*
//1-based indexing
    private:
    int f(int i,int j,string& s1,string& s2,vector<vector<int>>& dp){
        if(i==0) return j;
        if(j==0) return i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i-1]==s2[j-1]) return dp[i][j]=f(i-1,j-1,s1,s2,dp);  //because i,j are lengths.
        return dp[i][j]=1+min(f(i-1,j,s1,s2,dp),min(f(i,j-1,s1,s2,dp),f(i-1,j-1,s1,s2,dp)));
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(n,m,word1,word2,dp);       
    }
    */

    //remove auxiliary stack space. remove recursion.  give tabulation
public:
    int minDistance(string word1, string word2) {
        string s1=word1;
        string s2=word2;
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        //base case 1. j=0 s2=0
        for(int i=0;i<=n;i++) dp[i][0]=i;
        //base case 2 i=0 s1=0
        for(int j=0;j<=m;j++) dp[0][j]=j;
        //explore all possiblities
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //dp[i][j]=1+min(f(i-1,j,s1,s2,dp),min(f(i,j-1,s1,s2,dp),f(i-1,j-1,s1,s2,dp)));
                if(s1[i-1]==s2[j-1]) {
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};
