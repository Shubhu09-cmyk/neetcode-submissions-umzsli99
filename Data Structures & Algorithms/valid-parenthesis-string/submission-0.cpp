class Solution {
public:
//greedy range approach T O(n) S O(1)
    bool checkValidString(string s) {
        int mini=0,maxi=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                mini++,maxi++;
            }
            if(s[i]==')'){
                mini--,maxi--;
            }
            if(s[i]=='*'){
                mini--;
                maxi++;
            }
            mini=max(mini,0);  //if(min<0) min=0;
            if(maxi<0) return false; //{0,1} right can't be negative
        }
        return mini==0;
    }
};
