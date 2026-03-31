class Solution {
public:
    string minWindow(string s, string t) {

        //edge cese
        if(t.empty()||t.length()>s.length()) return "";
        unordered_map<char,int> countT,windowT;

        //frequency count t
        for(char c:t){
            countT[c]++;
        }
       int have=0; int need=countT.size();
       pair<int,int> res ={-1,-1};
       int res_len=INT_MAX;
       int l=0;

       for(int r=0;r<s.length();r++){
        char c=s[r];
        windowT[c]++;

        
        if(countT.count(c)&& countT[c]==windowT[c]){
            have++;
        }

        //if have ==need then shrinking and should shrink
        while(have==need){
            if(r-l+1<res_len){
            res_len=r-l+1;
            res={l,r};
            }
            
        
        
            //shrinking 
            windowT[s[l]]--;
            if(countT.count(s[l])&& windowT[s[l]]<countT[s[l]]){
                have--;

            }
            l++;
       }
       }
  return res_len==INT_MAX? "" : s.substr(res.first,res_len);
        
    }
};