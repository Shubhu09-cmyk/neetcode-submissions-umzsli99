class Solution {
public:
    int findMin(vector<int> &nums) {
        int s=0;
        int e=nums.size()-1;

        /*Why NOT while (s <= e) here?
Because this problem is not searching for an element,
it’s narrowing down to the minimum index.
🔥 Key Difference
Problem Type	Loop Condition
Find element	while (s <= e) ✅
Find boundary/min/max	while (s < e) ✅

*/
        while(s<e){
            int mid=s+(e-s)/2;
            if(nums[mid]>nums[e]){
                s=mid+1;
            }
            else {
                e=mid;
            }

        }
        return nums[s];
    }
};
