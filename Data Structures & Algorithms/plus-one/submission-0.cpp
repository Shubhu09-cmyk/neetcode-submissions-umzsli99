class Solution {
    //space O(1). time O(n)
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int digit=digits.size()-1;digit>=0;digit--){
            if(digits[digit]<9){ //4<9
            digits[digit]++;
            return digits;
            }
            //if digit==9
            digits[digit]=0;
        }
        //if all 9 i.e. {9,9,9}
        digits.insert(digits.begin(),1); //digits.insert(where,value)
        return digits;
    }
};
