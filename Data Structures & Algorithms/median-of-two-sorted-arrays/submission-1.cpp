class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int l=0;
        int r=nums1.size();
        int total=nums1.size()+nums2.size();
        int half=(total+1)/2;
        while(l<=r){
            int cut1=l+(r-l)/2;   
            int cut2=half-cut1;

            int l1=(cut1==0)?INT_MIN:nums1[cut1-1];
            int r1=(cut1==nums1.size())?INT_MAX:nums1[cut1];

            int l2=(cut2==0)?INT_MIN:nums2[cut2-1];
            int r2=(cut2==nums2.size())?INT_MAX:nums2[cut2];

            if(l1<=r2 && l2<=r1){
                if(total%2==0){
                return (max(l1,l2)+min(r1,r2))/2.0; //even.  for float answer
                }
                else{
                    return max(l1,l2);//odd
                }
            }
            else if(l1>r2){
                r=cut1-1;
            }
            else{
                l=cut1+1;
            }


        }
        return 0;
    }
};
