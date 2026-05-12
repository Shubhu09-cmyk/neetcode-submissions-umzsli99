class Solution {
public:
//TC O(n).  SC O(1)
    vector<int> partitionLabels(string s) {
        vector<int> last_occ(26,-1);
        //getting last occurance of each character
        for(int i=0;i<s.length();i++){
            last_occ[s[i]-'a']=i;
        }
        vector<int> ans;
        int start=0,end=0;
        for(int i=0;i<s.length();i++){
            //expanding the end
            end=max(end,last_occ[s[i]-'a']);
        
        if(i==end){
            ans.push_back(end-start+1);
            start=i+1;
        }}
        return ans;
    }
};
