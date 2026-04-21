class Solution {
public:
vector<string> mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void helper(string& digits, int idx, string& curr, vector<string>& result){
        if(digits.size()==idx){
            result.push_back(curr);
            return;
        }
        string letter=mapping[digits[idx]-'0'];
        for(char c : letter){
            curr.push_back(c);
            helper(digits,idx+1,curr,result);
            curr.pop_back();

        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};  //if(digits.=="") return {};
        vector<string> result ;
        string curr="";
        helper(digits,0,curr,result);// digits[0]
        return result;
        
    }
};
