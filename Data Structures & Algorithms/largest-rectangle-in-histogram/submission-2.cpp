class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;   //stores indices of bars
        int n=heights.size();
        vector<int> r(n,0);   //to keep index of right nearest smallest elkement
        vector<int> l(n,0);   //to keep index of left nearest smallest elkement
        //find right nearest element index of each element
        int maxArea=0;
        //solved by 0(n)
        
        //nearest  smaller  left element
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i]<=heights[st.top()] ){
                st.pop();
         }
           l[i]=st.empty()?-1:st.top();
           st.push(i) ;
            
        }
        while(!st.empty()){
            st.pop();
        }

        //finding nearest smallest right element
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
            r[i]=st.empty()? n : st.top();
            st.push(i);
        }

        for(int i=0;i<heights.size();i++){
            int currArea= heights[i]*(r[i]-l[i]-1);
            maxArea=max(currArea,maxArea);
        }
        
        return maxArea;
    }
};

/*
If no smaller bar exists on one side, using -1 or n automatically gives the full width of the rectangle that can extend to the edge.
💡 Summary:
l[i] = -1 → no smaller bar left → rectangle can extend to index 0
r[i] = n → no smaller bar right → rectangle can extend to index n-1
Using these makes area calculation formula uniform: heights[i] * (r[i] - l[i] - 1).
*/