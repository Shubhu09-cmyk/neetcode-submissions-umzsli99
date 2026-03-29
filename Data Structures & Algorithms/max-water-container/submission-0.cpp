class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int i=0;
        int j=n-1;
        int max_area=0;
        while(i<j){
            
            int area=min(heights[i],heights[j])*(j-i);
            max_area=max(area,max_area);

            if(heights[i]<heights[j]){
                i++;
            }else{
                j--;
            }

            
        }

        return max_area;
    }
};
