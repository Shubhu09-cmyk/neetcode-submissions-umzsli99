class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int longest=0;   //if nums array has 0 element
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        for (int num : s){
            if(!s.count(num-1)){        //if s doews not contains n-1 element then start
               int count=1;
               int x=num;
                while(s.count(num+1)){   //if x+1 element exist
                    num++;
                    count++;

                }
                longest=max(longest,count);
            }
            
        }
       return longest;
    }
};
