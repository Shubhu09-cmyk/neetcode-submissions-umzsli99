class Solution {
    /*. prefix/suffix. it can fail
public:
    int maxProduct(vector<int>& nums) {
    int n=nums.size();
    int leftProduct=1;
    int rightProduct=1;
    int ans=nums[0];
    for(int i=0;i<n;i++){
        leftProduct=(leftProduct==0)?1:leftProduct; //if product=0 then flip it to 1 in case of 0 in array
        rightProduct=(rightProduct==0)?1:rightProduct;

        leftProduct*=nums[i];
        rightProduct*=nums[n-1-i];
        ans=max(ans,max(leftProduct,rightProduct));
    }
    return ans;
    }
*/

//min max tracking.  most interview friendly
/*
we track both the maximum and minimum product ending at each index.
Why both?
Because a negative number can flip signs, turning a small minimum into a large maximum.
*/
public:
    int maxProduct(vector<int>& nums) {
int mini=nums[0];//currMin
int maxi=nums[0];//currMax
int ans=nums[0];
for(int i=1;i<nums.size();i++){
    if(nums[i]<0){
        swap(mini,maxi);  //// If negative, swap because sign flips
    }
    mini=min(nums[i],mini*nums[i]);
    maxi=max(nums[i],maxi*nums[i]);
    ans=max(ans,maxi);
}
return ans;
    }
};
