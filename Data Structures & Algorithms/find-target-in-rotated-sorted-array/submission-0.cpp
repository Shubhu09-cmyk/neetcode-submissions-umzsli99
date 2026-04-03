class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0; 
        int e=nums.size()-1;
        
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                return mid;
            }
            //if mid element not equals to target then search sorted part
            if(nums[s]<=nums[mid])  {//left part sorted apply binary search here
                if(nums[s] <= target && target < nums[mid]){// target find in left
                    e=mid-1; 
                }else{
                    s=mid+1;  //target found in right 
                }
            }

            else{      //ni to right part is sorted apply binary search here
                if(nums[mid]<target && target <= nums[e]){
                    s=mid+1;
                }else{
                    e=mid-1;
                }

            }
        }
        
return -1;
        
    }
};
