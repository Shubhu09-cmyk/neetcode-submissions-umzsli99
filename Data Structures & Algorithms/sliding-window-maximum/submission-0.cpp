class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> que;
        int n=nums.size();
        vector<int> output(n-k+1);   //6 windows
        int l=0, r=0;
        while(r<n){
            while(!que.empty() && nums[que.back()]<nums[r]){
                que.pop_back();
            }
            que.push_back(r);

            //check out of window
            // remove out-of-window element
            if (!que.empty() && que.front() == r - k) {
                que.pop_front();
            }
            //if results are meeting
            if(r+1>=k){
                output[l]=nums[que.front()];
                l++;
            }
            r++;
        }
     return output;   
    }
};
