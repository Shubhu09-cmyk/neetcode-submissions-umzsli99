class Solution {
    //time O(1) space O(1)
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result=0;
        for(int i=0;i<32;i++){
            result<<=1;  //step1 left shift result by 1. result=result <<1
            if((n&1)==1) result++;//step 2 check if n is odd
            n>>=1;//step3 right shift n by 1
        }
        return result;
    }
};
