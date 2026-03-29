class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int l=0;
        int r=0;
        int max_len=0;
        while(r<s.size()){
            if(mp.count(s[r])){
                l=max(l,mp[s[r]]+1);   //mp[s[r]]>=l
            }
            mp[s[r]]=r;
            max_len=max(max_len,r-l+1);
            r++;
        }
     return max_len;   
    }
};
