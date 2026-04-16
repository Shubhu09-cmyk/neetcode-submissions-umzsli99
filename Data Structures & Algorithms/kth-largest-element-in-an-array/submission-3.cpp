class Solution {
public:
/*
    int findKthLargest(vector<int>& nums, int k) {
        //  method-1 minHeap

        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(int& c:nums){
            minHeap.push(c);
            if(minHeap.size()>k){
                minHeap.pop();         //TC O(nlogk). SC 0(k)
            }
        }
       return minHeap.top(); 
       */
       // method-2 quick select
       int findKthLargest(vector<int>& nums, int k) {
        int target =nums.size()-k;
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
        int pIndex=partition(nums,left,right);
        if(pIndex==target){
            return nums[pIndex];
        }else if(target<pIndex){
            right=pIndex-1;
        }
        else if(target>pIndex){
            left=pIndex+1;
        }
        }
       }



       private:
         int partition(vector<int>& nums, int left,int right){
            int i=left;  //stored value
            int pivot=nums[right];
            for(int j=i;j<right;j++){
                if(nums[j]<=pivot){
                    swap(nums[i],nums[j]);
                    i++;
                }

            }
            swap(nums[i],nums[right]);
            return i;
         
    }
};
