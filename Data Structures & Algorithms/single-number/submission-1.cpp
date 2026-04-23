class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //pair cancels out in XOR x^x=0
        int result=0;
        for(int num:nums){
            result^=num;
        }
        return result;
        
    }
};
