class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        //sort(piles.begin(),piles.end());//no need to sort
        //int r=piles[piles.size()-1];  use below line instead of two lines
        int r=*max_element(piles.begin(),piles.end());
        int res=r;
        while(l<=r){
           int k=l+(r-l)/2;
            
            int total_hours=0;
            for(auto pile:piles){
            total_hours+=(pile+k-1)/k;//ceil(pile/k) standard trickl for ceiling dividion in integers that we used in program

            }
            if(total_hours<=h){
                res=k;
                r=k-1;
            }
            else{
                l=k+1;
            }

        }
     return res;   
    }
};
