class Solution {
public:
    void paranthesis(int n,int open,int close, vector<string>& result,string curr){
        if(curr.size()==2*n){
            result.push_back(curr);
            return ;
        }
        if(open<n){
            curr.push_back('(');
            paranthesis(n,open+1,close,result,curr);
            curr.pop_back();
        }
        if(close<open){
            curr.push_back(')');
            paranthesis(n,open,close+1,result,curr);
            curr.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr="";
        paranthesis(n,0,0,result,curr);//open=0; close=0
        return result;
        
    }
};
