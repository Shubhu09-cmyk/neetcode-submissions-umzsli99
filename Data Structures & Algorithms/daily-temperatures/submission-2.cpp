class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(),0);
        stack<pair<int,int>> st;

        for(int i=0;i<temperatures.size();i++){
           // int t=temperatures[i];
            
            while(!st.empty() && temperatures[i]>st.top().first) //if temperature[i] is greater than stack top element
            {
                int index_top=st.top().second;
                st.pop();
                res[index_top]=i-index_top;    //computes number of days waited
            }
            //if temperature[i] is <= than stack top element then push the element only
            st.push({temperatures[i],i});
        }
       return res; 
    }
};
