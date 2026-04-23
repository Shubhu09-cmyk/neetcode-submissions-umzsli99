class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int xor_all=0;
        for(int i=0;i<n;i++){
             xor_all^=i;
             xor_all^=nums[i];
        }

        return xor_all^n;//including last numbefr
    }
};
