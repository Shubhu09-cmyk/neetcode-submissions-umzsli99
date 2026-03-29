class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int l_max=0;
        int r_max=0;
        int l=0;
        int r=height.size()-1;
        while(l<r){
            l_max=max(l_max,height[l]);
            r_max=max(r_max,height[r]);

            if(l_max<r_max){        //l_max is the deciding factor
                ans+=l_max-height[l];
                l++;
            }
            else{
                ans+=r_max-height[r];//r_max is the deciding factor
                r--;
            }
        }
       return ans;  
    }
};
