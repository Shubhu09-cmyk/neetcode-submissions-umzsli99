class Solution {
public:
bool isPalindrome(string s1){
    string s2=s1;
    reverse(s2.begin(),s2.end());
    return s1==s2;   
}
    void partitioning(string& s,int idx,vector<string>& curr,vector<vector<string>>& result){
        if(s.length()==idx){
            result.push_back(curr);
            return;
        }
        for(int i=idx;i<s.length();i++){
            string part=s.substr(idx,i-idx+1);
            if(isPalindrome(part)){
                curr.push_back(part);
                partitioning(s,i+1,curr,result);
                curr.pop_back();

            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        partitioning(s,0,curr,result);//start index 0 of s
        return result;

    }
};
