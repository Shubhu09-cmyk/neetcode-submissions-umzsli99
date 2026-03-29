class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;

        for (string it:strs){
            string temp=it;
            sort(it.begin(),it.end());
            mp[it].push_back(temp);
        }
        vector<vector<string>> res;
        for (auto it:mp){
            res.push_back(it.second);
        }
        return res;
    }
};
