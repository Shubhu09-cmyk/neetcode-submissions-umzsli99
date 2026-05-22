//class Solution {
//public:
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
       //Quickselect naturally finds the kth smallest.
       class Solution {
    //most optimal approach is quick select TC O(n) average space O(1)
    //It naturally find k smallest at index 
private:
    int partition(vector<int>& nums,int left,int right){
        int stored_index=left;
        int pivot=nums[right];
        for(int i=left;i<right;i++){
            if(nums[i]<pivot) {
                swap(nums[i],nums[stored_index]);
                stored_index++;
            }
        }
            swap(nums[stored_index],nums[right]);
        
        return stored_index;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left=0;
        int target=nums.size()-k;
        int right=nums.size()-1;
        while(left<=right){
            int pIndex=partition(nums,left,right);
            if(pIndex==target) return nums[pIndex];
            else if(pIndex<target) {
              
                left=pIndex+1;
            }
            else{
                  right=pIndex-1;;
            }
            
        }
      return -1;  
    }
};