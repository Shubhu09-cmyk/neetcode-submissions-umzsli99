class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char,int> ana;
        if(s.length()!=t.length()) return false;
        for (char ch:s){
            ana[ch]++;
        }
        for (char ch:t){
            if (ana[ch]==0){ return false;}
            ana[ch]--;
        }
        return true;
    }
};
