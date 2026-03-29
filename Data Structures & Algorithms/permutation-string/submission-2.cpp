class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> mp(26,0);
        for(char c:s1){
            mp[c-'a']++;
        }
        int total_count=s1.size();
        int i=0;
        int j=0;
        while(j<s2.size()){
            if(mp[s2[j]-'a']>0){    //if(mp[s2[j++]-'a'])>0
                total_count--;
            }
                mp[s2[j]-'a']--;
                j++;
            
            if(total_count==0) return true;
            //manage sliding window
            if(j-i==s1.size()){
                if(mp[s2[i]-'a']>=0){
                    total_count++;
                   
                }
                 mp[(s2[i]-'a')]++;
                    
                i++;
            }
        }
      return false;  
    }
};
