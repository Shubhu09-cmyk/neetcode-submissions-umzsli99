class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;   //while multiplying long operands, overflow ccan happen so long
        for(auto& c:tokens){
            if(c=="+"){          //" use double quote because string"
                int a=st.top(); st.pop();
                int b=st.top(); st.pop();
                st.push(b+a);
            }
            else if(c=="-"){
                int a=st.top(); st.pop();
                int b=st.top(); st.pop();
                st.push(b-a);
            }
            else if(c=="*"){
                int a=st.top(); st.pop();
                int b=st.top(); st.pop();
                st.push(b*a);
            }
            else if(c=="/"){
                int a=st.top(); st.pop();
                int b=st.top(); st.pop();
                st.push(b/a);
            }
            else{
                st.push(stoi(c));  //convert string to int if no operations are there
            }
        }
    return st.top();
        
    }
};
