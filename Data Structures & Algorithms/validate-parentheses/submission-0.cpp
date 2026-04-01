class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char,char> closingToOpen{{']','['},
        {'}','{'},
        {')','('}
        };
        for(char c:s){
            //if c is closing bracket
            if(closingToOpen.count(c)){
                if(!stack.empty() && stack.top()==closingToOpen[c]){
                    stack.pop();
                } else{
                    return false;
                }
            }else{
            //if c is opening 
            stack.push(c);
            }
        }
        return stack.empty();
    }
};
