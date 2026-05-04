class Solution {

    //time complexity- O(n^2)
    //space complexity- O(1)
private:
    int palindrome(string& s,int left,int right){
         int count=0;
        while(left>=0 && right<s.length() && s[left]==s[right]){
            count++;
            left--;
            right++;
        }
        return count;
    }
public:
   
    int countSubstrings(string s) {
         int count=0;
        for(int i=0;i<s.length();i++){
            //odd length palindrome
            count+=palindrome(s,i,i);   //left and right index are same so points at centre
            //even length palindrome
            count+=palindrome(s,i,i+1); //left and right diff even
        }     
        return count;  
    }
};
