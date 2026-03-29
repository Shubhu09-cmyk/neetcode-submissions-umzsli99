class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int longest=0;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        for (int num : s){
            if(!s.count(num-1)){
               int count=1;
               int x=num;
                while(s.count(x+1)){
                    x++;
                    count++;

                }
                longest=max(longest,count);
            }
            
        }
       return longest;
    }
};
