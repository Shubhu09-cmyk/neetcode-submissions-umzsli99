class Solution {

    //“Expand around center for both odd and even cases”. TC O(n^2). SC O(1)
private:
    void palindrome(string& s,int left,int right,int& start,int& maxLength, int n){
        while(left>=0 && right<n && s[left]==s[right]){
            if(maxLength<right-left+1){
                maxLength=right-left+1;
                start=left;
            }
            left--;
            right++;
        }
    }
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n==0) return "";
        int start=0; int maxLen=1;
        for(int i=0;i<n;i++){
            //odd length
            palindrome(s,i,i,start,maxLen,n);
            //even Length
            palindrome(s,i,i+1,start,maxLen,n);
        }
       return s.substr(start,maxLen); 
    }
};
